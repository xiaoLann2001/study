#ifndef __LINKSTACK_H_
#define __LINKSTACK_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "bitree.h"

typedef bitree* data_t;

typedef struct stack_node_t{
    //data field
    data_t data;
    //pointer field
    struct stack_node_t *next;
}linkstack_t;

linkstack_t *linkstack_create();
bool linkstack_isEmpty(linkstack_t * stack);
int linkstack_push(linkstack_t * stack, data_t data);
data_t linkstack_pop(linkstack_t * stack);
data_t linkstack_getTop(linkstack_t * stack);
int linkstack_free(linkstack_t * stack);
void linkstack_show(linkstack_t * stack);


#endif
