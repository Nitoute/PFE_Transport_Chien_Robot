// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from unitree_nav_interfaces:srv/SetBodyRPY.idl
// generated code does not contain a copyright notice
#include "unitree_nav_interfaces/srv/detail/set_body_rpy__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

bool
unitree_nav_interfaces__srv__SetBodyRPY_Request__init(unitree_nav_interfaces__srv__SetBodyRPY_Request * msg)
{
  if (!msg) {
    return false;
  }
  // roll
  // pitch
  // yaw
  return true;
}

void
unitree_nav_interfaces__srv__SetBodyRPY_Request__fini(unitree_nav_interfaces__srv__SetBodyRPY_Request * msg)
{
  if (!msg) {
    return;
  }
  // roll
  // pitch
  // yaw
}

bool
unitree_nav_interfaces__srv__SetBodyRPY_Request__are_equal(const unitree_nav_interfaces__srv__SetBodyRPY_Request * lhs, const unitree_nav_interfaces__srv__SetBodyRPY_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // roll
  if (lhs->roll != rhs->roll) {
    return false;
  }
  // pitch
  if (lhs->pitch != rhs->pitch) {
    return false;
  }
  // yaw
  if (lhs->yaw != rhs->yaw) {
    return false;
  }
  return true;
}

bool
unitree_nav_interfaces__srv__SetBodyRPY_Request__copy(
  const unitree_nav_interfaces__srv__SetBodyRPY_Request * input,
  unitree_nav_interfaces__srv__SetBodyRPY_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // roll
  output->roll = input->roll;
  // pitch
  output->pitch = input->pitch;
  // yaw
  output->yaw = input->yaw;
  return true;
}

unitree_nav_interfaces__srv__SetBodyRPY_Request *
unitree_nav_interfaces__srv__SetBodyRPY_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  unitree_nav_interfaces__srv__SetBodyRPY_Request * msg = (unitree_nav_interfaces__srv__SetBodyRPY_Request *)allocator.allocate(sizeof(unitree_nav_interfaces__srv__SetBodyRPY_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(unitree_nav_interfaces__srv__SetBodyRPY_Request));
  bool success = unitree_nav_interfaces__srv__SetBodyRPY_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
unitree_nav_interfaces__srv__SetBodyRPY_Request__destroy(unitree_nav_interfaces__srv__SetBodyRPY_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    unitree_nav_interfaces__srv__SetBodyRPY_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
unitree_nav_interfaces__srv__SetBodyRPY_Request__Sequence__init(unitree_nav_interfaces__srv__SetBodyRPY_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  unitree_nav_interfaces__srv__SetBodyRPY_Request * data = NULL;

  if (size) {
    data = (unitree_nav_interfaces__srv__SetBodyRPY_Request *)allocator.zero_allocate(size, sizeof(unitree_nav_interfaces__srv__SetBodyRPY_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = unitree_nav_interfaces__srv__SetBodyRPY_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        unitree_nav_interfaces__srv__SetBodyRPY_Request__fini(&data[i - 1]);
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
unitree_nav_interfaces__srv__SetBodyRPY_Request__Sequence__fini(unitree_nav_interfaces__srv__SetBodyRPY_Request__Sequence * array)
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
      unitree_nav_interfaces__srv__SetBodyRPY_Request__fini(&array->data[i]);
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

unitree_nav_interfaces__srv__SetBodyRPY_Request__Sequence *
unitree_nav_interfaces__srv__SetBodyRPY_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  unitree_nav_interfaces__srv__SetBodyRPY_Request__Sequence * array = (unitree_nav_interfaces__srv__SetBodyRPY_Request__Sequence *)allocator.allocate(sizeof(unitree_nav_interfaces__srv__SetBodyRPY_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = unitree_nav_interfaces__srv__SetBodyRPY_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
unitree_nav_interfaces__srv__SetBodyRPY_Request__Sequence__destroy(unitree_nav_interfaces__srv__SetBodyRPY_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    unitree_nav_interfaces__srv__SetBodyRPY_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
unitree_nav_interfaces__srv__SetBodyRPY_Request__Sequence__are_equal(const unitree_nav_interfaces__srv__SetBodyRPY_Request__Sequence * lhs, const unitree_nav_interfaces__srv__SetBodyRPY_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!unitree_nav_interfaces__srv__SetBodyRPY_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
unitree_nav_interfaces__srv__SetBodyRPY_Request__Sequence__copy(
  const unitree_nav_interfaces__srv__SetBodyRPY_Request__Sequence * input,
  unitree_nav_interfaces__srv__SetBodyRPY_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(unitree_nav_interfaces__srv__SetBodyRPY_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    unitree_nav_interfaces__srv__SetBodyRPY_Request * data =
      (unitree_nav_interfaces__srv__SetBodyRPY_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!unitree_nav_interfaces__srv__SetBodyRPY_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          unitree_nav_interfaces__srv__SetBodyRPY_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!unitree_nav_interfaces__srv__SetBodyRPY_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


bool
unitree_nav_interfaces__srv__SetBodyRPY_Response__init(unitree_nav_interfaces__srv__SetBodyRPY_Response * msg)
{
  if (!msg) {
    return false;
  }
  // structure_needs_at_least_one_member
  return true;
}

void
unitree_nav_interfaces__srv__SetBodyRPY_Response__fini(unitree_nav_interfaces__srv__SetBodyRPY_Response * msg)
{
  if (!msg) {
    return;
  }
  // structure_needs_at_least_one_member
}

bool
unitree_nav_interfaces__srv__SetBodyRPY_Response__are_equal(const unitree_nav_interfaces__srv__SetBodyRPY_Response * lhs, const unitree_nav_interfaces__srv__SetBodyRPY_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // structure_needs_at_least_one_member
  if (lhs->structure_needs_at_least_one_member != rhs->structure_needs_at_least_one_member) {
    return false;
  }
  return true;
}

bool
unitree_nav_interfaces__srv__SetBodyRPY_Response__copy(
  const unitree_nav_interfaces__srv__SetBodyRPY_Response * input,
  unitree_nav_interfaces__srv__SetBodyRPY_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // structure_needs_at_least_one_member
  output->structure_needs_at_least_one_member = input->structure_needs_at_least_one_member;
  return true;
}

unitree_nav_interfaces__srv__SetBodyRPY_Response *
unitree_nav_interfaces__srv__SetBodyRPY_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  unitree_nav_interfaces__srv__SetBodyRPY_Response * msg = (unitree_nav_interfaces__srv__SetBodyRPY_Response *)allocator.allocate(sizeof(unitree_nav_interfaces__srv__SetBodyRPY_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(unitree_nav_interfaces__srv__SetBodyRPY_Response));
  bool success = unitree_nav_interfaces__srv__SetBodyRPY_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
unitree_nav_interfaces__srv__SetBodyRPY_Response__destroy(unitree_nav_interfaces__srv__SetBodyRPY_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    unitree_nav_interfaces__srv__SetBodyRPY_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
unitree_nav_interfaces__srv__SetBodyRPY_Response__Sequence__init(unitree_nav_interfaces__srv__SetBodyRPY_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  unitree_nav_interfaces__srv__SetBodyRPY_Response * data = NULL;

  if (size) {
    data = (unitree_nav_interfaces__srv__SetBodyRPY_Response *)allocator.zero_allocate(size, sizeof(unitree_nav_interfaces__srv__SetBodyRPY_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = unitree_nav_interfaces__srv__SetBodyRPY_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        unitree_nav_interfaces__srv__SetBodyRPY_Response__fini(&data[i - 1]);
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
unitree_nav_interfaces__srv__SetBodyRPY_Response__Sequence__fini(unitree_nav_interfaces__srv__SetBodyRPY_Response__Sequence * array)
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
      unitree_nav_interfaces__srv__SetBodyRPY_Response__fini(&array->data[i]);
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

unitree_nav_interfaces__srv__SetBodyRPY_Response__Sequence *
unitree_nav_interfaces__srv__SetBodyRPY_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  unitree_nav_interfaces__srv__SetBodyRPY_Response__Sequence * array = (unitree_nav_interfaces__srv__SetBodyRPY_Response__Sequence *)allocator.allocate(sizeof(unitree_nav_interfaces__srv__SetBodyRPY_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = unitree_nav_interfaces__srv__SetBodyRPY_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
unitree_nav_interfaces__srv__SetBodyRPY_Response__Sequence__destroy(unitree_nav_interfaces__srv__SetBodyRPY_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    unitree_nav_interfaces__srv__SetBodyRPY_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
unitree_nav_interfaces__srv__SetBodyRPY_Response__Sequence__are_equal(const unitree_nav_interfaces__srv__SetBodyRPY_Response__Sequence * lhs, const unitree_nav_interfaces__srv__SetBodyRPY_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!unitree_nav_interfaces__srv__SetBodyRPY_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
unitree_nav_interfaces__srv__SetBodyRPY_Response__Sequence__copy(
  const unitree_nav_interfaces__srv__SetBodyRPY_Response__Sequence * input,
  unitree_nav_interfaces__srv__SetBodyRPY_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(unitree_nav_interfaces__srv__SetBodyRPY_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    unitree_nav_interfaces__srv__SetBodyRPY_Response * data =
      (unitree_nav_interfaces__srv__SetBodyRPY_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!unitree_nav_interfaces__srv__SetBodyRPY_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          unitree_nav_interfaces__srv__SetBodyRPY_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!unitree_nav_interfaces__srv__SetBodyRPY_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
