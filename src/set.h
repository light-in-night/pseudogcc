#ifndef __SET_H_
#define __SET_H_

#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "vector.h"
#include "default_types.h"

typedef struct set_t {
    vector_t * data; 
    int (*compareFn)(const void *, const void *)
} set_t;

void set_init(set_t * s, int elem_size, void (*freeFn), void (*mapFn)) {

}

void set_dispose(set_t * s) {
    vector_dispose(s->data);
}

void set_insert(set_t * s, void * addr_data) {
    vector_push_back(s);
}

void set_contains(set_t * s, void * addr_data) {
    
}

void set_remove(set_t * s, void * addr_data) {

}


#endif