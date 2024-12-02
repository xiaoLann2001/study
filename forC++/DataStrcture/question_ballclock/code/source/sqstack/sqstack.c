#include "sqstack.h"

sqstack* sqstack_create(int len)
{
    //1.request memory
    sqstack* stack = (sqstack*)malloc(sizeof(data_t*) + 2 * sizeof(int));
    data_t* pdata = (data_t*)malloc(len * sizeof(data_t));
    if(NULL == stack || NULL == pdata)
    {
        printf("malloc failed\n");
        return stack;
    } 

    //2.initialize
    memset(pdata, 0, sizeof(len * sizeof(data_t)));
    stack->data = pdata;
    stack->maxlen = len;
    stack->top = -1;
    
    //3.return pointer
    return stack;
}

bool sqstack_isFull(sqstack* stack)
{
    if (NULL == stack)
    {
        printf("invalid stack\n");
        return false;
    }
    
    if (stack->top == (stack->maxlen - 1))
    {
        return true;
    }
    return false;
}

bool sqstack_isEmpty(sqstack* stack)
{
    if (NULL == stack)
    {
        printf("invalid stack\n");
        return false;
    }
    
    if (stack->top == -1)
    {
        return true;
    }
    return false;
}

int sqstack_push(sqstack* stack, data_t data)
{
    //1.check NULL
    if (NULL == stack)
    {
        printf("invalid stack\n");
        return -1;
    }

    //2.check full
    if (sqstack_isFull(stack))
    {
        printf("stack is full\n");
        return -1;
    }

    //3.top upgrade and push a data
    stack->top++;
    stack->data[stack->top] = data;

    return 0;
}

data_t sqstack_pop(sqstack* stack)
{
    //1.check NULL
    if (NULL == stack)
    {
        printf("invalid stack\n");
        return -1;
    }

    //2.check empty
    if (sqstack_isEmpty(stack))
    {
        printf("stack is empty\n");
        return -1;
    }

    //3.pop a data from top and upgrade
    data_t data = stack->data[stack->top];
    stack->top--;

    return data;
}

data_t sqstack_getTop(sqstack* stack)
{
    //1.check NULL
    if (NULL == stack)
    {
        printf("invalid stack\n");
        return 0;
    }

    //2.return
    return stack->data[stack->top];
}

int sqstack_clear(sqstack* stack)
{
    //1.check NULL
    if (NULL == stack)
    {
        printf("invalid stack\n");
        return -1;
    }

    //2.clear data
    memset(stack->data, 0, stack->maxlen * sizeof(data_t));
    stack->top = -1;

    return 0;
}

int sqstack_free(sqstack* stack)
{
    //1.check NULL
    if (NULL == stack)
    {
        printf("invalid stack\n");
        return -1;
    }

    //2.free data field
    free(stack->data);  //just free by frist pointer if request by malloc
    stack->data = NULL;

    free(stack);
    stack = NULL;
    return 0;
}

void sqstack_show(sqstack* stack)
{
    //1.check NULL
    if (NULL == stack)
    {
        printf("invalid stack\n");
        return;
    }
    
    //2.print stack
    printf("index\t| data\t\n");
    printf("-----bottom-----");
    int i = 0;
    while (i <= stack->top)
    {
        printf("\n%d\t| %d\t", i, stack->data[i]);
        i++;
    }
    printf("<---top\n");
    return;
}
