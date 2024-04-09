#include "sequeue.h"

sequeue* sequeue_create()
{
    //request memory
    sequeue* queue = (sequeue*)malloc(sizeof(sequeue));
    data_t* data = (data_t*)malloc(N * sizeof(data_t));
    if (NULL == queue || NULL == data)
    {
        printf("malloc failed\n");
        return queue;
    }

    //initialize
    memset(data, 0, N * sizeof(data_t));
    queue->data = data;
    queue->front = 0;
    queue->rear = 0;

    return queue;
}

int sequeue_clean(sequeue *queue)
{
    //check null
    if (NULL == queue)
    {
        printf("invalid queue\n");
        return -1;
    }

    //clean
    memset(queue->data, 0, N * sizeof(data_t));
    queue->front = 0;
    queue->rear = 0;

    return 0;
}

sequeue* sequeue_free(sequeue *queue)
{
    //check null
    if (NULL == queue)
    {
        printf("invalid queue\n");
        return queue;
    }

    //free
    free(queue->data);
    queue->data = NULL;
    free(queue);
    queue = NULL;

    return queue;
}

bool sequeue_isEmpty(sequeue *queue)
{
    //check null
    if (NULL == queue)
    {
        printf("invalid queue\n");
        return false;
    }

    if (queue->front == queue->rear)
    {
        return true;
    }
    return false;
}

bool sequeue_isFull(sequeue *queue)
{
    //check null
    if (NULL == queue)
    {
        printf("invalid queue\n");
        return false;
    }

    if (queue->front == (queue->rear + 1) % N)
    {
        return true;
    }
    return false;
}

int sequeue_enqueue(sequeue *queue, data_t data)
{
    //check null
    if (NULL == queue)
    {
        printf("invalid queue\n");
        return -1;
    }

    //check full
    if (sequeue_isFull(queue))
    {
        printf("queue is full\n");
        return -2;
    }
    
    //enqueue
    queue->data[queue->rear] = data;
    queue->rear = (queue->rear + 1) % N;

    return 0;
}

data_t sequeue_dequeue(sequeue *queue)
{
    //check null
    if (NULL == queue)
    {
        printf("invalid queue\n");
        return -1;
    }

    //check full
    if (sequeue_isEmpty(queue))
    {
        printf("queue is empty\n");
        return -2;
    }
    
    //dequeue
    data_t temp;
    temp = queue->data[queue->front];
    queue->front = (queue->front + 1) % N;

    return temp;
}

void sequeue_show(sequeue *queue)
{
    //check null
    if (NULL == queue)
    {
        printf("invalid queue\n");
        return;
    }

    printf("< ");
    int pos = queue->front;
    while (pos < queue->rear)
    {
        printf("%d, ", queue->data[pos]);
        pos++;
    }
    printf("<\n");

    printf("-----------------");
    for (int i = 0; i < N; i++)
    {
        printf("\n%d\t%d\t", i, queue->data[i]);
        if (queue->front == i)
        {
            printf("<---front");
        }
        if (queue->rear == i)
        {
            printf("<---rear");
        }
    }
    printf("\n-----------------\n"); 
}
