#pragma once
#include <ossia/network/base/address.hpp>
#include <ossia/network/domain/domain.hpp>
#include <ossia/network/midi/detail/channel.hpp>

#define BOOST_LEXICAL_CAST_ASSUME_C_LOCALE
#include <boost/lexical_cast.hpp>
namespace ossia
{
namespace net
{
namespace midi
{
class midi_protocol;
struct address_info
{
  enum class Type : midi_size_t
  {
    NoteOn,    // /12/note/on 64 127 -> C3 at 127 velocity
    NoteOn_N,  // /12/note/on/64 127 -> C3 at 127 velocity
    NoteOff,   // /12/note/off 64 127
    NoteOff_N, // /12/note/off/64 127
    CC,        // /12/CC 64 123
    CC_N,      // /12/CC/64 123,
    PC,        // /12/PC 32
    PC_N       // /12/PC/32 Impulse
  };

  ossia::val_type matchingType()
  {
    switch (type)
    {
      case Type::NoteOn:
      case Type::NoteOff:
      case Type::CC:
        return ossia::val_type::TUPLE;
      case Type::NoteOn_N:
      case Type::NoteOff_N:
      case Type::CC_N:
      case Type::PC:
        return ossia::val_type::INT;
      case Type::PC_N:
        return ossia::val_type::IMPULSE;
    }
    return {};
  }

  std::string address()
  {
    switch (type)
    {
      case Type::NoteOn:
        return "/" + boost::lexical_cast<std::string>(channel) + "/note/on";
      case Type::NoteOff:
        return "/" + boost::lexical_cast<std::string>(channel) + "/note/off";
      case Type::CC:
        return "/" + boost::lexical_cast<std::string>(channel) + "/CC";
      case Type::NoteOn_N:
        return "/" + boost::lexical_cast<std::string>(channel) + "/note/on/"
               + boost::lexical_cast<std::string>(note);
      case Type::NoteOff_N:
        return "/" + boost::lexical_cast<std::string>(channel) + "/note/off/"
               + boost::lexical_cast<std::string>(note);
      case Type::CC_N:
        return "/" + boost::lexical_cast<std::string>(channel) + "/CC/" + boost::lexical_cast<std::string>(note);
      case Type::PC:
        return "/" + boost::lexical_cast<std::string>(channel) + "/PC";
      case Type::PC_N:
        return "/" + boost::lexical_cast<std::string>(channel) + "/PC/" + boost::lexical_cast<std::string>(note);
    }
    return {};
  }

  ossia::value defaultValue(midi_size_t val)
  {
    switch (type)
    {
      case Type::NoteOn:
      case Type::NoteOff:
      case Type::CC:
        return std::vector<ossia::value>{int32_t{val}, int32_t{val}};
      case Type::NoteOn_N:
      case Type::NoteOff_N:
      case Type::CC_N:
      case Type::PC:
        return int32_t{val};
      case Type::PC_N:
        return ossia::impulse{};
    }
    return {};
  }

  ossia::domain defaultDomain()
  {

    return ossia::make_domain(defaultValue(0), defaultValue(127));
  }

  address_info(Type t) : type{t}
  {
  }

  address_info(Type t, midi_size_t n) : type{t}, note{n}
  {
  }

  address_info(midi_size_t chan, Type t, midi_size_t n)
      : channel{chan}, type{t}, note{n}
  {
  }
  midi_size_t channel{};
  Type type{};
  midi_size_t note{};
};

class midi_address final : public ossia::net::address_base
{
  address_info mInfo;
  ossia::net::node_base& mParent;
  midi_protocol& mProtocol;
  ossia::domain mDomain;

  ossia::val_type mType = ossia::val_type::INT;
  value mValue;

public:
  midi_address(address_info info, ossia::net::node_base& parent);

  const address_info& info() const;

  ossia::net::node_base& getNode() const override;

  void pullValue() override;
  address_base& pushValue(const value& val) override;
  address_base& pushValue() override;
  const value& getValue() const;

  value cloneValue() const override;
  address_base& setValue(const value& v) override;

  ossia::val_type getValueType() const override;
  address_base& setValueType(ossia::val_type) override;

  ossia::access_mode getAccessMode() const override;
  address_base& setAccessMode(ossia::access_mode) override;

  const ossia::domain& getDomain() const override;
  address_base& setDomain(const ossia::domain&) override;

  ossia::bounding_mode getBoundingMode() const override;
  address_base& setBoundingMode(ossia::bounding_mode) override;

  ossia::repetition_filter getRepetitionFilter() const override;
  address_base& setRepetitionFilter(ossia::repetition_filter) override;

  void onFirstCallbackAdded() override;
  void onRemovingLastCallback() override;

  void valueCallback(const ossia::value& val);
};
}
}
}
