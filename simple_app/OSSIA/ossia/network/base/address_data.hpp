#pragma once
#include <ossia/network/common/complex_type.hpp>
#include <ossia/network/domain/domain.hpp>
#include <ossia/detail/any_map.hpp>

namespace ossia
{
namespace net
{
/**
 * @brief The data that can be found inside an address
 *
 * Used to create a new address / node.
 * Unlike address_base and its child classes, can be copied, moved, etc.
 */
struct address_data
{
  address_data() = default;
  address_data(const address_data&) = default;
  address_data(address_data&&) = default;
  address_data& operator=(const address_data&) = default;
  address_data& operator=(address_data&&) = default;

  address_data(std::string n):
    node_name{std::move(n)}
  {

  }

  std::string node_name;

  ossia::value value;
  ossia::complex_type type;
  ossia::optional<ossia::domain> domain;
  ossia::optional<ossia::access_mode> access;
  ossia::optional<ossia::bounding_mode> bounding;
  ossia::optional<ossia::repetition_filter> repetition_filter;
  unit_t unit;

  extended_attributes extended;

  operator const ossia::extended_attributes&() const { return extended; }
  operator ossia::extended_attributes&() { return extended; }
};

}
}
