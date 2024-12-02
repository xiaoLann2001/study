#include "linkstack.h"

linkstack_t *linkstack_create()
{
    //request memory
    linkstack_t * stack = (linkstack_t*)malloc(sizeof(linkstack_t));
    if (NULL == stack)
    {
        printf("malloc failed\n");
        return stack;
    }

    //initialize
    stack->data = 0;
    stack->next = NULL;

    return stack;
}

bool linkstack_isEmpty(linkstack_t * stack)
{
    //check null
    if (NULL == stack)
    {
        printf("invalid stack\n");
        return false;
    }
    
    //check empty
    if (NULL == stack->next)
    {
        return true;
    }
    return false;
}

int linkstack_push(linkstack_t * stack, data_t data)
{
    //check null
    if (NULL == stack)
    {
        printf("invalid stack\n");
        return -1;
    }

    //push a node (head insert)
    linkstack_t * node = linkstack_create();
    if (NULL == node)
    {
        return -1;
    }
    node->data = data;
    node->next = stack->next;
    stack->next = node;

    return 0;
}

data_t linkstack_pop(linkstack_t * stack)
{
    //check null
    if (NULL == stack)
    {
        printf("invalid stack\n");
        return NULL;
    }

    //check empty
    if (linkstack_isEmpty(stack))
    {
        printf("empty stack\n");
        return NULL;
    } 

    //delete node
    data_t temp = stack->next->data;
    linkstack_t * p = stack->next;
    stack->next = stack->next->next;

    free(p);
    return temp;
}

data_t linkstack_getTop(linkstack_t * stack)
{
    //check null
    if (NULL == stack)
    {
        printf("invalid stack\n");
        return NULL;
    }

    //check empty
    if (linkstack_isEmpty(stack))
    {
        printf("empty stack\n");
        return NULL;
    } 

    //return
    return stack->next->data;
}

int linkstack_free(linkstack_t * stack)
{
    //check null
    if (NULL == stack)
    {
        printf("invalid stack\n");
        return -1;
    }

    //free
    linkstack_t * p = stack;
    while (NULL != p)
    {
        linkstack_t * temp = p;
        p = p->next;
        free(temp);
    }
    
    return 0;
}

void linkstack_show(linkstack_t * stack)
{
    //check null
    if (NULL == stack)
    {
        printf("invalid stack\n");
        return;
    }

    //show
    linkstack_t * p = stack;
    int i = -1;
    while (NULL != p)
    {
        // 可以尝试使用回调函数自定义打印
        // printf("%d\t| %d\t| %p\n", i, p->data, p->next);
        p = p->next;
        i++;
    }
}

