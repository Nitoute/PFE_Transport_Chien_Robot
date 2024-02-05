// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from unitree_nav_interfaces:srv/SetBodyRPY.idl
// generated code does not contain a copyright notice

#ifndef UNITREE_NAV_INTERFACES__SRV__DETAIL__SET_BODY_RPY__TRAITS_HPP_
#define UNITREE_NAV_INTERFACES__SRV__DETAIL__SET_BODY_RPY__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "unitree_nav_interfaces/srv/detail/set_body_rpy__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace unitree_nav_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const SetBodyRPY_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: roll
  {
    out << "roll: ";
    rosidl_generator_traits::value_to_yaml(msg.roll, out);
    out << ", ";
  }

  // member: pitch
  {
    out << "pitch: ";
    rosidl_generator_traits::value_to_yaml(msg.pitch, out);
    out << ", ";
  }

  // member: yaw
  {
    out << "yaw: ";
    rosidl_generator_traits::value_to_yaml(msg.yaw, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const SetBodyRPY_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: roll
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "roll: ";
    rosidl_generator_traits::value_to_yaml(msg.roll, out);
    out << "\n";
  }

  // member: pitch
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "pitch: ";
    rosidl_generator_traits::value_to_yaml(msg.pitch, out);
    out << "\n";
  }

  // member: yaw
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "yaw: ";
    rosidl_generator_traits::value_to_yaml(msg.yaw, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const SetBodyRPY_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace unitree_nav_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use unitree_nav_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const unitree_nav_interfaces::srv::SetBodyRPY_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  unitree_nav_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use unitree_nav_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const unitree_nav_interfaces::srv::SetBodyRPY_Request & msg)
{
  return unitree_nav_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<unitree_nav_interfaces::srv::SetBodyRPY_Request>()
{
  return "unitree_nav_interfaces::srv::SetBodyRPY_Request";
}

template<>
inline const char * name<unitree_nav_interfaces::srv::SetBodyRPY_Request>()
{
  return "unitree_nav_interfaces/srv/SetBodyRPY_Request";
}

template<>
struct has_fixed_size<unitree_nav_interfaces::srv::SetBodyRPY_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<unitree_nav_interfaces::srv::SetBodyRPY_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<unitree_nav_interfaces::srv::SetBodyRPY_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace unitree_nav_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const SetBodyRPY_Response & msg,
  std::ostream & out)
{
  (void)msg;
  out << "null";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const SetBodyRPY_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  (void)msg;
  (void)indentation;
  out << "null\n";
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const SetBodyRPY_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace unitree_nav_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use unitree_nav_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const unitree_nav_interfaces::srv::SetBodyRPY_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  unitree_nav_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use unitree_nav_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const unitree_nav_interfaces::srv::SetBodyRPY_Response & msg)
{
  return unitree_nav_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<unitree_nav_interfaces::srv::SetBodyRPY_Response>()
{
  return "unitree_nav_interfaces::srv::SetBodyRPY_Response";
}

template<>
inline const char * name<unitree_nav_interfaces::srv::SetBodyRPY_Response>()
{
  return "unitree_nav_interfaces/srv/SetBodyRPY_Response";
}

template<>
struct has_fixed_size<unitree_nav_interfaces::srv::SetBodyRPY_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<unitree_nav_interfaces::srv::SetBodyRPY_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<unitree_nav_interfaces::srv::SetBodyRPY_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<unitree_nav_interfaces::srv::SetBodyRPY>()
{
  return "unitree_nav_interfaces::srv::SetBodyRPY";
}

template<>
inline const char * name<unitree_nav_interfaces::srv::SetBodyRPY>()
{
  return "unitree_nav_interfaces/srv/SetBodyRPY";
}

template<>
struct has_fixed_size<unitree_nav_interfaces::srv::SetBodyRPY>
  : std::integral_constant<
    bool,
    has_fixed_size<unitree_nav_interfaces::srv::SetBodyRPY_Request>::value &&
    has_fixed_size<unitree_nav_interfaces::srv::SetBodyRPY_Response>::value
  >
{
};

template<>
struct has_bounded_size<unitree_nav_interfaces::srv::SetBodyRPY>
  : std::integral_constant<
    bool,
    has_bounded_size<unitree_nav_interfaces::srv::SetBodyRPY_Request>::value &&
    has_bounded_size<unitree_nav_interfaces::srv::SetBodyRPY_Response>::value
  >
{
};

template<>
struct is_service<unitree_nav_interfaces::srv::SetBodyRPY>
  : std::true_type
{
};

template<>
struct is_service_request<unitree_nav_interfaces::srv::SetBodyRPY_Request>
  : std::true_type
{
};

template<>
struct is_service_response<unitree_nav_interfaces::srv::SetBodyRPY_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // UNITREE_NAV_INTERFACES__SRV__DETAIL__SET_BODY_RPY__TRAITS_HPP_
