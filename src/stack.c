#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "stack.h"
#include "vector.h"

void stack_init(
    stack_t * st,
    int elem_size,
    void (*freeFn)(void *),
    void (*mapFn)(void *, void*)
) {
    vector_t * vec = malloc(sizeof(vector_t));
    vector_init(vec, elem_size, freeFn, mapFn);
    st->vec = vec;
}

void stack_dispose(stack_t * st) {
    vector_dispose(st->vec);
    free(st->vec);
}

void stack_push(stack_t * st, void * addr_data) {
   vector_push_back(st->vec,addr_data);
}

bool stack_isEmpty(stack_t * st) {
    return vector_isEmpty(st->vec);
}

void stack_pop(stack_t * st, void * addr_data) {
   assert(!stack_isEmpty(st));
   vector_pop_back(st->vec,addr_data);
}

void stack_peek(stack_t * st, void * addr_data) {
    assert(!stack_isEmpty(st));
    vector_read(st->vec,vector_size(st->vec)-1,addr_data);    
}
