#include <ossia/editor/scenario/time_node.hpp>
#include <ossia/editor/scenario/time_constraint.hpp>
namespace ossia
{

time_node::time_node()
    : mExpression(expressions::make_expression_true())
{
}

time_node::~time_node() = default;

bool time_node::trigger()
{
  // if all TimeEvents are not PENDING
  if (mPendingEvents.size() != timeEvents().size())
  {
    // stop expression observation because the TimeNode is not ready to be
    // processed
    observeExpressionResult(false);

    // the triggering failed
    return false;
  }

  // now TimeEvents will happen or be disposed
  for (auto& timeEvent : mPendingEvents)
  {
    auto& ev = *timeEvent;
    auto& expr = ev.getExpression();
    // update any Destination value into the expression
    expressions::update(expr);

    if (expressions::evaluate(expr))
      ev.happen();
    else
      ev.dispose();
  }

  // stop expression observation now the TimeNode has been processed
  observeExpressionResult(false);

  // notify observers
  triggered.send();

  // the triggering succeded
  return true;
}

time_value time_node::getDate() const
{
  // compute the date from each first previous time constraint
  // ignoring zero duration time constraint
  if (!timeEvents().empty())
  {
    for (auto& timeEvent : timeEvents())
    {
      if (!timeEvent->previousTimeConstraints().empty())
      {
        if (timeEvent->previousTimeConstraints()[0]->getDurationNominal()
            > Zero)
          return timeEvent->previousTimeConstraints()[0]->getDurationNominal()
                 + timeEvent->previousTimeConstraints()[0]
                       ->getStartEvent()
                       .getTimeNode()
                       .getDate();
      }
    }
  }

  return Zero;
}

const expression& time_node::getExpression() const
{
  return *mExpression;
}

time_node& time_node::setExpression(expression_ptr exp)
{
  assert(exp);
  mExpression = std::move(exp);
  return *this;
}

time_node::iterator time_node::insert(
    time_node::const_iterator pos,
    std::shared_ptr<time_event> ev)
{
  return mTimeEvents.insert(pos, std::move(ev));
}

void time_node::remove(const std::shared_ptr<time_event>& e)
{
  remove_one(mPendingEvents, e);
  remove_one(mTimeEvents, e);
}

time_node::iterator time_node::emplace(
    const_iterator pos, time_event::ExecutionCallback callback,
    ossia::expression_ptr exp)
{
  return insert(
        pos,
        std::make_shared<time_event>(callback, *this, std::move(exp)));
}

void time_node::process(ptr_container<time_event>& statusChangedEvents)
{
  // prepare to remember which event changed its status to PENDING
  // because it is needed in time_node::trigger
  mPendingEvents.clear();

  bool maximalDurationReached = false;

  for (auto& timeEvent : timeEvents())
  {
    switch (timeEvent->getStatus())
    {
      // check if NONE TimeEvent is ready to become PENDING
      case time_event::Status::NONE:
      {
        bool minimalDurationReached = true;

        for (auto& timeConstraint : timeEvent->previousTimeConstraints())
        {
          // previous TimeConstraints with a DISPOSED start event are ignored
          if (timeConstraint->getStartEvent().getStatus()
              == time_event::Status::DISPOSED)
            continue;

          // previous TimeConstraint with a none HAPPENED start event
          // can't have reached its minimal duration
          if (timeConstraint->getStartEvent().getStatus()
              != time_event::Status::HAPPENED)
          {
            minimalDurationReached = false;
            break;
          }

          // previous TimeConstraint which doesn't reached its minimal duration
          // force to quit
          if (timeConstraint->getDate() < timeConstraint->getDurationMin())
          {
            minimalDurationReached = false;
            break;
          }
        }

        // access to PENDING status once all previous TimeConstraints allow it
        if (minimalDurationReached)
          timeEvent->setStatus(time_event::Status::PENDING);
        else
          break;
      }

      // PENDING TimeEvent is ready for evaluation
      case time_event::Status::PENDING:
      {
        mPendingEvents.push_back(timeEvent);

        for (auto& timeConstraint : timeEvent->previousTimeConstraints())
        {
          if (timeConstraint->getDate() >= timeConstraint->getDurationMax())
          {
            maximalDurationReached = true;
          }
        }

        break;
      }

      // HAPPENED TimeEvent propagates recursively the execution to the end of
      // each next TimeConstraints
      case time_event::Status::HAPPENED:
      {
        for (auto& timeConstraint : timeEvent->nextTimeConstraints())
        {
          timeConstraint
              ->getEndEvent()
              .getTimeNode()
              .process(statusChangedEvents);
        }

        break;
      }

      // DISPOSED TimeEvent stops the propagation of the execution
      case time_event::Status::DISPOSED:
      {
        break;
      }
    }
  }

  // if all TimeEvents are not PENDING
  if (mPendingEvents.size() != timeEvents().size())
  {
    if(mEvaluating)
    {
      mEvaluating = false;
      leftEvaluation.send();
    }

    return;
  }

  if(!mEvaluating)
  {
    mEvaluating = true;
    enteredEvaluation.send();
  }

  // false expression mute TimeNode triggering
  if (*mExpression == expressions::expression_false())
    return;

  //! \todo force triggering if at leat one TimeEvent has
  // at least one TimeConstraint over its maximal duration

  // update the expression one time
  // then observe and evaluate TimeNode's expression before to trig
  // only if no maximal duration have been reached
  if (*mExpression != expressions::expression_true() && !maximalDurationReached)
  {
    if (!isObservingExpression())
      expressions::update(*mExpression);

    observeExpressionResult(true);

    if (!expressions::evaluate(*mExpression))
      return;
  }

  // trigger the time node
  if (trigger())
  {
    // former PENDING TimeEvents are now HAPPENED or DISPOSED
    statusChangedEvents.insert(
          statusChangedEvents.end(),
          mPendingEvents.begin(),
          mPendingEvents.end());

    mEvaluating = false;
    finishedEvaluation.send(maximalDurationReached);
  }
}

bool time_node::isObservingExpression()
{
  return mObserveExpression;
}

void time_node::observeExpressionResult(bool observe)
{
  if (!mExpression || *mExpression == expressions::expression_true()
      || *mExpression == expressions::expression_false())
    return;

  if (observe != mObserveExpression)
  {
    bool wasObserving = mObserveExpression;
    mObserveExpression = observe;

    if (mObserveExpression)
    {
      // pull value

      // start expression observation; dummy callback used.
      // Do not remove it : else the expressions will stop listening.
      mResultCallbackIndex = expressions::add_callback(*mExpression, [] (bool) { });
    }
    else
    {
      // stop expression observation
      if (wasObserving && mResultCallbackIndex)
      {
        expressions::remove_callback(*mExpression, *mResultCallbackIndex);
        mResultCallbackIndex = ossia::none;
      }
    }
  }
}

void time_node::reset()
{
    for(auto& timeEvent : mTimeEvents)
    {
        timeEvent->reset();
    }

    mPendingEvents.clear();
}

void time_node::cleanup()
{
  for(auto& timeevent : mTimeEvents)
    timeevent->cleanup();

  mPendingEvents.clear();
  mTimeEvents.clear();
}

}
