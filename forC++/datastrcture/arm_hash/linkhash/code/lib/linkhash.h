#ifndef __LINKHASH_H__
#define __LINKHASH_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define N 20    // p = 19
#define P 19

typedef char* data_t;

typedef struct node_t{
    int key;
    data_t value;
    struct node_t *next;
}linknode;

typedef struct linkhash_t{
    linknode headArray[N];
}linkhash;

linkhash* linkhash_create();
linkhash* linkhash_free(linkhash*);
int linkhash_insert(linkhash* table, int key, data_t value);
data_t linkhash_search(linkhash* table, int key);
void linkhash_show(linkhash* table);


#endif