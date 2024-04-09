#ifndef __LINKQUEUE_H_
#define __LINKQUEUE_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "bitree.h"

// typedef int data_t;
typedef bitree* data_t;

typedef struct node_t
{
    data_t data;
    struct node_t* next;
}listnode, *linklist;

typedef struct linkqueue_t
{
    listnode* front;
    listnode* rear;
}linkqueue;

/**
 * @brief   create a linkqueue and return pointer of it
 * @return  pointer of new linkqueue
 * */
linkqueue* linkqueue_create();
linkqueue* linkqueue_free(linkqueue* queue);
bool linkqueue_isEmpty(linkqueue* queue);
int linkqueue_enqueue(linkqueue* queue, data_t data);
data_t linkqueue_dequeue(linkqueue* queue);
// void linkqueue_show(linkqueue* queue);


#endif
