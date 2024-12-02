#include "sqstack.h"

int main(int argc, char *argv[])
{
    sqstack* S = sqstack_create(100);
    if (NULL == S)
    {
        return -1;
    }
    
    for (int i = 0; i < 7; i++)
    {
        if (-1 == sqstack_push(S, i + 5))
            printf("push failed\n");
    }
    sqstack_show(S);

    data_t temp;
    for (int i = 0; i < 1; i++)
    {
        if (-1 == sqstack_pop(S, &temp))
            printf("pop failed\n");
    }
    sqstack_show(S);

    printf("top: %d\n", sqstack_getTop(S));
    printf("top: %d\n", sqstack_getTop(S));
    
    if (-1 == sqstack_clear(S))
        printf("clear failed\n");
    sqstack_show(S);

    if (-1 == sqstack_free(S))
        printf("free failed\n");
    return 0;
}