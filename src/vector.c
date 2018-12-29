#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "vector.h"

#define INIT_SIZE 10

/* private */
char * _vector_nth(vector_t *vec, int i) {
    return vec->data + vec->elem_size * i;
}

void _vector_grow(vector_t * vec) {
    vec->alloc *= 2;
    char * new_data = realloc(vec->data, vec->elem_size * vec->alloc);
    assert(new_data != NULL);
    vec->data = new_data;
}

/* public */

void vector_init(
    vector_t * vec,
    int elem_size,
    void (*freeFn)(void *),
    void (*mapFn)(void *, void *)
    ) {
    vec->data = malloc(elem_size * INIT_SIZE);
    vec->elem_size = elem_size;
    vec->size = 0;
    vec->alloc = INIT_SIZE;
    vec->freeFn = freeFn;
    vec->mapFn = mapFn;
}


void vector_dispose(vector_t * vec) {
    if(vec->freeFn != NULL)
        for(int i = 0; i < vec->size; i++)
            vec->freeFn(_vector_nth(vec,i));
    free(vec->data);
}

void vector_push_back(vector_t * vec, void * addr_data) {
    if(vec->size == vec->alloc) 
        _vector_grow(vec);
    
    memcpy(_vector_nth(vec, vec->size), addr_data, vec->elem_size);
    vec->size++;
}

void vector_pop_back(vector_t * vec, void * addr_data) {
    assert(vec->size > 0);
    memcpy(addr_data, _vector_nth(vec, vec->size-1),  vec->elem_size);
    vec->size--;
}

void vector_insert(vector_t * vec, void * addr_data, int i) {
    assert(i >= 0 && i < vec->size);
    if(vec->size == vec->alloc) 
        _vector_grow(vec);
    memmove(_vector_nth(vec,i+1), _vector_nth(vec, i), vec->elem_size * (vec->size - i));
    memcpy(_vector_nth(vec,i), addr_data, vec->elem_size);
    vec->size++;
}


void vector_remove(vector_t * vec, void * addr_data, int i) {
    assert(i >= 0 && i < vec->size);
    memmove(_vector_nth(vec, i),_vector_nth(vec, i+1), vec->elem_size * (vec->size - i - 1));
    vec->size--;
}

int vector_size(vector_t * vec) {
    return vec->size;
}

int vector_isEmpty(vector_t * vec) {
    return vec->size == 0;
}

void vector_read(vector_t * vec, int i, void * addr_data) {
    assert(i >= 0 && i < vector_size(vec));
    memcpy(addr_data, _vector_nth(vec,i),vec->elem_size);
}

void vector_write(vector_t * vec, int i, void * addr_data) {
    assert(i >= 0 && i < vector_size(vec));
    memcpy(_vector_nth(vec,i),addr_data,vec->elem_size);
}
 
void vector_sort(vector_t * vec, int (*compareFn)(const void *, const void *)) {
    qsort(_vector_nth(vec,0), vector_size(vec), vec->elem_size, compareFn);
}

bool vector_contains(
    vector_t * vec,
    void * addr_data,
    int (*compareFn)(const void *, const void *),
    bool isSorted) 
{
    void * ret;
    size_t nmemb_bsearch = ((size_t)(vec->size));
    long unsigned int val = (long unsigned int)(vec->size);
    long unsigned int * lsearch_nmemb = &(val);
    if(isSorted) {
        ret = bsearch(addr_data,_vector_nth(vec,0), nmemb_bsearch, vec->elem_size, compareFn);
    } else {
        ret = lfind(addr_data,_vector_nth(vec,0), lsearch_nmemb, vec->elem_size, compareFn);
    }

    return ret != NULL;
}

void vector_search(
    vector_t * vec, 
    void * addr_data, 
    void * return_data,
    int (*compareFn)(const void *, const void *),
    bool isSorted) 
{
    void * ret;
    size_t nmemb_bsearch = ((size_t)(vec->size));
    long unsigned int val = (long unsigned int)(vec->size);
    long unsigned int * lsearch_nmemb = &(val);
    if(isSorted) {
        ret = bsearch(addr_data,_vector_nth(vec,0), nmemb_bsearch, vec->elem_size, compareFn);
    } else {
        ret = lfind(addr_data,_vector_nth(vec,0), lsearch_nmemb, vec->elem_size, compareFn);
    }

    if(ret != NULL) {
        memcpy(return_data, ret, vec->elem_size);
    }
}

/* testing */
#pragma region testing
// int main() {
//     vector_t * vec = malloc(sizeof(vector_t));
//     vector_init( vec, sizeof(int), NULL, NULL);
//     for(int i = 0; i < 100; i++)
//         vector_push_back(vec, &i);

//     for(int i = 0; i < 1000; i++)
//         vector_insert(vec, &i, i);

//     for(int i = 0; i < 500; i++)
//         vector_remove(vec, &i, i);

//     while(!vec_isEmpty(vec)){
//         int val;
//         vector_pop_back(vec, &val);
//         printf("%i ,", val);
//     }

//     vector_dispose(vec);
//     free(vec);
//     return 0;
// }
#pragma endregion testing