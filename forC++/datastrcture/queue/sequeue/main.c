#include "sequeue.h"

int main(int argc, char *argv[])
{
    sequeue *Q = sequeue_create();
    if (NULL == Q)
    {
        return -1;
    }

    for (int i = 0; i < 9; i++)
    {
        if (sequeue_enqueue(Q, i + 5) < 0)
        {
            printf("enqueue failed\n");
        }
    }
    sequeue_show(Q);

    for (int i = 0; i < 12; i++)
    {
        if (sequeue_dequeue(Q) < 0)
        {
            printf("dequeue failed\n");
        }
    }
    sequeue_show(Q);
    
    if (sequeue_clean(Q) < 0)
    {
        printf("clean failed\n");
    }

    Q = sequeue_free(Q);

    if (sequeue_clean(Q) < 0)
    {
        printf("clean failed\n");
    }
    
    return 0;
}