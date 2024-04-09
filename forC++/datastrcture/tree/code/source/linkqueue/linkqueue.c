#include "linkqueue.h"

linkqueue* linkqueue_create()
{
    //request memory
    linkqueue* queue = (linkqueue*)malloc(sizeof(linkqueue));
    listnode* head = (listnode*)malloc(sizeof(listnode));
    if (NULL == queue || NULL == head)
    {
        printf("malloc failed\n");
        return queue;
    }

    //initialize
    head->data = NULL;
    head->next = NULL;
    queue->front = head;
    queue->rear = head;

    return queue;
}

linkqueue* linkqueue_free(linkqueue* queue)
{
    //check null
    if (NULL == queue)
    {
        printf("invalid queue\n");
        return queue;
    }

    listnode* p;
    p = queue->front;
    while (NULL != p)
    {
        listnode* temp;
        temp = p;
        p = p->next;
        free(temp);
    }

    free(queue);

    return NULL;
}

bool linkqueue_isEmpty(linkqueue* queue)
{
    //check null
    if (NULL == queue)
    {
        printf("invalid queue\n");
        return false;
    }

    return (queue->front == queue->rear) ? true : false;
}

int linkqueue_enqueue(linkqueue* queue, data_t data)
{
    //check null
    if (NULL == queue)
    {
        printf("invalid queue\n");
        return -1;
    }

    //create a new node
    listnode* node = (listnode*)malloc(sizeof(listnode));
    node->data = data;
    node->next = NULL;

    //enqueue
    queue->rear->next = node;
    queue->rear = node;

    return 0;
}

data_t linkqueue_dequeue(linkqueue* queue)
{
    //check null
    if (NULL == queue)
    {
        printf("invalid queue\n");
        return -1;
    }

    //check empty
    if (linkqueue_isEmpty(queue))
    {
        printf("queue is empty\n");
        return -2;
    }  

    //dequeue
    data_t temp;
    listnode *p;
    temp = queue->front->next->data;
    p = queue->front->next;
    if (queue->front->next == queue->rear)
    {
        queue->rear = queue->front;
    }
    queue->front->next = queue->front->next->next;

    free(p);

    return temp;
}

// void linkqueue_show(linkqueue* queue)
// {
//     //check null
//     if (NULL == queue)
//     {
//         printf("invalid queue\n");
//         return;
//     }

//     printf("< ");
//     listnode* p;
//     p = queue->front->next;
//     while (NULL != p)
//     {
//         printf("%d, ", p->data);
//         p = p->next;
//     }
//     printf("<\n");

//     printf("------------------------------");
//     p = queue->front;
//     int i = -1;
//     while (NULL != p)
//     {
//         printf("\n%d\t| %d\t| %p", i, p->data, p);
//         p = p->next;
//         i++;
//     }
//     printf("\n------------------------------\n");
// }

