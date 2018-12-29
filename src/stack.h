#ifndef __STACK_H__
#define __STACK_H__

#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "vector.h"
#include "default_types.h"

typedef struct stack_t {
    vector_t * vec;
} stack_t;

void stack_init(
    stack_t * st,
    int elem_size,
    void (*freeFn)(void *),
    void (*mapFn)(void *, void*)
);

void stack_dispose(stack_t * st);

void stack_push(stack_t * st, void * addr_data);

bool stack_isEmpty(stack_t * st);

void stack_pop(stack_t * st, void * addr_data);

void stack_peek(stack_t * st, void * addr_data);

#endif