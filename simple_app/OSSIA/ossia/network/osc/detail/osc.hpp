#pragma once
#include <ossia/editor/value/value.hpp>
#include <ossia/network/base/address.hpp>
#include <ossia/network/domain/domain.hpp>
#include <ossia/network/generic/generic_address.hpp>
#include <ossia/detail/string_view.hpp>
#include <oscpack/osc/OscOutboundPacketStream.h>
#include <oscpack/osc/OscReceivedElements.h>

// TODO better way would be to use Boost.Spirit :
// see http://stackoverflow.com/questions/23437778/comparing-3-modern-c-ways-to-convert-integral-values-to-strings
#define BOOST_LEXICAL_CAST_ASSUME_C_LOCALE
#include <boost/lexical_cast.hpp>

namespace oscpack
{
inline oscpack::OutboundPacketStream&
operator<<(oscpack::OutboundPacketStream& p, const ossia::value& val);
}

namespace ossia
{
namespace net
{
struct osc_outbound_visitor
{
    oscpack::OutboundPacketStream& p;
    void operator()(ossia::impulse) const
    {
    }
    void operator()(int32_t i) const
    {
      p << int32_t(i);
    }
    void operator()(float f) const
    {
      p << float(f);
    }
    void operator()(bool b) const
    {
      p << int32_t(b);
    }
    void operator()(char c) const
    {
      p << int32_t(c);
    }
    void operator()(const std::string& str) const
    {
      p << (ossia::string_view)str;
    }
    void operator()(ossia::vec2f vec) const
    {
      p << vec[0] << vec[1];
    }
    void operator()(ossia::vec3f vec) const
    {
      p << vec[0] << vec[1] << vec[2];
    }
    void operator()(ossia::vec4f vec) const
    {
      p << vec[0] << vec[1] << vec[2] << vec[3];
    }
    void operator()(const ossia::Destination& d) const
    {
    }
    void operator()(const std::vector<ossia::value>& t) const
    {
      for (const auto& val : t)
      {
        p << val;
      }
    }

    void operator()() const
    {
    }
};

struct osc_utilities
{
  static float get_float(oscpack::ReceivedMessageArgumentIterator it, float f)
  {
      try {
        switch (it->TypeTag())
        {
          case oscpack::INT32_TYPE_TAG:
            return it->AsInt32Unchecked();
          case oscpack::INT64_TYPE_TAG:
            return it->AsInt64Unchecked();
          case oscpack::FLOAT_TYPE_TAG:
            return it->AsFloatUnchecked();
          case oscpack::DOUBLE_TYPE_TAG:
            return it->AsDoubleUnchecked();
          case oscpack::CHAR_TYPE_TAG:
            return it->AsCharUnchecked();
          case oscpack::TRUE_TYPE_TAG:
            return 1.f;
          case oscpack::FALSE_TYPE_TAG:
            return 0.f;
          case oscpack::STRING_TYPE_TAG:
            return boost::lexical_cast<float>(it->AsStringUnchecked());
          case oscpack::SYMBOL_TYPE_TAG:
            return boost::lexical_cast<float>(it->AsSymbolUnchecked());
          default:
            return f;
        }
      } catch(const boost::bad_lexical_cast &) {
        return f;
      }
  }

  static int get_int(oscpack::ReceivedMessageArgumentIterator it, int i)
  {
    try {
      switch (it->TypeTag())
      {
        case oscpack::INT32_TYPE_TAG:
          return it->AsInt32Unchecked();
        case oscpack::INT64_TYPE_TAG:
          return int32_t(it->AsInt64Unchecked());
        case oscpack::FLOAT_TYPE_TAG:
          return int32_t(it->AsFloatUnchecked());
        case oscpack::DOUBLE_TYPE_TAG:
          return int32_t(it->AsDoubleUnchecked());
        case oscpack::CHAR_TYPE_TAG:
          return int32_t(it->AsCharUnchecked());
        case oscpack::TRUE_TYPE_TAG:
          return 1;
        case oscpack::FALSE_TYPE_TAG:
          return 0;
        case oscpack::STRING_TYPE_TAG:
          return boost::lexical_cast<int>(it->AsStringUnchecked());
        case oscpack::SYMBOL_TYPE_TAG:
          return boost::lexical_cast<int>(it->AsSymbolUnchecked());
        default:
          return i;
      }
    } catch(const boost::bad_lexical_cast &) {
      return i;
    }
  }

  static bool get_bool(oscpack::ReceivedMessageArgumentIterator it, bool b)
  {
    try {
      switch (it->TypeTag())
      {
        case oscpack::INT32_TYPE_TAG:
          return it->AsInt32Unchecked();
        case oscpack::INT64_TYPE_TAG:
          return it->AsInt64Unchecked();
        case oscpack::FLOAT_TYPE_TAG:
          return it->AsFloatUnchecked();
        case oscpack::DOUBLE_TYPE_TAG:
          return it->AsDoubleUnchecked();
        case oscpack::CHAR_TYPE_TAG:
          return it->AsCharUnchecked();
        case oscpack::TRUE_TYPE_TAG:
          return true;
        case oscpack::FALSE_TYPE_TAG:
          return false;
        case oscpack::STRING_TYPE_TAG:
          return boost::lexical_cast<bool>(it->AsStringUnchecked());
        case oscpack::SYMBOL_TYPE_TAG:
          return boost::lexical_cast<bool>(it->AsSymbolUnchecked());
        default:
          return b;
      }
    } catch(const boost::bad_lexical_cast &) {
      return b;
    }
  }

  static char get_char(oscpack::ReceivedMessageArgumentIterator it, char c)
  {
    switch (it->TypeTag())
    {
      case oscpack::INT32_TYPE_TAG:
        return char{char(it->AsInt32Unchecked())};
      case oscpack::INT64_TYPE_TAG:
        return char{char(it->AsInt64Unchecked())};
      case oscpack::FLOAT_TYPE_TAG:
        return char{char(it->AsFloatUnchecked())};
      case oscpack::DOUBLE_TYPE_TAG:
        return char{char(it->AsDoubleUnchecked())};
      case oscpack::CHAR_TYPE_TAG:
        return char{char(it->AsCharUnchecked())};
      case oscpack::TRUE_TYPE_TAG:
        return char{'T'};
      case oscpack::FALSE_TYPE_TAG:
        return char{'F'};
      case oscpack::STRING_TYPE_TAG:
        return char{it->AsStringUnchecked()[0]};
      case oscpack::SYMBOL_TYPE_TAG:
        return char{it->AsSymbolUnchecked()[0]};
      default:
        return c;
    }
  }

  static ossia::value create_value(oscpack::ReceivedMessageArgumentIterator it)
  {
    switch (it->TypeTag())
    {
      case oscpack::INT32_TYPE_TAG:
        return int32_t{it->AsInt32Unchecked()};
      case oscpack::INT64_TYPE_TAG:
        return int32_t{(int)it->AsInt64Unchecked()};
      case oscpack::FLOAT_TYPE_TAG:
        return float{it->AsFloatUnchecked()};
      case oscpack::DOUBLE_TYPE_TAG:
        return float{(float)it->AsDoubleUnchecked()};
      case oscpack::CHAR_TYPE_TAG:
        return char{it->AsCharUnchecked()};
      case oscpack::TRUE_TYPE_TAG:
        return bool{true};
      case oscpack::FALSE_TYPE_TAG:
        return bool{false};
      case oscpack::STRING_TYPE_TAG:
        return std::string{it->AsStringUnchecked()};
      case oscpack::SYMBOL_TYPE_TAG:
        return std::string{it->AsSymbolUnchecked()};
      default:
        return ossia::impulse{};
    }
  }

  static std::vector<ossia::value> create_tuple(
      oscpack::ReceivedMessageArgumentIterator cur_it, int numArguments)
  {
    std::vector<ossia::value> t;
    for(int i = 0; i < numArguments; ++i)
    {
      t.push_back(osc_utilities::create_value(cur_it));
      ++cur_it;
    }
    return t;
  }

};

struct osc_inbound_visitor
{
    osc_inbound_visitor(
        oscpack::ReceivedMessageArgumentIterator cur,
        oscpack::ReceivedMessageArgumentIterator beg,
        oscpack::ReceivedMessageArgumentIterator end,
        int n = 1): cur_it{cur}, beg_it{beg}, end_it{end}, numArguments{n} {}

    oscpack::ReceivedMessageArgumentIterator cur_it;
    oscpack::ReceivedMessageArgumentIterator beg_it;
    oscpack::ReceivedMessageArgumentIterator end_it;
    int numArguments = 1;

    ossia::value operator()(ossia::impulse imp) const
    {
      return imp;
    }

    ossia::value operator()(int32_t i) const
    {
      return osc_utilities::get_int(cur_it, i);
    }

    ossia::value operator()(float f) const
    {
      return osc_utilities::get_float(cur_it, f);
    }

    ossia::value operator()(bool b) const
    {
      return osc_utilities::get_bool(cur_it, b);
    }

    ossia::value operator()(char c) const
    {
      return osc_utilities::get_char(cur_it, c);
    }

    ossia::value operator()(const std::string& str) const
    {
      switch (cur_it->TypeTag())
      {
        case oscpack::INT32_TYPE_TAG:
          return std::string{boost::lexical_cast<std::string>(cur_it->AsInt32Unchecked())};
        case oscpack::INT64_TYPE_TAG:
          return std::string{boost::lexical_cast<std::string>(cur_it->AsInt64Unchecked())};
        case oscpack::FLOAT_TYPE_TAG:
          return std::string{boost::lexical_cast<std::string>(cur_it->AsFloatUnchecked())};
        case oscpack::DOUBLE_TYPE_TAG:
          return std::string{boost::lexical_cast<std::string>(cur_it->AsDoubleUnchecked())};
        case oscpack::CHAR_TYPE_TAG:
          return std::string{boost::lexical_cast<std::string>(cur_it->AsCharUnchecked())};
        case oscpack::TRUE_TYPE_TAG:
          return std::string{"true"};
        case oscpack::FALSE_TYPE_TAG:
          return std::string{"false"};
        case oscpack::STRING_TYPE_TAG:
          return std::string{cur_it->AsStringUnchecked()};
        case oscpack::SYMBOL_TYPE_TAG:
          return std::string{cur_it->AsSymbolUnchecked()};
        default:
          return str;
      }
    }


    template <std::size_t N>
    ossia::value operator()(std::array<float, N> vec) const
    {
      if (numArguments == N)
      {
        std::array<float, N> ret;
        std::size_t i = 0;
        auto vec_it = beg_it;
        auto vec_end = end_it;
        for (; vec_it != vec_end; ++vec_it)
        {
          ret[i] = osc_utilities::get_float(vec_it, vec[i]);
          i++;
        }
        return ret;
      }
      else
      {
        return vec;
      }
    }

    ossia::value operator()(const ossia::Destination& d) const
    {
      return d;
    }


    ossia::value operator()(const std::vector<ossia::value>&)
    {
      /* This code preserves type info, this is not what we want.
    int n = t.size();
    if (numArguments == n)
    {
      for (int i = 0; i < n; i++)
      {
        auto res = eggs::variants::apply(*this, t[i].v);
        t[i] = std::move(res);
        ++cur_it;
      }
    }
    */
      return osc_utilities::create_tuple(cur_it, numArguments);
    }

    ossia::value operator()() const
    {
      return {};
    }
};

struct osc_inbound_numeric_visitor
{
    osc_inbound_numeric_visitor(oscpack::ReceivedMessageArgumentIterator cur):
      cur_it{cur}
    {

    }

    oscpack::ReceivedMessageArgumentIterator cur_it;
    ossia::value operator()(ossia::impulse imp) const
    {
      return imp;
    }

    ossia::value operator()(int32_t i) const
    {
      return osc_utilities::get_int(cur_it, i);
    }

    ossia::value operator()(float f) const
    {
      return osc_utilities::get_float(cur_it, f);
    }

    ossia::value operator()(bool b) const
    {
      return osc_utilities::get_bool(cur_it, b);
    }

    ossia::value operator()(char c) const
    {
      return osc_utilities::get_char(cur_it, c);
    }

    ossia::value operator()(const std::string& str) const
    {
      return str;
    }

    template <std::size_t N>
    ossia::value operator()(std::array<float, N> vec) const
    {
      return osc_utilities::get_float(cur_it, vec[0]);
    }

    ossia::value operator()(const ossia::Destination& d) const
    {
      return d;
    }

    ossia::value operator()(const std::vector<ossia::value>& t)
    {
      return osc_utilities::get_float(cur_it, !t.empty() ? ossia::convert<float>(t[0]) : 0.f);
    }

    ossia::value operator()() const
    {
      return {};
    }
};



struct osc_inbound_impulse_visitor
{
  template<typename T>
  ossia::value operator()(T&& t) const
  {
    return t;
  }

  ossia::value operator()() const
  {
    return {};
  }
};

template<typename Value_T>
inline ossia::value filter_value(
    const ossia::domain& dom, Value_T&& base_val,
    ossia::bounding_mode mode)
{
  if (dom)
  {
    auto res = ossia::apply_domain(dom, mode, std::forward<Value_T>(base_val));
    if (res.valid())
      return res;
    else
      return {};
  }
  else
  {
    return std::forward<Value_T>(base_val);
  }
}

inline ossia::value filter_value(const ossia::net::address_base& addr)
{
  auto val = addr.cloneValue();
  if (addr.filterRepetition(val))
    return {};

  return filter_value(
        addr.getDomain(), std::move(val), addr.getBoundingMode());
}

inline ossia::value to_value(
    const ossia::value& current,
    oscpack::ReceivedMessageArgumentIterator beg_it,
    oscpack::ReceivedMessageArgumentIterator end_it, int N)
{
  if(beg_it != end_it)
    return current.apply(osc_inbound_visitor{beg_it, beg_it, end_it, N});
  else
    return current.apply(osc_inbound_impulse_visitor{});
}

// Used for domains :
inline ossia::value to_numeric_value(
    const ossia::value& current,
    oscpack::ReceivedMessageArgumentIterator beg_it,
    oscpack::ReceivedMessageArgumentIterator end_it)
{
  if(beg_it != end_it)
    return current.apply(osc_inbound_numeric_visitor{beg_it});
  else
    return current.apply(osc_inbound_impulse_visitor{});
}


inline bool update_value(
    ossia::net::address_base& addr,
    oscpack::ReceivedMessageArgumentIterator beg_it,
    oscpack::ReceivedMessageArgumentIterator end_it, int N)
{
  auto res = filter_value(
               addr.getDomain(),
               ossia::net::to_value(addr.cloneValue(), beg_it, end_it, N),
               addr.getBoundingMode());

  if (res.valid())
  {
    addr.setValue(std::move(res));
    return true;
  }
  return false;
}

inline bool update_value(
    ossia::net::address_base& addr, const oscpack::ReceivedMessage& mess)
{
  return update_value(
        addr, mess.ArgumentsBegin(), mess.ArgumentsEnd(), mess.ArgumentCount());
}

inline bool update_value_quiet(
    ossia::net::address_base& addr,
    oscpack::ReceivedMessageArgumentIterator beg_it,
    oscpack::ReceivedMessageArgumentIterator end_it, int N)
{
  auto res = filter_value(
               addr.getDomain(),
               ossia::net::to_value(addr.cloneValue(), beg_it, end_it, N),
               addr.getBoundingMode());

  if (res.valid())
  {
    addr.setValueQuiet(std::move(res));
    return true;
  }
  return false;
}

inline bool update_value_quiet(
    ossia::net::address_base& addr,
    const oscpack::ReceivedMessage& mess)
{
  return update_value_quiet(
        addr, mess.ArgumentsBegin(), mess.ArgumentsEnd(), mess.ArgumentCount());
}

struct osc_write_domain_visitor
{
  ossia::net::osc_outbound_visitor vis;
  template<typename T>
  void operator()(const T& dom)
  {
    if(dom.min && dom.max)
    {
      vis(*dom.min);
      vis(*dom.max);
    }
  }

  template<std::size_t N>
  void operator()(const domain_base<std::array<float, N>>& dom)
  {
    if(dom.min && dom.max)
    {
      vis((*dom.min)[0]);
      vis((*dom.max)[0]);
    }
  }

  void operator()(const domain_base<std::vector<ossia::value>>& dom)
  {
    if(dom.min && dom.max)
    {
      const std::vector<ossia::value>& min = *dom.min;
      const std::vector<ossia::value>& max = *dom.max;
      if(!min.empty() && !max.empty())
      {
        vis(ossia::convert<float>(min[0]));
        vis(ossia::convert<float>(max[0]));
      }
    }
  }

  void operator()(const domain_base<ossia::value>& dom)
  {
    if(dom.min && dom.max)
    {
      vis(ossia::convert<float>(*dom.min));
      vis(ossia::convert<float>(*dom.max));
    }
  }

  void operator()(const domain_base<ossia::impulse>& dom)
  {
  }

  void operator()(const domain_base<std::string>& dom)
  {
  }

  void operator()()
  {
  }
};

}
}

namespace oscpack
{
inline oscpack::OutboundPacketStream&
operator<<(oscpack::OutboundPacketStream& p, const ossia::value& val)
{
  val.apply(ossia::net::osc_outbound_visitor{p});
  return p;
}


inline oscpack::OutboundPacketStream&
operator<<(oscpack::OutboundPacketStream& p, const ossia::domain& dom)
{
  ossia::apply(ossia::net::osc_write_domain_visitor{p}, dom);

  return p;
}
}
