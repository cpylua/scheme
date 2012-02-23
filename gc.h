#ifndef _GC_H_
#define _GC_H_

#include "object.h"

typedef struct gc_heap {
    struct object *segments;
    int seg_total;    /* total number of segments */
    int seg_used;
} gc_heap;

typedef struct gc_segment {
    struct object *start;
    struct object *end;
} gc_segment;


typedef struct gc_list {
    int size;
    struct object head;
} gc_list;


int gc_init(int heap_size);
struct object* gc_alloc(void);
void gc(void);
void gc_finalize(void);
void dump_gc_summary(void);

void gc_stack_root_push(object **obj);
void gc_stack_root_pop();
#define gc_protect(obj) \
    gc_stack_root_push(&obj)
#define gc_abandon() \
    gc_stack_root_pop()

#endif

