// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from unitree_nav_interfaces:srv/NavToPose.idl
// generated code does not contain a copyright notice

#ifndef UNITREE_NAV_INTERFACES__SRV__DETAIL__NAV_TO_POSE__TRAITS_HPP_
#define UNITREE_NAV_INTERFACES__SRV__DETAIL__NAV_TO_POSE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "unitree_nav_interfaces/srv/detail/nav_to_pose__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace unitree_nav_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const NavToPose_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: x
  {
    out << "x: ";
    rosidl_generator_traits::value_to_yaml(msg.x, out);
    out << ", ";
  }

  // member: y
  {
    out << "y: ";
    rosidl_generator_traits::value_to_yaml(msg.y, out);
    out << ", ";
  }

  // member: theta
  {
    out << "theta: ";
    rosidl_generator_traits::value_to_yaml(msg.theta, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const NavToPose_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "x: ";
    rosidl_generator_traits::value_to_yaml(msg.x, out);
    out << "\n";
  }

  // member: y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "y: ";
    rosidl_generator_traits::value_to_yaml(msg.y, out);
    out << "\n";
  }

  // member: theta
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "theta: ";
    rosidl_generator_traits::value_to_yaml(msg.theta, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const NavToPose_Request & msg, bool use_flow_style = false)
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
  const unitree_nav_interfaces::srv::NavToPose_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  unitree_nav_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use unitree_nav_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const unitree_nav_interfaces::srv::NavToPose_Request & msg)
{
  return unitree_nav_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<unitree_nav_interfaces::srv::NavToPose_Request>()
{
  return "unitree_nav_interfaces::srv::NavToPose_Request";
}

template<>
inline const char * name<unitree_nav_interfaces::srv::NavToPose_Request>()
{
  return "unitree_nav_interfaces/srv/NavToPose_Request";
}

template<>
struct has_fixed_size<unitree_nav_interfaces::srv::NavToPose_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<unitree_nav_interfaces::srv::NavToPose_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<unitree_nav_interfaces::srv::NavToPose_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace unitree_nav_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const NavToPose_Response & msg,
  std::ostream & out)
{
  (void)msg;
  out << "null";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const NavToPose_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  (void)msg;
  (void)indentation;
  out << "null\n";
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const NavToPose_Response & msg, bool use_flow_style = false)
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
  const unitree_nav_interfaces::srv::NavToPose_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  unitree_nav_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use unitree_nav_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const unitree_nav_interfaces::srv::NavToPose_Response & msg)
{
  return unitree_nav_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<unitree_nav_interfaces::srv::NavToPose_Response>()
{
  return "unitree_nav_interfaces::srv::NavToPose_Response";
}

template<>
inline const char * name<unitree_nav_interfaces::srv::NavToPose_Response>()
{
  return "unitree_nav_interfaces/srv/NavToPose_Response";
}

template<>
struct has_fixed_size<unitree_nav_interfaces::srv::NavToPose_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<unitree_nav_interfaces::srv::NavToPose_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<unitree_nav_interfaces::srv::NavToPose_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<unitree_nav_interfaces::srv::NavToPose>()
{
  return "unitree_nav_interfaces::srv::NavToPose";
}

template<>
inline const char * name<unitree_nav_interfaces::srv::NavToPose>()
{
  return "unitree_nav_interfaces/srv/NavToPose";
}

template<>
struct has_fixed_size<unitree_nav_interfaces::srv::NavToPose>
  : std::integral_constant<
    bool,
    has_fixed_size<unitree_nav_interfaces::srv::NavToPose_Request>::value &&
    has_fixed_size<unitree_nav_interfaces::srv::NavToPose_Response>::value
  >
{
};

template<>
struct has_bounded_size<unitree_nav_interfaces::srv::NavToPose>
  : std::integral_constant<
    bool,
    has_bounded_size<unitree_nav_interfaces::srv::NavToPose_Request>::value &&
    has_bounded_size<unitree_nav_interfaces::srv::NavToPose_Response>::value
  >
{
};

template<>
struct is_service<unitree_nav_interfaces::srv::NavToPose>
  : std::true_type
{
};

template<>
struct is_service_request<unitree_nav_interfaces::srv::NavToPose_Request>
  : std::true_type
{
};

template<>
struct is_service_response<unitree_nav_interfaces::srv::NavToPose_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // UNITREE_NAV_INTERFACES__SRV__DETAIL__NAV_TO_POSE__TRAITS_HPP_
