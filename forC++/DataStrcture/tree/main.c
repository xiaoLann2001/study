#include "bitree.h"

int main()
{
    bitree* tree;
    tree = bitree_create();

    // input: AB#CD###EFG##H##I##
    // input: ABD#H##E#KG###C#F##

    bitree_travel("bitree_preorder", bitree_preorder, tree);
    bitree_travel("bitree_inorder", bitree_inorder, tree);
    bitree_travel("bitree_postorder", bitree_postorder, tree);
    bitree_travel("bitree_hierarchy", bitree_hierarchy, tree);
    bitree_travel("bitree_preorder_stack", bitree_preorder_stack, tree);
    bitree_travel("bitree_inorder_stack", bitree_inorder_stack, tree);
    bitree_travel("bitree_postorder_stack", bitree_postorder_stack, tree);

    return 0;
}