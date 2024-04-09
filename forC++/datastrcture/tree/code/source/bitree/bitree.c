#include "bitree.h"
#include "linkqueue.h"

bitree* bitree_create()
{
    bitree* root;
    tdata_t ch;

    scanf("%c", &ch);
    if ('#' == ch)
    {
        return NULL;
    }

    if ((root = (bitree*)malloc(sizeof(bitree))) == NULL)
    {
        printf("malloc failed\n");
        return root;
    }

    root->data = ch;
    root->left = bitree_create();
    root->right = bitree_create();
    
    return root;
}

void bitree_preorder(bitree* root)
{
    if (NULL == root) return;
    printf("%c, ", root->data);
    bitree_preorder(root->left);
    bitree_preorder(root->right);
}

void bitree_inorder(bitree* root)
{
    if (NULL == root) return;
    bitree_inorder(root->left);
    printf("%c, ", root->data);
    bitree_inorder(root->right);
}

void bitree_postorder(bitree* root)
{
    if (NULL == root) return;
    bitree_postorder(root->left);
    bitree_postorder(root->right);
    printf("%c, ", root->data);
}

void bitree_hierarchy(bitree* root)
{
    if (NULL == root) return;
    
    linkqueue *queue = linkqueue_create();
    
    linkqueue_enqueue(queue, root);

    while (!linkqueue_isEmpty(queue))
    {
        bitree* ret = linkqueue_dequeue(queue);
        printf("%c, ", ret->data);

        if (ret->left != NULL)
            linkqueue_enqueue(queue, ret->left);
        if (ret->right != NULL)
            linkqueue_enqueue(queue, ret->right);
    }

    queue = linkqueue_free(queue); 
}


