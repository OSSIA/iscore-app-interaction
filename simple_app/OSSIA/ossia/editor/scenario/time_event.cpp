#include <ossia/editor/scenario/time_event.hpp>
#include <ossia/editor/scenario/time_constraint.hpp>
#include <ossia/editor/expression/expression.hpp>

namespace ossia
{
time_event::time_event(
    time_event::ExecutionCallback callback,
    time_node& aTimeNode,
    expression_ptr anExpression)
    : mCallback(callback)
    , mTimeNode(aTimeNode)
    , mStatus(time_event::Status::NONE)
    , mExpression(std::move(anExpression))
{
}

time_event::~time_event() = default;

void time_event::setCallback(time_event::ExecutionCallback callback)
{
  mCallback = callback;
}

void time_event::happen()
{
  if (mStatus != time_event::Status::PENDING)
  {
    throw execution_error("time_event::happen: "
                          "only PENDING event can happens");
    return;
  }

  mStatus = time_event::Status::HAPPENED;

  // stop previous TimeConstraints
  for (auto& timeConstraint : previousTimeConstraints())
  {
    timeConstraint->stop();
  }

  // setup next TimeConstraints
  for (auto& timeConstraint : nextTimeConstraints())
  {
    timeConstraint->start();
  }

  if (mCallback)
    (mCallback)(mStatus);
}

void time_event::dispose()
{
  if (mStatus == time_event::Status::HAPPENED)
  {
    throw execution_error("time_event::dispose: "
                          "HAPPENED event cannot be disposed");
    return;
  }

  mStatus = time_event::Status::DISPOSED;

  // stop previous TimeConstraints
  for (auto& timeConstraint : previousTimeConstraints())
  {
    timeConstraint->stop();
  }

  // dispose next TimeConstraints end event if everything is disposed before
  for (auto& nextTimeConstraint : nextTimeConstraints())
  {
    bool dispose = true;

    for (auto& previousTimeConstraint : nextTimeConstraint->getEndEvent().previousTimeConstraints())
    {
      if (previousTimeConstraint->getStartEvent().getStatus()
          != time_event::Status::DISPOSED)
      {
        dispose = false;
        break;
      }
    }

    if (dispose)
      nextTimeConstraint->getEndEvent().dispose();
  }

  if (mCallback)
    (mCallback)(mStatus);
}

void time_event::addState(state_element&& state)
{
  mState.add(std::move(state));
}

void time_event::removeState(const state_element& state)
{
  mState.remove(state);
}

time_node& time_event::getTimeNode() const
{
  return mTimeNode;
}

const state& time_event::getState() const
{
  return mState;
}

const expression& time_event::getExpression() const
{
  return *mExpression;
}

time_event& time_event::setExpression(expression_ptr exp)
{
  assert(exp);

  mExpression = std::move(exp);

  return *this;
}

time_event::Status time_event::getStatus() const
{
  return mStatus;
}

time_event::OffsetBehavior time_event::getOffsetBehavior() const
{
  return mOffsetBehavior;
}

time_event& time_event::setOffsetBehavior(OffsetBehavior b)
{
  mOffsetBehavior = b;
  return *this;
}

void time_event::setStatus(Status status)
{
  mStatus = status;
  if (mCallback)
      (mCallback)(mStatus);
}

void time_event::reset()
{
    setStatus(Status::NONE);
}

void time_event::cleanup()
{
  m_previousTimeConstraints.clear();
  m_nextTimeConstraints.clear();
}
}
