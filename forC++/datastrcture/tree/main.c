#include "bitree.h"

int main()
{
    bitree* tree;
    tree = bitree_create();

    // input: AB#CD###EFG##H##I##
    // input: ABD#H##E#KG###C#F##

    printf("bitree_preorder: \t\t");
    bitree_preorder(tree);
    puts("");

    printf("bitree_inorder: \t\t");
    bitree_inorder(tree);
    puts("");
    
    printf("bitree_postorder: \t\t");
    bitree_postorder(tree);
    puts("");

    printf("bitree_hierarchy: \t\t");
    bitree_hierarchy(tree);
    puts("");

    printf("bitree_preorder_stack: \t\t");
    bitree_preorder_stack(tree);
    puts("");

    printf("bitree_inorder_stack: \t\t");
    bitree_inorder_stack(tree);
    puts("");

    printf("bitree_postorder_stack: \t");
    bitree_postorder_stack(tree);
    puts("");

    return 0;
}