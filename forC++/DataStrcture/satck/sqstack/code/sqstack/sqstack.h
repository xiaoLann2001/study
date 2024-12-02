#ifndef __SQSTACK_H_
#define __SQSTACK_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef int data_t;

typedef struct sqstack{
    //pointer to data field
    data_t* data;
    //stack's max length
    int maxlen;
    //point to stack's top
    int top;
}sqstack;

/**
 * @brief   create a sqstack and init
 * @param   len -length of stack that will be create
 * @return  pointer of new stack's bottom
 * */
sqstack* sqstack_create(int len);

bool sqstack_isFull(sqstack* stack);

bool sqstack_isEmpty(sqstack* stack);

/**
 * @brief   push a data to stack's top
 * @param   stack -the data structure being manipulated
 * @param   data -data will be push
 * @return  0 -run successfully
 *          1 -run failed
 * */
int sqstack_push(sqstack* stack, data_t data);

/**
 * @brief   pop a data from stack's top
 * @param   stack -the data structure being manipulated
 * @param   data -data will be pop to space of this pointer
 * @return  0 -run successfully
 *          1 -run failed
 * */
int sqstack_pop(sqstack* stack, data_t* data);

data_t sqstack_getTop(sqstack* stack);

int sqstack_clear(sqstack* stack);

int sqstack_free(sqstack* stack);

void sqstack_show(sqstack* stack);


#endif
