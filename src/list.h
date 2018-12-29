#ifndef __LIST_H__
#define __LIST_H__

#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "default_types.h"

typedef struct _list_elem_t{
    void * data;
    struct _list_elem_t * next;
    struct _list_elem_t * prev;
} _list_elem_t;

typedef struct list_t {
    _list_elem_t * start;
    _list_elem_t * end;
    int elem_size;
    int size;
    void (*freeFn)(void *);
    void (*mapFn)(void *, void *);
} list_t;

void _list_dispose_util(list_t * ls,_list_elem_t * elem);

void _list_remove_node(list_t * ls, _list_elem_t * existing_node);

void _list_add_node_at(list_t * ls, 
                        _list_elem_t * existing_node,
                      _list_elem_t * new_node);

void list_init(list_t * ls, int elem_size, void (*freeFn), void (*mapFn));

void list_dispose(list_t * ls);

void list_push_front(list_t * ls, void * addr_data);

void list_pop_front(list_t * ls, void * addr_data);

void list_push_back(list_t * ls, void * addr_data);

void list_pop_back(list_t * ls, void * addr_data);

void list_peek_back(list_t * ls, void * addr_data);

void list_peek_front(list_t * ls, void * addr_data);

bool list_isEmpty(list_t * ls);

#endif