// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from ros2_unitree_legged_msgs:msg/LowState.idl
// generated code does not contain a copyright notice
#include "ros2_unitree_legged_msgs/msg/detail/low_state__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `imu`
#include "ros2_unitree_legged_msgs/msg/detail/imu__functions.h"
// Member `motor_state`
#include "ros2_unitree_legged_msgs/msg/detail/motor_state__functions.h"
// Member `bms`
#include "ros2_unitree_legged_msgs/msg/detail/bms_state__functions.h"

bool
ros2_unitree_legged_msgs__msg__LowState__init(ros2_unitree_legged_msgs__msg__LowState * msg)
{
  if (!msg) {
    return false;
  }
  // head
  // level_flag
  // frame_reserve
  // sn
  // version
  // band_width
  // imu
  if (!ros2_unitree_legged_msgs__msg__IMU__init(&msg->imu)) {
    ros2_unitree_legged_msgs__msg__LowState__fini(msg);
    return false;
  }
  // motor_state
  for (size_t i = 0; i < 20; ++i) {
    if (!ros2_unitree_legged_msgs__msg__MotorState__init(&msg->motor_state[i])) {
      ros2_unitree_legged_msgs__msg__LowState__fini(msg);
      return false;
    }
  }
  // bms
  if (!ros2_unitree_legged_msgs__msg__BmsState__init(&msg->bms)) {
    ros2_unitree_legged_msgs__msg__LowState__fini(msg);
    return false;
  }
  // foot_force
  // foot_force_est
  // tick
  // wireless_remote
  // reserve
  // crc
  return true;
}

void
ros2_unitree_legged_msgs__msg__LowState__fini(ros2_unitree_legged_msgs__msg__LowState * msg)
{
  if (!msg) {
    return;
  }
  // head
  // level_flag
  // frame_reserve
  // sn
  // version
  // band_width
  // imu
  ros2_unitree_legged_msgs__msg__IMU__fini(&msg->imu);
  // motor_state
  for (size_t i = 0; i < 20; ++i) {
    ros2_unitree_legged_msgs__msg__MotorState__fini(&msg->motor_state[i]);
  }
  // bms
  ros2_unitree_legged_msgs__msg__BmsState__fini(&msg->bms);
  // foot_force
  // foot_force_est
  // tick
  // wireless_remote
  // reserve
  // crc
}

bool
ros2_unitree_legged_msgs__msg__LowState__are_equal(const ros2_unitree_legged_msgs__msg__LowState * lhs, const ros2_unitree_legged_msgs__msg__LowState * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // head
  for (size_t i = 0; i < 2; ++i) {
    if (lhs->head[i] != rhs->head[i]) {
      return false;
    }
  }
  // level_flag
  if (lhs->level_flag != rhs->level_flag) {
    return false;
  }
  // frame_reserve
  if (lhs->frame_reserve != rhs->frame_reserve) {
    return false;
  }
  // sn
  for (size_t i = 0; i < 2; ++i) {
    if (lhs->sn[i] != rhs->sn[i]) {
      return false;
    }
  }
  // version
  for (size_t i = 0; i < 2; ++i) {
    if (lhs->version[i] != rhs->version[i]) {
      return false;
    }
  }
  // band_width
  if (lhs->band_width != rhs->band_width) {
    return false;
  }
  // imu
  if (!ros2_unitree_legged_msgs__msg__IMU__are_equal(
      &(lhs->imu), &(rhs->imu)))
  {
    return false;
  }
  // motor_state
  for (size_t i = 0; i < 20; ++i) {
    if (!ros2_unitree_legged_msgs__msg__MotorState__are_equal(
        &(lhs->motor_state[i]), &(rhs->motor_state[i])))
    {
      return false;
    }
  }
  // bms
  if (!ros2_unitree_legged_msgs__msg__BmsState__are_equal(
      &(lhs->bms), &(rhs->bms)))
  {
    return false;
  }
  // foot_force
  for (size_t i = 0; i < 4; ++i) {
    if (lhs->foot_force[i] != rhs->foot_force[i]) {
      return false;
    }
  }
  // foot_force_est
  for (size_t i = 0; i < 4; ++i) {
    if (lhs->foot_force_est[i] != rhs->foot_force_est[i]) {
      return false;
    }
  }
  // tick
  if (lhs->tick != rhs->tick) {
    return false;
  }
  // wireless_remote
  for (size_t i = 0; i < 40; ++i) {
    if (lhs->wireless_remote[i] != rhs->wireless_remote[i]) {
      return false;
    }
  }
  // reserve
  if (lhs->reserve != rhs->reserve) {
    return false;
  }
  // crc
  if (lhs->crc != rhs->crc) {
    return false;
  }
  return true;
}

bool
ros2_unitree_legged_msgs__msg__LowState__copy(
  const ros2_unitree_legged_msgs__msg__LowState * input,
  ros2_unitree_legged_msgs__msg__LowState * output)
{
  if (!input || !output) {
    return false;
  }
  // head
  for (size_t i = 0; i < 2; ++i) {
    output->head[i] = input->head[i];
  }
  // level_flag
  output->level_flag = input->level_flag;
  // frame_reserve
  output->frame_reserve = input->frame_reserve;
  // sn
  for (size_t i = 0; i < 2; ++i) {
    output->sn[i] = input->sn[i];
  }
  // version
  for (size_t i = 0; i < 2; ++i) {
    output->version[i] = input->version[i];
  }
  // band_width
  output->band_width = input->band_width;
  // imu
  if (!ros2_unitree_legged_msgs__msg__IMU__copy(
      &(input->imu), &(output->imu)))
  {
    return false;
  }
  // motor_state
  for (size_t i = 0; i < 20; ++i) {
    if (!ros2_unitree_legged_msgs__msg__MotorState__copy(
        &(input->motor_state[i]), &(output->motor_state[i])))
    {
      return false;
    }
  }
  // bms
  if (!ros2_unitree_legged_msgs__msg__BmsState__copy(
      &(input->bms), &(output->bms)))
  {
    return false;
  }
  // foot_force
  for (size_t i = 0; i < 4; ++i) {
    output->foot_force[i] = input->foot_force[i];
  }
  // foot_force_est
  for (size_t i = 0; i < 4; ++i) {
    output->foot_force_est[i] = input->foot_force_est[i];
  }
  // tick
  output->tick = input->tick;
  // wireless_remote
  for (size_t i = 0; i < 40; ++i) {
    output->wireless_remote[i] = input->wireless_remote[i];
  }
  // reserve
  output->reserve = input->reserve;
  // crc
  output->crc = input->crc;
  return true;
}

ros2_unitree_legged_msgs__msg__LowState *
ros2_unitree_legged_msgs__msg__LowState__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ros2_unitree_legged_msgs__msg__LowState * msg = (ros2_unitree_legged_msgs__msg__LowState *)allocator.allocate(sizeof(ros2_unitree_legged_msgs__msg__LowState), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(ros2_unitree_legged_msgs__msg__LowState));
  bool success = ros2_unitree_legged_msgs__msg__LowState__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
ros2_unitree_legged_msgs__msg__LowState__destroy(ros2_unitree_legged_msgs__msg__LowState * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    ros2_unitree_legged_msgs__msg__LowState__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
ros2_unitree_legged_msgs__msg__LowState__Sequence__init(ros2_unitree_legged_msgs__msg__LowState__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ros2_unitree_legged_msgs__msg__LowState * data = NULL;

  if (size) {
    data = (ros2_unitree_legged_msgs__msg__LowState *)allocator.zero_allocate(size, sizeof(ros2_unitree_legged_msgs__msg__LowState), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = ros2_unitree_legged_msgs__msg__LowState__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        ros2_unitree_legged_msgs__msg__LowState__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
ros2_unitree_legged_msgs__msg__LowState__Sequence__fini(ros2_unitree_legged_msgs__msg__LowState__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      ros2_unitree_legged_msgs__msg__LowState__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

ros2_unitree_legged_msgs__msg__LowState__Sequence *
ros2_unitree_legged_msgs__msg__LowState__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ros2_unitree_legged_msgs__msg__LowState__Sequence * array = (ros2_unitree_legged_msgs__msg__LowState__Sequence *)allocator.allocate(sizeof(ros2_unitree_legged_msgs__msg__LowState__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = ros2_unitree_legged_msgs__msg__LowState__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
ros2_unitree_legged_msgs__msg__LowState__Sequence__destroy(ros2_unitree_legged_msgs__msg__LowState__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    ros2_unitree_legged_msgs__msg__LowState__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
ros2_unitree_legged_msgs__msg__LowState__Sequence__are_equal(const ros2_unitree_legged_msgs__msg__LowState__Sequence * lhs, const ros2_unitree_legged_msgs__msg__LowState__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!ros2_unitree_legged_msgs__msg__LowState__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
ros2_unitree_legged_msgs__msg__LowState__Sequence__copy(
  const ros2_unitree_legged_msgs__msg__LowState__Sequence * input,
  ros2_unitree_legged_msgs__msg__LowState__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(ros2_unitree_legged_msgs__msg__LowState);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    ros2_unitree_legged_msgs__msg__LowState * data =
      (ros2_unitree_legged_msgs__msg__LowState *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!ros2_unitree_legged_msgs__msg__LowState__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          ros2_unitree_legged_msgs__msg__LowState__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!ros2_unitree_legged_msgs__msg__LowState__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
