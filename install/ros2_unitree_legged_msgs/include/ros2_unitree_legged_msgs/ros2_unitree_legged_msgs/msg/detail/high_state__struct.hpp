// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from ros2_unitree_legged_msgs:msg/HighState.idl
// generated code does not contain a copyright notice

#ifndef ROS2_UNITREE_LEGGED_MSGS__MSG__DETAIL__HIGH_STATE__STRUCT_HPP_
#define ROS2_UNITREE_LEGGED_MSGS__MSG__DETAIL__HIGH_STATE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'imu'
#include "ros2_unitree_legged_msgs/msg/detail/imu__struct.hpp"
// Member 'motor_state'
#include "ros2_unitree_legged_msgs/msg/detail/motor_state__struct.hpp"
// Member 'bms'
#include "ros2_unitree_legged_msgs/msg/detail/bms_state__struct.hpp"
// Member 'foot_position2body'
// Member 'foot_speed2body'
#include "ros2_unitree_legged_msgs/msg/detail/cartesian__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__ros2_unitree_legged_msgs__msg__HighState __attribute__((deprecated))
#else
# define DEPRECATED__ros2_unitree_legged_msgs__msg__HighState __declspec(deprecated)
#endif

namespace ros2_unitree_legged_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct HighState_
{
  using Type = HighState_<ContainerAllocator>;

  explicit HighState_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : imu(_init),
    bms(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      std::fill<typename std::array<uint8_t, 2>::iterator, uint8_t>(this->head.begin(), this->head.end(), 0);
      this->level_flag = 0;
      this->frame_reserve = 0;
      std::fill<typename std::array<uint32_t, 2>::iterator, uint32_t>(this->sn.begin(), this->sn.end(), 0ul);
      std::fill<typename std::array<uint32_t, 2>::iterator, uint32_t>(this->version.begin(), this->version.end(), 0ul);
      this->band_width = 0;
      this->motor_state.fill(ros2_unitree_legged_msgs::msg::MotorState_<ContainerAllocator>{_init});
      std::fill<typename std::array<int16_t, 4>::iterator, int16_t>(this->foot_force.begin(), this->foot_force.end(), 0);
      std::fill<typename std::array<int16_t, 4>::iterator, int16_t>(this->foot_force_est.begin(), this->foot_force_est.end(), 0);
      this->mode = 0;
      this->progress = 0.0f;
      this->gait_type = 0;
      this->foot_raise_height = 0.0f;
      std::fill<typename std::array<float, 3>::iterator, float>(this->position.begin(), this->position.end(), 0.0f);
      this->body_height = 0.0f;
      std::fill<typename std::array<float, 3>::iterator, float>(this->velocity.begin(), this->velocity.end(), 0.0f);
      this->yaw_speed = 0.0f;
      std::fill<typename std::array<float, 4>::iterator, float>(this->range_obstacle.begin(), this->range_obstacle.end(), 0.0f);
      this->foot_position2body.fill(ros2_unitree_legged_msgs::msg::Cartesian_<ContainerAllocator>{_init});
      this->foot_speed2body.fill(ros2_unitree_legged_msgs::msg::Cartesian_<ContainerAllocator>{_init});
      std::fill<typename std::array<uint8_t, 40>::iterator, uint8_t>(this->wireless_remote.begin(), this->wireless_remote.end(), 0);
      this->reserve = 0ul;
      this->crc = 0ul;
    }
  }

  explicit HighState_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : head(_alloc),
    sn(_alloc),
    version(_alloc),
    imu(_alloc, _init),
    motor_state(_alloc),
    bms(_alloc, _init),
    foot_force(_alloc),
    foot_force_est(_alloc),
    position(_alloc),
    velocity(_alloc),
    range_obstacle(_alloc),
    foot_position2body(_alloc),
    foot_speed2body(_alloc),
    wireless_remote(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      std::fill<typename std::array<uint8_t, 2>::iterator, uint8_t>(this->head.begin(), this->head.end(), 0);
      this->level_flag = 0;
      this->frame_reserve = 0;
      std::fill<typename std::array<uint32_t, 2>::iterator, uint32_t>(this->sn.begin(), this->sn.end(), 0ul);
      std::fill<typename std::array<uint32_t, 2>::iterator, uint32_t>(this->version.begin(), this->version.end(), 0ul);
      this->band_width = 0;
      this->motor_state.fill(ros2_unitree_legged_msgs::msg::MotorState_<ContainerAllocator>{_alloc, _init});
      std::fill<typename std::array<int16_t, 4>::iterator, int16_t>(this->foot_force.begin(), this->foot_force.end(), 0);
      std::fill<typename std::array<int16_t, 4>::iterator, int16_t>(this->foot_force_est.begin(), this->foot_force_est.end(), 0);
      this->mode = 0;
      this->progress = 0.0f;
      this->gait_type = 0;
      this->foot_raise_height = 0.0f;
      std::fill<typename std::array<float, 3>::iterator, float>(this->position.begin(), this->position.end(), 0.0f);
      this->body_height = 0.0f;
      std::fill<typename std::array<float, 3>::iterator, float>(this->velocity.begin(), this->velocity.end(), 0.0f);
      this->yaw_speed = 0.0f;
      std::fill<typename std::array<float, 4>::iterator, float>(this->range_obstacle.begin(), this->range_obstacle.end(), 0.0f);
      this->foot_position2body.fill(ros2_unitree_legged_msgs::msg::Cartesian_<ContainerAllocator>{_alloc, _init});
      this->foot_speed2body.fill(ros2_unitree_legged_msgs::msg::Cartesian_<ContainerAllocator>{_alloc, _init});
      std::fill<typename std::array<uint8_t, 40>::iterator, uint8_t>(this->wireless_remote.begin(), this->wireless_remote.end(), 0);
      this->reserve = 0ul;
      this->crc = 0ul;
    }
  }

  // field types and members
  using _head_type =
    std::array<uint8_t, 2>;
  _head_type head;
  using _level_flag_type =
    uint8_t;
  _level_flag_type level_flag;
  using _frame_reserve_type =
    uint8_t;
  _frame_reserve_type frame_reserve;
  using _sn_type =
    std::array<uint32_t, 2>;
  _sn_type sn;
  using _version_type =
    std::array<uint32_t, 2>;
  _version_type version;
  using _band_width_type =
    uint16_t;
  _band_width_type band_width;
  using _imu_type =
    ros2_unitree_legged_msgs::msg::IMU_<ContainerAllocator>;
  _imu_type imu;
  using _motor_state_type =
    std::array<ros2_unitree_legged_msgs::msg::MotorState_<ContainerAllocator>, 20>;
  _motor_state_type motor_state;
  using _bms_type =
    ros2_unitree_legged_msgs::msg::BmsState_<ContainerAllocator>;
  _bms_type bms;
  using _foot_force_type =
    std::array<int16_t, 4>;
  _foot_force_type foot_force;
  using _foot_force_est_type =
    std::array<int16_t, 4>;
  _foot_force_est_type foot_force_est;
  using _mode_type =
    uint8_t;
  _mode_type mode;
  using _progress_type =
    float;
  _progress_type progress;
  using _gait_type_type =
    uint8_t;
  _gait_type_type gait_type;
  using _foot_raise_height_type =
    float;
  _foot_raise_height_type foot_raise_height;
  using _position_type =
    std::array<float, 3>;
  _position_type position;
  using _body_height_type =
    float;
  _body_height_type body_height;
  using _velocity_type =
    std::array<float, 3>;
  _velocity_type velocity;
  using _yaw_speed_type =
    float;
  _yaw_speed_type yaw_speed;
  using _range_obstacle_type =
    std::array<float, 4>;
  _range_obstacle_type range_obstacle;
  using _foot_position2body_type =
    std::array<ros2_unitree_legged_msgs::msg::Cartesian_<ContainerAllocator>, 4>;
  _foot_position2body_type foot_position2body;
  using _foot_speed2body_type =
    std::array<ros2_unitree_legged_msgs::msg::Cartesian_<ContainerAllocator>, 4>;
  _foot_speed2body_type foot_speed2body;
  using _wireless_remote_type =
    std::array<uint8_t, 40>;
  _wireless_remote_type wireless_remote;
  using _reserve_type =
    uint32_t;
  _reserve_type reserve;
  using _crc_type =
    uint32_t;
  _crc_type crc;

  // setters for named parameter idiom
  Type & set__head(
    const std::array<uint8_t, 2> & _arg)
  {
    this->head = _arg;
    return *this;
  }
  Type & set__level_flag(
    const uint8_t & _arg)
  {
    this->level_flag = _arg;
    return *this;
  }
  Type & set__frame_reserve(
    const uint8_t & _arg)
  {
    this->frame_reserve = _arg;
    return *this;
  }
  Type & set__sn(
    const std::array<uint32_t, 2> & _arg)
  {
    this->sn = _arg;
    return *this;
  }
  Type & set__version(
    const std::array<uint32_t, 2> & _arg)
  {
    this->version = _arg;
    return *this;
  }
  Type & set__band_width(
    const uint16_t & _arg)
  {
    this->band_width = _arg;
    return *this;
  }
  Type & set__imu(
    const ros2_unitree_legged_msgs::msg::IMU_<ContainerAllocator> & _arg)
  {
    this->imu = _arg;
    return *this;
  }
  Type & set__motor_state(
    const std::array<ros2_unitree_legged_msgs::msg::MotorState_<ContainerAllocator>, 20> & _arg)
  {
    this->motor_state = _arg;
    return *this;
  }
  Type & set__bms(
    const ros2_unitree_legged_msgs::msg::BmsState_<ContainerAllocator> & _arg)
  {
    this->bms = _arg;
    return *this;
  }
  Type & set__foot_force(
    const std::array<int16_t, 4> & _arg)
  {
    this->foot_force = _arg;
    return *this;
  }
  Type & set__foot_force_est(
    const std::array<int16_t, 4> & _arg)
  {
    this->foot_force_est = _arg;
    return *this;
  }
  Type & set__mode(
    const uint8_t & _arg)
  {
    this->mode = _arg;
    return *this;
  }
  Type & set__progress(
    const float & _arg)
  {
    this->progress = _arg;
    return *this;
  }
  Type & set__gait_type(
    const uint8_t & _arg)
  {
    this->gait_type = _arg;
    return *this;
  }
  Type & set__foot_raise_height(
    const float & _arg)
  {
    this->foot_raise_height = _arg;
    return *this;
  }
  Type & set__position(
    const std::array<float, 3> & _arg)
  {
    this->position = _arg;
    return *this;
  }
  Type & set__body_height(
    const float & _arg)
  {
    this->body_height = _arg;
    return *this;
  }
  Type & set__velocity(
    const std::array<float, 3> & _arg)
  {
    this->velocity = _arg;
    return *this;
  }
  Type & set__yaw_speed(
    const float & _arg)
  {
    this->yaw_speed = _arg;
    return *this;
  }
  Type & set__range_obstacle(
    const std::array<float, 4> & _arg)
  {
    this->range_obstacle = _arg;
    return *this;
  }
  Type & set__foot_position2body(
    const std::array<ros2_unitree_legged_msgs::msg::Cartesian_<ContainerAllocator>, 4> & _arg)
  {
    this->foot_position2body = _arg;
    return *this;
  }
  Type & set__foot_speed2body(
    const std::array<ros2_unitree_legged_msgs::msg::Cartesian_<ContainerAllocator>, 4> & _arg)
  {
    this->foot_speed2body = _arg;
    return *this;
  }
  Type & set__wireless_remote(
    const std::array<uint8_t, 40> & _arg)
  {
    this->wireless_remote = _arg;
    return *this;
  }
  Type & set__reserve(
    const uint32_t & _arg)
  {
    this->reserve = _arg;
    return *this;
  }
  Type & set__crc(
    const uint32_t & _arg)
  {
    this->crc = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    ros2_unitree_legged_msgs::msg::HighState_<ContainerAllocator> *;
  using ConstRawPtr =
    const ros2_unitree_legged_msgs::msg::HighState_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<ros2_unitree_legged_msgs::msg::HighState_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<ros2_unitree_legged_msgs::msg::HighState_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      ros2_unitree_legged_msgs::msg::HighState_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<ros2_unitree_legged_msgs::msg::HighState_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      ros2_unitree_legged_msgs::msg::HighState_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<ros2_unitree_legged_msgs::msg::HighState_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<ros2_unitree_legged_msgs::msg::HighState_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<ros2_unitree_legged_msgs::msg::HighState_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__ros2_unitree_legged_msgs__msg__HighState
    std::shared_ptr<ros2_unitree_legged_msgs::msg::HighState_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__ros2_unitree_legged_msgs__msg__HighState
    std::shared_ptr<ros2_unitree_legged_msgs::msg::HighState_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const HighState_ & other) const
  {
    if (this->head != other.head) {
      return false;
    }
    if (this->level_flag != other.level_flag) {
      return false;
    }
    if (this->frame_reserve != other.frame_reserve) {
      return false;
    }
    if (this->sn != other.sn) {
      return false;
    }
    if (this->version != other.version) {
      return false;
    }
    if (this->band_width != other.band_width) {
      return false;
    }
    if (this->imu != other.imu) {
      return false;
    }
    if (this->motor_state != other.motor_state) {
      return false;
    }
    if (this->bms != other.bms) {
      return false;
    }
    if (this->foot_force != other.foot_force) {
      return false;
    }
    if (this->foot_force_est != other.foot_force_est) {
      return false;
    }
    if (this->mode != other.mode) {
      return false;
    }
    if (this->progress != other.progress) {
      return false;
    }
    if (this->gait_type != other.gait_type) {
      return false;
    }
    if (this->foot_raise_height != other.foot_raise_height) {
      return false;
    }
    if (this->position != other.position) {
      return false;
    }
    if (this->body_height != other.body_height) {
      return false;
    }
    if (this->velocity != other.velocity) {
      return false;
    }
    if (this->yaw_speed != other.yaw_speed) {
      return false;
    }
    if (this->range_obstacle != other.range_obstacle) {
      return false;
    }
    if (this->foot_position2body != other.foot_position2body) {
      return false;
    }
    if (this->foot_speed2body != other.foot_speed2body) {
      return false;
    }
    if (this->wireless_remote != other.wireless_remote) {
      return false;
    }
    if (this->reserve != other.reserve) {
      return false;
    }
    if (this->crc != other.crc) {
      return false;
    }
    return true;
  }
  bool operator!=(const HighState_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct HighState_

// alias to use template instance with default allocator
using HighState =
  ros2_unitree_legged_msgs::msg::HighState_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace ros2_unitree_legged_msgs

#endif  // ROS2_UNITREE_LEGGED_MSGS__MSG__DETAIL__HIGH_STATE__STRUCT_HPP_
