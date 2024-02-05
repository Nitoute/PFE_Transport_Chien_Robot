// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from unitree_nav_interfaces:srv/NavToPose.idl
// generated code does not contain a copyright notice

#ifndef UNITREE_NAV_INTERFACES__SRV__DETAIL__NAV_TO_POSE__BUILDER_HPP_
#define UNITREE_NAV_INTERFACES__SRV__DETAIL__NAV_TO_POSE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "unitree_nav_interfaces/srv/detail/nav_to_pose__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace unitree_nav_interfaces
{

namespace srv
{

namespace builder
{

class Init_NavToPose_Request_theta
{
public:
  explicit Init_NavToPose_Request_theta(::unitree_nav_interfaces::srv::NavToPose_Request & msg)
  : msg_(msg)
  {}
  ::unitree_nav_interfaces::srv::NavToPose_Request theta(::unitree_nav_interfaces::srv::NavToPose_Request::_theta_type arg)
  {
    msg_.theta = std::move(arg);
    return std::move(msg_);
  }

private:
  ::unitree_nav_interfaces::srv::NavToPose_Request msg_;
};

class Init_NavToPose_Request_y
{
public:
  explicit Init_NavToPose_Request_y(::unitree_nav_interfaces::srv::NavToPose_Request & msg)
  : msg_(msg)
  {}
  Init_NavToPose_Request_theta y(::unitree_nav_interfaces::srv::NavToPose_Request::_y_type arg)
  {
    msg_.y = std::move(arg);
    return Init_NavToPose_Request_theta(msg_);
  }

private:
  ::unitree_nav_interfaces::srv::NavToPose_Request msg_;
};

class Init_NavToPose_Request_x
{
public:
  Init_NavToPose_Request_x()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_NavToPose_Request_y x(::unitree_nav_interfaces::srv::NavToPose_Request::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_NavToPose_Request_y(msg_);
  }

private:
  ::unitree_nav_interfaces::srv::NavToPose_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::unitree_nav_interfaces::srv::NavToPose_Request>()
{
  return unitree_nav_interfaces::srv::builder::Init_NavToPose_Request_x();
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
auto build<::unitree_nav_interfaces::srv::NavToPose_Response>()
{
  return ::unitree_nav_interfaces::srv::NavToPose_Response(rosidl_runtime_cpp::MessageInitialization::ZERO);
}

}  // namespace unitree_nav_interfaces

#endif  // UNITREE_NAV_INTERFACES__SRV__DETAIL__NAV_TO_POSE__BUILDER_HPP_
