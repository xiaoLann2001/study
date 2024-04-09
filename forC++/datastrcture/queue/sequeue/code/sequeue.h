#ifndef __SEQUEUE_H_
#define __SEQUEUE_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define N 10

typedef int data_t;

typedef struct{
    data_t *data;
    int front;
    int rear;
}sequeue;

/**
 * @brief   create a sequeue and return pointer of it
 * @return  pointer of new sequeue
 * */
sequeue* sequeue_create();
int sequeue_clean(sequeue *queue);
sequeue* sequeue_free(sequeue *queue);
bool sequeue_isEmpty(sequeue *queue);
bool sequeue_isFull(sequeue *queue);
int sequeue_enqueue(sequeue *queue, data_t data);
data_t sequeue_dequeue(sequeue *queue);
void sequeue_show(sequeue *queue);

#endif
