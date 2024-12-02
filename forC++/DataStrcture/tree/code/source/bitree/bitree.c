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

// 非递归先序，中序，后序遍历
#if 0
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
            // 1. 遍历根节点时，右子节点非空时将右子节点入栈
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
#else
void bitree_preorder_stack(bitree *root)
{
    if (NULL == root)
        return;

    bitree *t = root;
    linkstack_t *stack = linkstack_create();

    while (t || !linkstack_isEmpty(stack))  // 若左右节点都为空且栈为空，则退出循环
    {
        // 1. 从根节点开始，凡是左子节点直接入栈（有左子树时）
        if (t)
        {
            printf("%c, ", t->data);    // 入栈前访问，先序遍历
            linkstack_push(stack, t);
            t = t->left;
        }
        else
        {
            // 2. 否则查栈顶，将栈顶出栈，当栈顶节点有右子树时，将其右子节点入栈并以右子树为新的根节点（只有右子树时）
            t = linkstack_pop(stack);
            if (t->right) 
                t = t->right;
            else    // 3. 当没有节点可以入栈时，将栈顶出栈，将其右子节点入栈并以右子树为新的根节点（只有叶子时）
            {
                if (!linkstack_isEmpty(stack)) 
                {
                    t = linkstack_pop(stack);
                }
                if (t) 
                    t = t->right;
            }
        }     
    }

    linkstack_free(stack);
}
#endif

#if 0
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
#else
void bitree_inorder_stack(bitree *root)
{
    if (NULL == root)
        return;

    bitree *t = root;
    linkstack_t *stack = linkstack_create();

    while (t || !linkstack_isEmpty(stack))  // 若左右节点都为空且栈为空，则退出循环
    {
        // 1. 从根节点开始，凡是左子节点直接入栈（有左子树时）
        if (t)
        {
            linkstack_push(stack, t);
            t = t->left;
        }
        else
        {
            // 2. 否则查栈顶，将栈顶出栈（因为左子树已经处理完了），当栈顶节点有右子树时，将其右子节点入栈并以右子树为新的根节点（只有右子树时）
            t = linkstack_pop(stack);
            printf("%c, ", t->data);    // 出栈时访问，中序遍历
            if (t->right) 
                t = t->right;
            else    // 3. 当没有节点可以入栈时，将栈顶出栈，将其右子节点入栈并以右子树为新的根节点（只有叶子时）
            {
                if (!linkstack_isEmpty(stack)) 
                {
                    t = linkstack_pop(stack);
                    printf("%c, ", t->data);    // 出栈时访问，中序遍历
                }
                if (t) 
                    t = t->right;
            }
        }     
    }

    linkstack_free(stack);
}
#endif

#if 0
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
#else
void bitree_postorder_stack(bitree *root)
{
    if (NULL == root)
        return;

    bitree *t = root;       // 当前处理节点
    bitree *last = NULL;    // 上一次处理的节点
    linkstack_t *stack = linkstack_create();

    while (t || !linkstack_isEmpty(stack))  // 若左右节点都为空且栈为空，则退出循环
    {
        // 1. （有左子树时）左子节点入栈
        if (t)
        {
            linkstack_push(stack, t);
            t = t->left;
        }
        else    // top没有左子树
        {
            bitree *top = linkstack_getTop(stack);
            // 2. 若当前节点右子树存在且未访问（上一次节点不是当前节点右子树），遍历右子树
            // 3. 若上一次节点是当前节点右子树，右子树遍历完，出栈
            // 4. 若上一次节点是当前节点左子树（不考虑），且当前节点没有右子树，出栈
            // 5. 若当前节点没有左右子树，出栈
            if (!(top->right) || (last == top->right)) 
            {
                printf("%c, ", top->data);    // 出栈时访问，后序遍历
                last = linkstack_pop(stack);
            }
            // 2. 右子树遍历条件：右子树存在且未访问
            // else if (top->right && last != top->right)  
            else
            {
                t = top->right;
            }
        }   
    }

    linkstack_free(stack);
}
#endif

#if 0
void bitree_postorder_stack(bitree *root)
{
    if (root == NULL)
        return;

    bitree *t = root;       // 当前处理节点
    bitree *last = NULL;    // 上一次处理的节点
    linkstack_t *stack = linkstack_create();

    while (t || !linkstack_isEmpty(stack))  // 若当前节点非空或栈非空，则继续循环
    {
        // 1. 左子树遍历，持续压栈
        if (t) 
        {
            linkstack_push(stack, t);
            t = t->left;
        }
        else
        {
            bitree *top = linkstack_getTop(stack);

            // 2. 右子树遍历条件：右子树存在且未访问
            if (top->right && last != top->right) 
            {
                t = top->right;
            }
            else
            {
                // 3. 访问当前节点，并弹出栈顶元素
                printf("%c, ", top->data);
                last = linkstack_pop(stack);
            }
        }
    }

    linkstack_free(stack);
}
#endif

// 其他方法：

// 1. 用2个while的方法

// void backOrderNRec(Tree root){
 
// 	Node *p = root;
// 	Node *stack[MAXSIZE];
// 	int num = 0;
// 	Node *have_visited = NULL;
 
// 	while (NULL != p || num>0)
// 	{
// 		while (NULL != p)
// 		{
// 			stack[num++] = p;
// 			p = p->left;
// 		}
// 		p = stack[num - 1];
// 		if (NULL == p->right || have_visited == p->right)
// 		{
// 			printf(" %c - ", p->data);
// 			num--;
// 			have_visited = p;
// 			p = NULL;
// 		}
// 		else
// 		{
// 			p = p->right;
// 		}
// 	}
	
// }

// 2. 将根右左，反转数组为左右根
 
// void backOrderNRecSimple(Tree root){
// 	Tree stack[MAXSIZE], node;
// 	int top = 0;
// 	int count = 0;
// 	char array[MAXSIZE]; // 使用一个数组来保存数据，方便最后数组的反转
 
// 	if (root == NULL){
// 		printf("tree is empty-- \n");
// 		return;
// 	}
// 	else{
// 		top++;
// 		// 仿照一个栈
// 		stack[top] = root; // 将根节点入栈
// 		while (top > 0){
// 			//出栈
// 			node = stack[top--];
// 			array[count++] = node->data; // 将其保存在一个数组当中
 
// 			// 先把右子树放进去，栈是先进去后出，所以下面的左子树先出
// 			if (node->left != NULL){
// 				stack[++top] = node->left;  // 入栈
// 			}
// 			if (node->right != NULL){
// 				stack[++top] = node->right;
// 			}
 
// 		}
 
// 	}
// 	// 反转数组，输出
// 	for (int i = count-1; i >= 0; i--){
// 		printf(" %c - ", array[i]);
// 	}
 
// }

// 回调函数统一接口
void bitree_travel(const char * str, void (*pfunc)(bitree*), bitree* root)
{
    printf("%s: \t", str);
    pfunc(root);
    puts("");
}
