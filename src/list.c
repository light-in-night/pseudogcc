#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "list.h"

void _list_dispose_util(list_t * ls,_list_elem_t * elem) {
    if(elem == NULL) return;

    _list_dispose_util(ls, elem->next);
    free(elem);
    if(ls->freeFn != NULL) 
        ls->freeFn(elem->data);
}

void _list_remove_node(list_t * ls, _list_elem_t * existing_node) 
{
    existing_node->next->prev = existing_node->prev;
    existing_node->prev->next = existing_node->next;
    free(existing_node->data);
    free(existing_node);
    ls->size--;
}

void _list_add_node_at
(list_t * ls, 
_list_elem_t * existing_node,
_list_elem_t * new_node
) {
    new_node->next = existing_node->next;
    new_node->prev = existing_node;

    existing_node->next->prev = new_node;
    existing_node->next = new_node;

    ls->size++;  
}

void list_init(list_t * ls, int elem_size, void (*freeFn), void (*mapFn)) {
    ls->start = malloc(sizeof(_list_elem_t));
    ls->end = malloc(sizeof(_list_elem_t));

    ls->start->next = ls->end;
    ls->start->prev = NULL;
    ls->end->next = NULL;
    ls->end->prev = ls->start;

    ls->elem_size =elem_size;
    ls->size = 0;
    ls->freeFn = freeFn;
    ls->mapFn = mapFn;
}

void list_dispose(list_t * ls) {
    _list_dispose_util(ls, ls->start);
}

void list_push_front(list_t * ls, void * addr_data) {
    _list_elem_t * node = malloc(sizeof(_list_elem_t));
    node->data = malloc(ls->elem_size);

    memcpy(node->data, addr_data, ls->elem_size);
    _list_add_node_at(ls, ls->start, node);
}

void list_pop_front(list_t * ls, void * addr_data) {
    assert(!list_isEmpty(ls));

    memcpy(addr_data, ls->start->next->data, ls->elem_size);
    _list_remove_node(ls,ls->start->next);
}

void list_push_back(list_t * ls, void * addr_data) {
    _list_elem_t * node = malloc(sizeof(_list_elem_t));
    node->data = malloc(ls->elem_size);

    memcpy(node->data, addr_data, ls->elem_size);
    _list_add_node_at(ls, ls->end->prev, node);
}

void list_pop_back(list_t * ls, void * addr_data) {
    assert(!list_isEmpty(ls));

    memcpy(addr_data, ls->end->prev->data, ls->elem_size);
    _list_remove_node(ls,ls->end->prev);
}

void list_peek_front(list_t * ls, void * addr_data) {
    assert(!list_isEmpty(ls));
    memcpy(addr_data, ls->start->next->data, ls->elem_size);
}

void list_peek_back(list_t * ls, void * addr_data) {
    assert(!list_isEmpty(ls));
    memcpy(addr_data, ls->end->prev->data, ls->elem_size);
}

bool list_isEmpty(list_t * ls) {
    return ls->size == 0;
}

