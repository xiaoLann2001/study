#include <stdio.h>
#include "linkhash.h"

int main()
{
    linkhash* table;
    if ((table = linkhash_create()) == NULL)
    {
        exit(-1);
    }

    // 插入数据
    char str[10];
    for (int i = 0; i < 21; i++)
    {
        sprintf(str, "value%d", i);
        linkhash_insert(table, i*i, strdup(str));
    }

    linkhash_show(table);

    printf("Key: %d, Value: %s\n", 25, linkhash_search(table, 25));
    printf("Key: %d, Value: %s\n", 26, linkhash_search(table, 26));
    printf("Key: %d, Value: %s\n", 400, linkhash_search(table, 400));


    table = linkhash_free(table);
    printf("%p\n", table);

    return 0;
}