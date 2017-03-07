#include "domain_base.hpp"
#include <chobo/small_vector.hpp>
#include <ossia/network/domain/detail/apply_domain.hpp>
#include <ossia/network/domain/detail/min_max.hpp>
#include <ossia/network/domain/domain.hpp>

namespace ossia
{
value get_min(const domain& dom)
{
  return ossia::apply(domain_min_visitor{}, dom);
}

value get_max(const domain& dom)
{
  return ossia::apply(domain_max_visitor{}, dom);
}

void set_min(domain& dom, const ossia::value& val)
{
  if(dom && val.valid())
    return eggs::variants::apply(domain_set_min_visitor{}, dom, val.v);
  else if(dom) // Remove the value
    return eggs::variants::apply(domain_set_min_visitor{}, dom);
}

void set_max(domain& dom, const ossia::value& val)
{
  if(dom && val.valid())
    return eggs::variants::apply(domain_set_max_visitor{}, dom, val.v);
  else if(dom)
    return eggs::variants::apply(domain_set_max_visitor{}, dom);
}

void set_values(domain& dom, const std::vector<ossia::value>& val)
{
  if(dom)
    return eggs::variants::apply(domain_value_set_update_visitor{val}, dom);
}

domain make_domain(const ossia::value& min, const ossia::value& max)
{
  if (min.valid() && max.valid())
  {
    return eggs::variants::apply(domain_minmax_creation_visitor{}, min.v, max.v);
  }
  else if(min.valid())
  {
    auto dom = eggs::variants::apply(domain_minmax_creation_visitor{}, min.v, min.v);
    set_max(dom, ossia::value{});
    return dom;
  }
  else if(max.valid())
  {
    auto dom = eggs::variants::apply(domain_minmax_creation_visitor{}, max.v, max.v);
    set_min(dom, ossia::value{});
    return dom;
  }
  return {};
}

ossia::domain make_domain_from_type(ossia::val_type v)
{
  switch(v)
  {
    case ossia::val_type::FLOAT: return ossia::domain_base<float>{};
    case ossia::val_type::INT: return ossia::domain_base<int>{};
    case ossia::val_type::IMPULSE: return ossia::domain_base<impulse>{};
    case ossia::val_type::VEC2F: return ossia::domain_base<vec2f>{};
    case ossia::val_type::VEC3F: return ossia::domain_base<vec3f>{};
    case ossia::val_type::VEC4F: return ossia::domain_base<vec4f>{};
    case ossia::val_type::BOOL: return ossia::domain_base<bool>{};
    case ossia::val_type::CHAR: return ossia::domain_base<char>{};
    case ossia::val_type::TUPLE: return ossia::domain_base<std::vector<ossia::value>>{};
    default:
      return {};
  }
}

domain make_domain(const ossia::value& min, const ossia::value& max, const std::vector<ossia::value>& vals)
{
  if (min.valid() && max.valid())
  {
    auto dom = eggs::variants::apply(domain_minmax_creation_visitor{}, min.v, max.v);
    set_values(dom, vals);
    return dom;
  }
  else if(min.valid())
  {
    auto dom = eggs::variants::apply(domain_minmax_creation_visitor{}, min.v, min.v);
    set_max(dom, ossia::value{});
    set_values(dom, vals);
    return dom;
  }
  else if(max.valid())
  {
    auto dom = eggs::variants::apply(domain_minmax_creation_visitor{}, max.v, max.v);
    set_min(dom, ossia::value{});
    set_values(dom, vals);
    return dom;
  }
  else
  {
    if(vals.size() > 0)
    {
      auto dom = make_domain_from_type(vals[0].getType());
      eggs::variants::apply(domain_value_set_update_visitor{vals}, dom);
      return dom;
    }
  }
  return {};
}

domain make_domain(
    const chobo::small_vector<ossia::value, 2>& val,
    const ossia::value& cur)
{
  if (val.size() == 2 && val[0].valid() && val[1].valid())
  {
    return eggs::variants::apply(domain_minmax_creation_visitor{}, val[0].v, val[1].v);
  }
  else
  {
    return eggs::variants::apply(domain_value_set_creation_visitor{val}, cur.v);
  }
}

bool
operator==(const domain_base<impulse>& lhs, const domain_base<impulse>& rhs)
{
  return true;
}
bool
operator==(const domain_base<int32_t>& lhs, const domain_base<int32_t>& rhs)
{
  return lhs.min == rhs.min && lhs.max == rhs.max && lhs.values == rhs.values;
}
bool
operator==(const domain_base<float>& lhs, const domain_base<float>& rhs)
{
  return lhs.min == rhs.min && lhs.max == rhs.max && lhs.values == rhs.values;
}
bool
operator==(const domain_base<bool>& lhs, const domain_base<bool>& rhs)
{
  return lhs.min == rhs.min && lhs.max == rhs.max && lhs.values == rhs.values;
}
bool
operator==(const domain_base<char>& lhs, const domain_base<char>& rhs)
{
  return lhs.min == rhs.min && lhs.max == rhs.max && lhs.values == rhs.values;
}
bool
operator==(const domain_base<std::vector<ossia::value>>& lhs, const domain_base<std::vector<ossia::value>>& rhs)
{
  return lhs.min == rhs.min && lhs.max == rhs.max && lhs.values == rhs.values;
}
bool
operator==(const domain_base<vec2f>& lhs, const domain_base<vec2f>& rhs)
{
  return lhs.min == rhs.min && lhs.max == rhs.max && lhs.values == rhs.values;
}
bool
operator==(const domain_base<vec3f>& lhs, const domain_base<vec3f>& rhs)
{
  return lhs.min == rhs.min && lhs.max == rhs.max && lhs.values == rhs.values;
}
bool
operator==(const domain_base<vec4f>& lhs, const domain_base<vec4f>& rhs)
{
  return lhs.min == rhs.min && lhs.max == rhs.max && lhs.values == rhs.values;
}
bool
operator==(const domain_base<ossia::value>& lhs, const domain_base<ossia::value>& rhs)
{
  return lhs.min == rhs.min && lhs.max == rhs.max && lhs.values == rhs.values;
}
bool
operator==(const domain_base<std::string>& lhs, const domain_base<std::string>& rhs)
{
  return lhs.values == rhs.values;
}

value apply_domain(const domain& dom, bounding_mode b, const ossia::value& val)
{
  if (bool(dom) && bool(val.v))
  {
    return eggs::variants::apply(apply_domain_visitor{b}, val.v, dom);
  }
  return val;
}

value apply_domain(const domain& dom, bounding_mode b, ossia::value&& val)
{
  if (bool(dom) && bool(val.v))
  {
    return eggs::variants::apply(apply_domain_visitor{b}, ossia::move(val.v), dom);
  }
  return val;
}

domain init_domain(ossia::val_type type)
{
  switch (type)
  {
    case val_type::IMPULSE:
      return domain_base<impulse>{};
    case val_type::INT:
      return domain_base<int32_t>{};
    case val_type::FLOAT:
      return domain_base<float>{};
    case val_type::BOOL:
      return domain_base<bool>{};
    case val_type::CHAR:
      return domain_base<char>{};
    case val_type::STRING:
      return domain_base<std::string>();
    case val_type::TUPLE:
      return domain_base<std::vector<ossia::value>>();
    case val_type::VEC2F:
      return domain_base<vec2f>();
    case val_type::VEC3F:
      return domain_base<vec3f>();
    case val_type::VEC4F:
      return domain_base<vec4f>();
    case val_type::DESTINATION:
    default:
      return domain{};
  }
}
}
