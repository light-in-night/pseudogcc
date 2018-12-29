#ifndef __VECTOR_H_
#define __VECTOR_H_

#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <search.h>
#include "default_types.h"

#define INIT_SIZE 10

typedef struct vector_t {
    char * data;
    int elem_size;
    int size;
    int alloc;
    void (*freeFn)(void *);
    void (*mapFn)(void *, void *);
} vector_t;

/* private */
char * _vector_nth(vector_t *vec, int i);

void _vector_grow(vector_t * vec);

/* public */

void vector_init(
    vector_t * vec,
    int elem_size,
    void (*freeFn)(void *),
    void (*mapFn)(void *, void *)
    );

void vector_dispose(vector_t * vec);

void vector_push_back(vector_t * vec, void * addr_data);

void vector_pop_back(vector_t * vec, void * addr_data);

void vector_insert(vector_t * vec, void * addr_data, int i);

void vector_remove(vector_t * vec, void * addr_data, int i);

int vector_size(vector_t * vec);

int vector_isEmpty(vector_t * vec);

void vector_read(vector_t * vec, int i, void * addr_data);

void vector_write(vector_t * vec, int i, void * addr_data);

void vector_sort(vector_t * vec, int (*compareFn)(const void *, const void *));

bool vector_contains(vector_t * vec, void * addr_data, int (*compareFn)(const void *, const void *), bool isSorted);

void vector_search(vector_t * vec,  void * addr_data, void * return_data, int (*compareFn)(const void *, const void *), bool isSorted);

#endif