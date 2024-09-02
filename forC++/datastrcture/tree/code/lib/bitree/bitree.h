#ifndef __BITREE_H__
#define __BITREE_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef char tdata_t;

typedef struct tnode_t{
    tdata_t data;
    struct tnode_t *left;
    struct tnode_t *right;
}bitree;

bitree* bitree_create();
void bitree_preorder(bitree* root);
void bitree_inorder(bitree* root);
void bitree_postorder(bitree* root);
void bitree_hierarchy(bitree* root);

void bitree_preorder_stack(bitree* root);
void bitree_inorder_stack(bitree* root);
void bitree_postorder_stack(bitree* root);
#endif


