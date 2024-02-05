// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from unitree_nav_interfaces:srv/SetBodyRPY.idl
// generated code does not contain a copyright notice

#ifndef UNITREE_NAV_INTERFACES__SRV__DETAIL__SET_BODY_RPY__BUILDER_HPP_
#define UNITREE_NAV_INTERFACES__SRV__DETAIL__SET_BODY_RPY__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "unitree_nav_interfaces/srv/detail/set_body_rpy__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace unitree_nav_interfaces
{

namespace srv
{

namespace builder
{

class Init_SetBodyRPY_Request_yaw
{
public:
  explicit Init_SetBodyRPY_Request_yaw(::unitree_nav_interfaces::srv::SetBodyRPY_Request & msg)
  : msg_(msg)
  {}
  ::unitree_nav_interfaces::srv::SetBodyRPY_Request yaw(::unitree_nav_interfaces::srv::SetBodyRPY_Request::_yaw_type arg)
  {
    msg_.yaw = std::move(arg);
    return std::move(msg_);
  }

private:
  ::unitree_nav_interfaces::srv::SetBodyRPY_Request msg_;
};

class Init_SetBodyRPY_Request_pitch
{
public:
  explicit Init_SetBodyRPY_Request_pitch(::unitree_nav_interfaces::srv::SetBodyRPY_Request & msg)
  : msg_(msg)
  {}
  Init_SetBodyRPY_Request_yaw pitch(::unitree_nav_interfaces::srv::SetBodyRPY_Request::_pitch_type arg)
  {
    msg_.pitch = std::move(arg);
    return Init_SetBodyRPY_Request_yaw(msg_);
  }

private:
  ::unitree_nav_interfaces::srv::SetBodyRPY_Request msg_;
};

class Init_SetBodyRPY_Request_roll
{
public:
  Init_SetBodyRPY_Request_roll()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SetBodyRPY_Request_pitch roll(::unitree_nav_interfaces::srv::SetBodyRPY_Request::_roll_type arg)
  {
    msg_.roll = std::move(arg);
    return Init_SetBodyRPY_Request_pitch(msg_);
  }

private:
  ::unitree_nav_interfaces::srv::SetBodyRPY_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::unitree_nav_interfaces::srv::SetBodyRPY_Request>()
{
  return unitree_nav_interfaces::srv::builder::Init_SetBodyRPY_Request_roll();
}

}  // namespace unitree_nav_interfaces


namespace unitree_nav_interfaces
{

namespace srv
{


}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::unitree_nav_interfaces::srv::SetBodyRPY_Response>()
{
  return ::unitree_nav_interfaces::srv::SetBodyRPY_Response(rosidl_runtime_cpp::MessageInitialization::ZERO);
}

}  // namespace unitree_nav_interfaces

#endif  // UNITREE_NAV_INTERFACES__SRV__DETAIL__SET_BODY_RPY__BUILDER_HPP_
