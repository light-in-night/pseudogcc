
#ifndef __DEFAULT_TYPES_H__
#define __DEFAULT_TYPES_H__

#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef int bool;
enum {false, true};

typedef void (*freeFn)(void *);
typedef void (*mapFn)(void *,void*);
typedef int (*compareFn)(const void *, const void *);

#endif