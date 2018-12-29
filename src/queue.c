#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "queue.h"

void queue_init(queue_t * q, int elem_size, 
void (*freeFn)(void *), 
void (*mapFn)(void *, void *)) {
    q->data = malloc(sizeof(list_t));
    list_init(q->data,elem_size,freeFn,mapFn);
}

void queue_dispose(queue_t * q) {
    list_dispose(q->data);
    free(q->data);
}

void queue_enqueue(queue_t * q, void * addr_data) {
    list_push_front(q->data, addr_data);
}

void queue_dequeue(queue_t * q, void * addr_data) {
    list_pop_back(q->data, addr_data);
}

void queue_peek(queue_t * q, void * addr_data) {
    list_peek_back(q->data, addr_data);
}
