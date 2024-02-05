// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from ros2_unitree_legged_msgs:msg/MotorCmd.idl
// generated code does not contain a copyright notice

#ifndef ROS2_UNITREE_LEGGED_MSGS__MSG__DETAIL__MOTOR_CMD__STRUCT_HPP_
#define ROS2_UNITREE_LEGGED_MSGS__MSG__DETAIL__MOTOR_CMD__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__ros2_unitree_legged_msgs__msg__MotorCmd __attribute__((deprecated))
#else
# define DEPRECATED__ros2_unitree_legged_msgs__msg__MotorCmd __declspec(deprecated)
#endif

namespace ros2_unitree_legged_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct MotorCmd_
{
  using Type = MotorCmd_<ContainerAllocator>;

  explicit MotorCmd_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->mode = 0;
      this->q = 0.0f;
      this->dq = 0.0f;
      this->tau = 0.0f;
      this->kp = 0.0f;
      this->kd = 0.0f;
      std::fill<typename std::array<uint32_t, 3>::iterator, uint32_t>(this->reserve.begin(), this->reserve.end(), 0ul);
    }
  }

  explicit MotorCmd_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : reserve(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->mode = 0;
      this->q = 0.0f;
      this->dq = 0.0f;
      this->tau = 0.0f;
      this->kp = 0.0f;
      this->kd = 0.0f;
      std::fill<typename std::array<uint32_t, 3>::iterator, uint32_t>(this->reserve.begin(), this->reserve.end(), 0ul);
    }
  }

  // field types and members
  using _mode_type =
    uint8_t;
  _mode_type mode;
  using _q_type =
    float;
  _q_type q;
  using _dq_type =
    float;
  _dq_type dq;
  using _tau_type =
    float;
  _tau_type tau;
  using _kp_type =
    float;
  _kp_type kp;
  using _kd_type =
    float;
  _kd_type kd;
  using _reserve_type =
    std::array<uint32_t, 3>;
  _reserve_type reserve;

  // setters for named parameter idiom
  Type & set__mode(
    const uint8_t & _arg)
  {
    this->mode = _arg;
    return *this;
  }
  Type & set__q(
    const float & _arg)
  {
    this->q = _arg;
    return *this;
  }
  Type & set__dq(
    const float & _arg)
  {
    this->dq = _arg;
    return *this;
  }
  Type & set__tau(
    const float & _arg)
  {
    this->tau = _arg;
    return *this;
  }
  Type & set__kp(
    const float & _arg)
  {
    this->kp = _arg;
    return *this;
  }
  Type & set__kd(
    const float & _arg)
  {
    this->kd = _arg;
    return *this;
  }
  Type & set__reserve(
    const std::array<uint32_t, 3> & _arg)
  {
    this->reserve = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    ros2_unitree_legged_msgs::msg::MotorCmd_<ContainerAllocator> *;
  using ConstRawPtr =
    const ros2_unitree_legged_msgs::msg::MotorCmd_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<ros2_unitree_legged_msgs::msg::MotorCmd_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<ros2_unitree_legged_msgs::msg::MotorCmd_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      ros2_unitree_legged_msgs::msg::MotorCmd_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<ros2_unitree_legged_msgs::msg::MotorCmd_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      ros2_unitree_legged_msgs::msg::MotorCmd_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<ros2_unitree_legged_msgs::msg::MotorCmd_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<ros2_unitree_legged_msgs::msg::MotorCmd_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<ros2_unitree_legged_msgs::msg::MotorCmd_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__ros2_unitree_legged_msgs__msg__MotorCmd
    std::shared_ptr<ros2_unitree_legged_msgs::msg::MotorCmd_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__ros2_unitree_legged_msgs__msg__MotorCmd
    std::shared_ptr<ros2_unitree_legged_msgs::msg::MotorCmd_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const MotorCmd_ & other) const
  {
    if (this->mode != other.mode) {
      return false;
    }
    if (this->q != other.q) {
      return false;
    }
    if (this->dq != other.dq) {
      return false;
    }
    if (this->tau != other.tau) {
      return false;
    }
    if (this->kp != other.kp) {
      return false;
    }
    if (this->kd != other.kd) {
      return false;
    }
    if (this->reserve != other.reserve) {
      return false;
    }
    return true;
  }
  bool operator!=(const MotorCmd_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct MotorCmd_

// alias to use template instance with default allocator
using MotorCmd =
  ros2_unitree_legged_msgs::msg::MotorCmd_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace ros2_unitree_legged_msgs

#endif  // ROS2_UNITREE_LEGGED_MSGS__MSG__DETAIL__MOTOR_CMD__STRUCT_HPP_
