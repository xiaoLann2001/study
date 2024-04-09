#include "bitree.h"

int main()
{
    bitree* tree;
    tree = bitree_create();

    // input: AB#CD###EFG##H##I##

    bitree_preorder(tree);
    puts("");

    bitree_inorder(tree);
    puts("");

    bitree_postorder(tree);
    puts("");

    bitree_hierarchy(tree);
    puts("");

    return 0;
}