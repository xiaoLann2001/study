#include "linkstack.h"

int main()
{
    linkstack_t * S = linkstack_create();
    if (NULL == S)
    {
        return -1;
    }

    data_t data[] = {5, 6, 7, 8, -1};
    int i = 0;
    while (-1 != data[i])
    {
        linkstack_push(S, data[i]);
        i++;
    }
    linkstack_show(S);
    
    printf("top: %d\n", linkstack_getTop(S));

    linkstack_pop(S);
    linkstack_show(S);

    linkstack_free(S);
    return 0;
}