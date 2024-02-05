// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from unitree_nav_interfaces:srv/NavToPose.idl
// generated code does not contain a copyright notice

#ifndef UNITREE_NAV_INTERFACES__SRV__DETAIL__NAV_TO_POSE__STRUCT_H_
#define UNITREE_NAV_INTERFACES__SRV__DETAIL__NAV_TO_POSE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/NavToPose in the package unitree_nav_interfaces.
typedef struct unitree_nav_interfaces__srv__NavToPose_Request
{
  /// x coordinate of goal pose
  double x;
  /// y coordinate of goal pose
  double y;
  /// rotation of goal pose
  double theta;
} unitree_nav_interfaces__srv__NavToPose_Request;

// Struct for a sequence of unitree_nav_interfaces__srv__NavToPose_Request.
typedef struct unitree_nav_interfaces__srv__NavToPose_Request__Sequence
{
  unitree_nav_interfaces__srv__NavToPose_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} unitree_nav_interfaces__srv__NavToPose_Request__Sequence;


// Constants defined in the message

/// Struct defined in srv/NavToPose in the package unitree_nav_interfaces.
typedef struct unitree_nav_interfaces__srv__NavToPose_Response
{
  uint8_t structure_needs_at_least_one_member;
} unitree_nav_interfaces__srv__NavToPose_Response;

// Struct for a sequence of unitree_nav_interfaces__srv__NavToPose_Response.
typedef struct unitree_nav_interfaces__srv__NavToPose_Response__Sequence
{
  unitree_nav_interfaces__srv__NavToPose_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} unitree_nav_interfaces__srv__NavToPose_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // UNITREE_NAV_INTERFACES__SRV__DETAIL__NAV_TO_POSE__STRUCT_H_
