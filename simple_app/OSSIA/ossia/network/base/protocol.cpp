#include <ossia/network/base/protocol.hpp>
#include <ossia/network/common/network_logger.hpp>
namespace ossia
{
namespace net
{
protocol_base::~protocol_base() = default;

network_logger::network_logger() = default;
network_logger::~network_logger() = default;

void protocol_base::request(address_base&)
{
}

std::future<void> protocol_base::pullAsync(address_base&)
{
  return {};
}

}
}
