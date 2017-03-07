#pragma once

#include <memory>
#include <string>

#include <ossia/detail/ptr_container.hpp>
#include <ossia/editor/expression/expression.hpp>
#include <ossia/editor/scenario/time_event.hpp>
#include <ossia/editor/scenario/time_value.hpp>
#include <nano_signal_slot.hpp>
#include <ossia_export.h>

namespace ossia
{

class expression_base;
class state;
class time_event;
struct time_value;

/**
 * \brief #time_node is use to describe temporal structure to synchronize each
 * attached #time_event evaluation.
 *
 * \details #time_node is also a #time_event container.
 */
class OSSIA_EXPORT time_node final :
    public std::enable_shared_from_this<time_node>
{
  public:
    using iterator = ptr_container<time_event>::iterator;
    using const_iterator = ptr_container<time_event>::const_iterator;

    time_node();

    ~time_node();

    /*! evaluate all #time_event's to make them to happen or to dispose them
   \return boolean true if the operation succeeded */
    bool trigger();

    /*! get the date
   \details the date is the sum of its previous #time_constraint durations
   \details a #time_node with na previous #time_constraints have a date equals to
   0.
   \return #TimeValue the date */
    time_value getDate() const;

    /*! get the expression of the #time_node */
    const expression& getExpression() const;

    /*! set the expression of the #time_node
   \details setting the expression to ExpressionTrue will defer the evaluation
   on #time_event's expression
   \details setting the expression to ExpressionFalse will mute TimeNode
   execution
   \param expression_ptr
   \return #time_node the time node */
    time_node& setExpression(expression_ptr);

    /*! create and store a #time_event
   \param #Container<#time_event>::const_iterator where to store the #time_event
   \param #time_event::ExecutionCallback to get #time_event's status back
   \param expression_ptr an optional expression to apply to the
   #time_event
   \return std::shared_ptr<#time_event> */
    iterator emplace(
        const_iterator, time_event::ExecutionCallback,
        expression_ptr = expressions::make_expression_true());
    iterator insert(
        const_iterator, std::shared_ptr<time_event>);
    void remove(const std::shared_ptr<time_event>&);

    /*! get the #time_events of the #time_node
   \return #Container<#time_event> */
    ptr_container<time_event>& timeEvents()
    {
      return mTimeEvents;
    }

    /*! get the #time_events of the #time_node
   \return #Container<#time_event> */
    const ptr_container<time_event>& timeEvents() const
    {
      return mTimeEvents;
    }

    // Interface to be used for set-up by other time processes
    /* process all TimeEvents to propagate execution */
    void process(ptr_container<time_event>& statusChangedEvents);

    /* is the TimeNode observing its Expression ? */
    bool isObservingExpression();

    /* enable observation of the Expression */
    void observeExpressionResult(bool);

    //! Resets the internal state. Necessary when restarting an execution.
    void reset();

    /* To be called before deletion, to break the shared_ptr cycle */
    void cleanup();

    /*! Execution callbacks
     *
     * Used to be notified when the #time_node is triggered.
     *
     * \details This is not thread-safe
     */
    callback_container<std::function<void()>> triggered;

    //! Called when the time node starts evaluating
    callback_container<std::function<void()>> enteredEvaluation;

    //! Called if the time node stops evaluating due to a changing duration
    callback_container<std::function<void()>> leftEvaluation;

    //! Boolean : true if the evaluation was finished due to the max bound
    callback_container<std::function<void(bool)>> finishedEvaluation;


  private:
    ossia::expression_ptr mExpression;

    ptr_container<time_event> mTimeEvents;
    ptr_container<time_event> mPendingEvents;


    optional<expressions::expression_callback_iterator> mResultCallbackIndex;

    bool mObserveExpression = false;
    bool mEvaluating = false;

};
}
