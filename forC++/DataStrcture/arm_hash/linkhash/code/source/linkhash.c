#include "linkhash.h"

linkhash* linkhash_create()
{
    // request memory
    linkhash *table;
    if ((table = (linkhash*)malloc(sizeof(linkhash))) == NULL)
    {
        printf("malloc failed\n");
        return table;  
    }

    // initialization
    memset(table, 0, sizeof(linkhash));
    for (int i = 0; i < N; i++)
    {
        table->headArray[i].next = NULL;
    }

    return table;
}

linkhash* linkhash_free(linkhash* table)
{
    // check vaild parameter
    if (NULL == table)
    {
        printf("error hashtable\n");
        return table;
    }

    // free linknode
    for (int i = 0; i < N; i++)
    {
        linknode *p;
        linknode *tmp;
        p = table->headArray[i].next;
        while (NULL != p)
        {
            tmp = p;
            p = p->next;
            free(tmp);
        }
    }

    // free table
    free(table);

    return NULL;
}

int linkhash_insert(linkhash* table, int key, data_t value)
{
    // check vaild parameter
    if (NULL == table)
    {
        printf("error hashtable\n");
        return -1;
    }

    // create a linknode
    linknode *node;
    if ((node = (linknode*)malloc(sizeof(linknode))) == NULL)
    {
        printf("malloc failed\n");
        return -1;
    }

    // initialization
    node->key = key;
    node->value = node->value = malloc(strlen(value) + 1);  // request memory
    strcpy(node->value, value);         // because the first param of strcpy()
                                        // cannot be 0x0
    // node->next = NULL;
    
    // hash map
    int index;
    index = key % P;

    // head insert
    // node->next = table->headArray[index].next;
    // table->headArray[index].next = node;

    // insert by order
    linknode* p;
    p = &(table->headArray[index]);
    // find the prev of the node will be inserted
    while ((NULL != p->next) && (p->next->key < node->key))
    {
        p = p->next;
    }

    node->next = p->next;
    p->next = node;
    
    return 0;
}

data_t linkhash_search(linkhash* table, int key)
{
    // check valid parameter
    if (NULL == table)
    {
        printf("error hashtable\n");
        return "";
    }
    
    // hash map
    int index;
    index = key % P;

    // search
    linknode *p;
    p = table->headArray[index].next;
    while (NULL != p)
    {
        if (key == p->key) return p->value;
        p = p->next;
    }
    
    return "not found";
}

void linkhash_show(linkhash* table)
{
    // check valid parameter
    if (NULL == table)
    {
        printf("error hashtable\n");
        return;
    }

    for (int i = 0; i < N; i++)
    {
        printf("|%d|%p|--->", i, table->headArray[i].next);

        linknode *p;
        p = table->headArray[i].next;

        while (NULL != p)
        {
            printf("|key:%d value:'%s'|%p|--->", p->key, p->value, p->next);
            p = p->next;
        }

        puts("");
    }
}
