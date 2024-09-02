#include "bitree.h"
#include "linkqueue.h"
#include "linkstack.h"

bitree *bitree_create()
{
    bitree *root;
    tdata_t ch;

    scanf("%c", &ch);
    if ('#' == ch)
    {
        return NULL;
    }

    if ((root = (bitree *)malloc(sizeof(bitree))) == NULL)
    {
        printf("malloc failed\n");
        return root;
    }

    root->data = ch;
    root->left = bitree_create();
    root->right = bitree_create();

    return root;
}

// 递归先序，中序，后序遍历
void bitree_preorder(bitree *root)
{
    if (NULL == root)
        return;
    printf("%c, ", root->data);
    bitree_preorder(root->left);
    bitree_preorder(root->right);
}

void bitree_inorder(bitree *root)
{
    if (NULL == root)
        return;
    bitree_inorder(root->left);
    printf("%c, ", root->data);
    bitree_inorder(root->right);
}

void bitree_postorder(bitree *root)
{
    if (NULL == root)
        return;
    bitree_postorder(root->left);
    bitree_postorder(root->right);
    printf("%c, ", root->data);
}

// 层次遍历
void bitree_hierarchy(bitree *root)
{
    if (NULL == root)
        return;

    bitree *ret = NULL;
    linkqueue *queue = linkqueue_create();

    linkqueue_enqueue(queue, root);

    while (!linkqueue_isEmpty(queue))
    {
        ret = linkqueue_dequeue(queue);
        printf("%c, ", ret->data);

        if (ret->left != NULL)
            linkqueue_enqueue(queue, ret->left);
        if (ret->right != NULL)
            linkqueue_enqueue(queue, ret->right);
    }

    queue = linkqueue_free(queue);
}

// 栈先序，中序，后序遍历
void bitree_preorder_stack(bitree *root)
{
    if (NULL == root)
        return;

    bitree *t = root;
    linkstack_t *stack = linkstack_create();

    // 若左右节点都为空且栈为空，则退出循环
    while (t || !linkstack_isEmpty(stack)) 
    {
        if (t)
        {
            // 1. 遍历根节点时，右子节点非空时将右子节点保存
            printf("%c, ", t->data);
            if (t->right)
                linkstack_push(stack, t->right);

            // 2. 转1遍历左子树
            t = t->left;
        }
        else    // 3. 当根节点为空时，取出右子节点的地址，转1遍历右子树
        {
            if (!linkstack_isEmpty(stack))
                t = linkstack_pop(stack);
            else
                t = NULL;
        }
    }
}

void bitree_inorder_stack(bitree *root)
{
    if (NULL == root)
        return;

    bitree *t = root;
    linkstack_t *stack = linkstack_create();

    // 若左右节点都为空且栈为空，则退出循环
    while (t || !linkstack_isEmpty(stack)) 
    {
        if (t)
        {
            // 1. 若根非空，根节点入栈
            linkstack_push(stack, t);

            // 2. 转1，遍历左子树
            t = t->left;
        }
        else
        {
            // 3. 当根节点为空时，出栈根节点并访问，转1，遍历右子树
            t = linkstack_pop(stack);
            printf("%c, ", t->data);
            t = t->right;
        }
    }
}

void bitree_postorder_stack(bitree *root)
{
    if (NULL == root)
        return;

    bitree *t = root;
    linkstack_t *stack = linkstack_create();

    // 若左右节点都为空且栈为空，则退出循环
    while (t || !linkstack_isEmpty(stack)) 
    {
        if (t)
        {
            // 1. 若根非空，根节点入栈
            linkstack_push(stack, t);

            // 2. 转1，遍历左子树
            t = t->left;
        }
        else
        {
            // 3. 当根节点为空时，出栈根节点并访问其，转1，遍历右子树
            t = linkstack_pop(stack);
            t = t->right;
        }
    }
}
