// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from unitree_nav_interfaces:srv/SetBodyRPY.idl
// generated code does not contain a copyright notice

#ifndef UNITREE_NAV_INTERFACES__SRV__DETAIL__SET_BODY_RPY__FUNCTIONS_H_
#define UNITREE_NAV_INTERFACES__SRV__DETAIL__SET_BODY_RPY__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "unitree_nav_interfaces/msg/rosidl_generator_c__visibility_control.h"

#include "unitree_nav_interfaces/srv/detail/set_body_rpy__struct.h"

/// Initialize srv/SetBodyRPY message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * unitree_nav_interfaces__srv__SetBodyRPY_Request
 * )) before or use
 * unitree_nav_interfaces__srv__SetBodyRPY_Request__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_unitree_nav_interfaces
bool
unitree_nav_interfaces__srv__SetBodyRPY_Request__init(unitree_nav_interfaces__srv__SetBodyRPY_Request * msg);

/// Finalize srv/SetBodyRPY message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_unitree_nav_interfaces
void
unitree_nav_interfaces__srv__SetBodyRPY_Request__fini(unitree_nav_interfaces__srv__SetBodyRPY_Request * msg);

/// Create srv/SetBodyRPY message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * unitree_nav_interfaces__srv__SetBodyRPY_Request__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_unitree_nav_interfaces
unitree_nav_interfaces__srv__SetBodyRPY_Request *
unitree_nav_interfaces__srv__SetBodyRPY_Request__create();

/// Destroy srv/SetBodyRPY message.
/**
 * It calls
 * unitree_nav_interfaces__srv__SetBodyRPY_Request__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_unitree_nav_interfaces
void
unitree_nav_interfaces__srv__SetBodyRPY_Request__destroy(unitree_nav_interfaces__srv__SetBodyRPY_Request * msg);

/// Check for srv/SetBodyRPY message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_unitree_nav_interfaces
bool
unitree_nav_interfaces__srv__SetBodyRPY_Request__are_equal(const unitree_nav_interfaces__srv__SetBodyRPY_Request * lhs, const unitree_nav_interfaces__srv__SetBodyRPY_Request * rhs);

/// Copy a srv/SetBodyRPY message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_unitree_nav_interfaces
bool
unitree_nav_interfaces__srv__SetBodyRPY_Request__copy(
  const unitree_nav_interfaces__srv__SetBodyRPY_Request * input,
  unitree_nav_interfaces__srv__SetBodyRPY_Request * output);

/// Initialize array of srv/SetBodyRPY messages.
/**
 * It allocates the memory for the number of elements and calls
 * unitree_nav_interfaces__srv__SetBodyRPY_Request__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_unitree_nav_interfaces
bool
unitree_nav_interfaces__srv__SetBodyRPY_Request__Sequence__init(unitree_nav_interfaces__srv__SetBodyRPY_Request__Sequence * array, size_t size);

/// Finalize array of srv/SetBodyRPY messages.
/**
 * It calls
 * unitree_nav_interfaces__srv__SetBodyRPY_Request__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_unitree_nav_interfaces
void
unitree_nav_interfaces__srv__SetBodyRPY_Request__Sequence__fini(unitree_nav_interfaces__srv__SetBodyRPY_Request__Sequence * array);

/// Create array of srv/SetBodyRPY messages.
/**
 * It allocates the memory for the array and calls
 * unitree_nav_interfaces__srv__SetBodyRPY_Request__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_unitree_nav_interfaces
unitree_nav_interfaces__srv__SetBodyRPY_Request__Sequence *
unitree_nav_interfaces__srv__SetBodyRPY_Request__Sequence__create(size_t size);

/// Destroy array of srv/SetBodyRPY messages.
/**
 * It calls
 * unitree_nav_interfaces__srv__SetBodyRPY_Request__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_unitree_nav_interfaces
void
unitree_nav_interfaces__srv__SetBodyRPY_Request__Sequence__destroy(unitree_nav_interfaces__srv__SetBodyRPY_Request__Sequence * array);

/// Check for srv/SetBodyRPY message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_unitree_nav_interfaces
bool
unitree_nav_interfaces__srv__SetBodyRPY_Request__Sequence__are_equal(const unitree_nav_interfaces__srv__SetBodyRPY_Request__Sequence * lhs, const unitree_nav_interfaces__srv__SetBodyRPY_Request__Sequence * rhs);

/// Copy an array of srv/SetBodyRPY messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_unitree_nav_interfaces
bool
unitree_nav_interfaces__srv__SetBodyRPY_Request__Sequence__copy(
  const unitree_nav_interfaces__srv__SetBodyRPY_Request__Sequence * input,
  unitree_nav_interfaces__srv__SetBodyRPY_Request__Sequence * output);

/// Initialize srv/SetBodyRPY message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * unitree_nav_interfaces__srv__SetBodyRPY_Response
 * )) before or use
 * unitree_nav_interfaces__srv__SetBodyRPY_Response__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_unitree_nav_interfaces
bool
unitree_nav_interfaces__srv__SetBodyRPY_Response__init(unitree_nav_interfaces__srv__SetBodyRPY_Response * msg);

/// Finalize srv/SetBodyRPY message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_unitree_nav_interfaces
void
unitree_nav_interfaces__srv__SetBodyRPY_Response__fini(unitree_nav_interfaces__srv__SetBodyRPY_Response * msg);

/// Create srv/SetBodyRPY message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * unitree_nav_interfaces__srv__SetBodyRPY_Response__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_unitree_nav_interfaces
unitree_nav_interfaces__srv__SetBodyRPY_Response *
unitree_nav_interfaces__srv__SetBodyRPY_Response__create();

/// Destroy srv/SetBodyRPY message.
/**
 * It calls
 * unitree_nav_interfaces__srv__SetBodyRPY_Response__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_unitree_nav_interfaces
void
unitree_nav_interfaces__srv__SetBodyRPY_Response__destroy(unitree_nav_interfaces__srv__SetBodyRPY_Response * msg);

/// Check for srv/SetBodyRPY message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_unitree_nav_interfaces
bool
unitree_nav_interfaces__srv__SetBodyRPY_Response__are_equal(const unitree_nav_interfaces__srv__SetBodyRPY_Response * lhs, const unitree_nav_interfaces__srv__SetBodyRPY_Response * rhs);

/// Copy a srv/SetBodyRPY message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_unitree_nav_interfaces
bool
unitree_nav_interfaces__srv__SetBodyRPY_Response__copy(
  const unitree_nav_interfaces__srv__SetBodyRPY_Response * input,
  unitree_nav_interfaces__srv__SetBodyRPY_Response * output);

/// Initialize array of srv/SetBodyRPY messages.
/**
 * It allocates the memory for the number of elements and calls
 * unitree_nav_interfaces__srv__SetBodyRPY_Response__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_unitree_nav_interfaces
bool
unitree_nav_interfaces__srv__SetBodyRPY_Response__Sequence__init(unitree_nav_interfaces__srv__SetBodyRPY_Response__Sequence * array, size_t size);

/// Finalize array of srv/SetBodyRPY messages.
/**
 * It calls
 * unitree_nav_interfaces__srv__SetBodyRPY_Response__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_unitree_nav_interfaces
void
unitree_nav_interfaces__srv__SetBodyRPY_Response__Sequence__fini(unitree_nav_interfaces__srv__SetBodyRPY_Response__Sequence * array);

/// Create array of srv/SetBodyRPY messages.
/**
 * It allocates the memory for the array and calls
 * unitree_nav_interfaces__srv__SetBodyRPY_Response__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_unitree_nav_interfaces
unitree_nav_interfaces__srv__SetBodyRPY_Response__Sequence *
unitree_nav_interfaces__srv__SetBodyRPY_Response__Sequence__create(size_t size);

/// Destroy array of srv/SetBodyRPY messages.
/**
 * It calls
 * unitree_nav_interfaces__srv__SetBodyRPY_Response__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_unitree_nav_interfaces
void
unitree_nav_interfaces__srv__SetBodyRPY_Response__Sequence__destroy(unitree_nav_interfaces__srv__SetBodyRPY_Response__Sequence * array);

/// Check for srv/SetBodyRPY message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_unitree_nav_interfaces
bool
unitree_nav_interfaces__srv__SetBodyRPY_Response__Sequence__are_equal(const unitree_nav_interfaces__srv__SetBodyRPY_Response__Sequence * lhs, const unitree_nav_interfaces__srv__SetBodyRPY_Response__Sequence * rhs);

/// Copy an array of srv/SetBodyRPY messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_unitree_nav_interfaces
bool
unitree_nav_interfaces__srv__SetBodyRPY_Response__Sequence__copy(
  const unitree_nav_interfaces__srv__SetBodyRPY_Response__Sequence * input,
  unitree_nav_interfaces__srv__SetBodyRPY_Response__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // UNITREE_NAV_INTERFACES__SRV__DETAIL__SET_BODY_RPY__FUNCTIONS_H_
