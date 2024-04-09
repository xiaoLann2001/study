#include "linkqueue.h"

int main(int argc, char *argv[])
{
    linkqueue* Q = linkqueue_create();
    if (NULL == Q)
    {
        return -1;
    }
    
    for (int i = 0; i < 9; i++)
    {
        if (linkqueue_enqueue(Q, i + 5) < 0)
        {
            printf("enqueue failed\n");
        }
    }
    linkqueue_show(Q);

    for (int i = 0; i < 8; i++)
    {
        if (linkqueue_dequeue(Q) < 0)
        {
            printf("dequeue failed\n");
        }
    }
    linkqueue_show(Q);

    Q = linkqueue_free(Q);
    
    return 0;
}