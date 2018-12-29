#ifndef __QUEUE_H__
#define __QUEUE_H__

#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "list.h"

typedef struct queue_t {
    list_t * data;
} queue_t;

void queue_init(queue_t * q, int elem_size, void (*freeFn)(void *), void (*mapFn)(void *, void *));

void queue_dispose(queue_t * q);

void queue_enqueue(queue_t * q, void * addr_data);

void queue_dequeue(queue_t * q, void * addr_data);

void queue_peek(queue_t * q, void * addr_data);

#endif