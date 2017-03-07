#pragma once
#include "ext.h"
#include "ext_obex.h"
#undef error
#undef post

#include <ossia/ossia.hpp>
#include <ossia/context.hpp>
#include <ossia/network/common/websocket_log_sink.hpp>

namespace ossia
{
namespace max
{

// Return a singleton local device that can be used if the user has not made any device.
class singleton
{
public:
  static singleton& instance();

  static ossia::net::device_base& device_instance();

  t_class* ossia_parameter_class{};
  t_class* ossia_logger_class{};

  std::shared_ptr<ossia::websocket_threaded_connection> get_connection(std::string ip);
  void collect_garbage();

private:
  singleton();

  ossia::context ctx;
  ossia::net::local_protocol* m_localProtocol{};
  ossia::net::generic_device m_device;
  string_map<std::shared_ptr<ossia::websocket_threaded_connection>> m_connections;
};

}
}
