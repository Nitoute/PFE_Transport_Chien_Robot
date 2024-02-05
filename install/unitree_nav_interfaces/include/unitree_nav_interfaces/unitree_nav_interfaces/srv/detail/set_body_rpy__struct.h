// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from unitree_nav_interfaces:srv/SetBodyRPY.idl
// generated code does not contain a copyright notice

#ifndef UNITREE_NAV_INTERFACES__SRV__DETAIL__SET_BODY_RPY__STRUCT_H_
#define UNITREE_NAV_INTERFACES__SRV__DETAIL__SET_BODY_RPY__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/SetBodyRPY in the package unitree_nav_interfaces.
typedef struct unitree_nav_interfaces__srv__SetBodyRPY_Request
{
  /// rotation about the x-axis
  /// range is about -0.8 to 0.8
  double roll;
  /// rotation about the y-axis
  /// negative to look up, positive to look down
  /// range is about -0.6 to 0.6
  double pitch;
  /// rotation about the z-axis
  /// negative to look left, positive to look right
  /// range is about -0.3 to 0.3
  double yaw;
} unitree_nav_interfaces__srv__SetBodyRPY_Request;

// Struct for a sequence of unitree_nav_interfaces__srv__SetBodyRPY_Request.
typedef struct unitree_nav_interfaces__srv__SetBodyRPY_Request__Sequence
{
  unitree_nav_interfaces__srv__SetBodyRPY_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} unitree_nav_interfaces__srv__SetBodyRPY_Request__Sequence;


// Constants defined in the message

/// Struct defined in srv/SetBodyRPY in the package unitree_nav_interfaces.
typedef struct unitree_nav_interfaces__srv__SetBodyRPY_Response
{
  uint8_t structure_needs_at_least_one_member;
} unitree_nav_interfaces__srv__SetBodyRPY_Response;

// Struct for a sequence of unitree_nav_interfaces__srv__SetBodyRPY_Response.
typedef struct unitree_nav_interfaces__srv__SetBodyRPY_Response__Sequence
{
  unitree_nav_interfaces__srv__SetBodyRPY_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} unitree_nav_interfaces__srv__SetBodyRPY_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // UNITREE_NAV_INTERFACES__SRV__DETAIL__SET_BODY_RPY__STRUCT_H_
