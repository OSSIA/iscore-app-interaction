#pragma once
#include <ossia/detail/config.hpp>
#include <ossia/network/common/network_logger.hpp>
#include <memory>
#include <future>

#include <ossia_export.h>

namespace ossia
{
class state;

namespace net
{
class address_base;
class node_base;
class device_base;

/**
 * @brief The protocol_base class
 *
 * A protocol is used to implement remote communication.
 *
 * \see local_protocol
 * \see osc_protocol
 * \see minuit_protocol
 * \see oscquery_protocol
 * \see midi_protocol
 */
class OSSIA_EXPORT protocol_base
{
public:
  virtual ~protocol_base();

  /**
   * @brief Pulls a value from the server synchronously.
   * @return True if the value was correctly retrieved.
   */
  virtual bool pull(address_base&) = 0;

  /**
   * @brief Pulls a value from the server asynchronously.
   * @return A future that will be set when the value is received.
   */
  virtual std::future<void> pullAsync(address_base&);

  /**
   * @brief Request an update on a value.
   */
  virtual void request(address_base&);

  /**
   * @brief Send a value to the network.
   * @return
   */
  virtual bool push(const address_base&) = 0;

  /**
   * @brief Notify the network that an address should be listened to.
   *
   * In some protocols (Minuit, OSCQuery), this may send a message to the other client
   * so that it regularly sends values of this address to the local computer.
   *
   * If an address is listened to, when a message is received, address_base::setValue will be called,
   * which will notify the local signals.
   * Else, address_base::setValueQuiet will be called : the value will be updated but the signals
   * won't be notified.
   */
  virtual bool observe(address_base&, bool) = 0;

  /**
   * @brief Begin observation without notifying the other computers.
   */
  virtual bool observe_quietly(address_base&, bool)
  { return false; }

  /**
   * @brief If the protocol supports it, request the namespace corresponding
   * to this node.
   */
  virtual bool update(node_base& node_base) = 0;

  /**
   * @brief It is mandatory to call this function from device implementations, when
   * the protocol is set.
   */
  virtual void setDevice(ossia::net::device_base& dev)
  {
  }

  //! Replace the loggers used
  void setLogger(const network_logger& l)
  { mLogger = l; }
  const network_logger& getLogger() const
  { return mLogger; }

protected:
  network_logger mLogger;
};

}
}
