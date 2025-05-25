#include <bits/stdc++.h>

using namespace std;

#define null (-2147483648)

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};

/**
 * @brief 层次构造二叉树
 * @param p_vals-按层次顺序排列的数组指针，数组的值为NULL_FLAG时表示空
 * @return 按层次顺序构造的二叉树的根节点
*/
TreeNode *tree_build_level(vector<int>* p_vals)
{
    if (0 == p_vals->size()) return NULL;

    TreeNode *root = new TreeNode((*p_vals)[0]);
    queue<TreeNode*> queue;

    queue.push(root);

    int i = 1;
    TreeNode *temp_root;
    while (i < p_vals->size()) {
        temp_root = queue.front();
        queue.pop();
        if (null == (*p_vals)[i]) {
            temp_root->left = NULL;
        } else {
            temp_root->left = new TreeNode((*p_vals)[i]);
            queue.push(temp_root->left);
        }
        i++;
        if (i >= p_vals->size()) break;
        if (null == (*p_vals)[i]) {
            temp_root->right = NULL;
        } else {
            temp_root->right = new TreeNode((*p_vals)[i]);
            queue.push(temp_root->right);
        }
        i++;
    }

    return root;
}

/**
 * @brief 层次遍历二叉树并打印输出
 * @param root-二叉树根节点指针
*/
void tree_traversal_level(TreeNode *root)
{
    if (NULL == root)
        return;

    TreeNode *ret = NULL;
    queue<TreeNode*> queue;

    queue.push(root);

    while (!queue.empty())
    {
        ret = queue.front();
        queue.pop();
        cout << ret->val << ", ";

        if (ret->left != NULL)
            queue.push(ret->left);
        if (ret->right != NULL)
            queue.push(ret->right);
    }
    cout << endl;
}

class Solution {
public:
    TreeNode* Convert(TreeNode* pRootOfTree) {
        // 空树
        if (!pRootOfTree)
            return NULL;

        // 目标链表的头指针
        TreeNode* prev = NULL;
        TreeNode* head = NULL;

        // 中序遍历
        inorder(pRootOfTree, &prev, &head);

        return head;
    }

    void inorder(TreeNode* pRootOfTree, TreeNode** prev, TreeNode** head) {
        // 空节点
        if (!pRootOfTree)
            return;

        // 先遍历左子树
        inorder(pRootOfTree->left, prev, head);
        
        // 将当前节点连接到链表尾部
        if (!*prev) {  // 头节点
            *head = pRootOfTree;
            pRootOfTree->left = NULL;
        } else {
            (*prev)->right = pRootOfTree;
            pRootOfTree->left = *prev;
        }
        // prev = &pRootOfTree;   // 更新链表尾节点指针    (这里只修改了局部变量)
        *prev = pRootOfTree;   // 更新链表尾节点指针

        // 再遍历右子树
        inorder(pRootOfTree->right, prev, head);
    }
};

void printList(TreeNode* pList) {
    while (pList) {
        cout << pList->val << " -> ";
        pList = pList->right;
    }
    cout << endl;
}

int main() {
    Solution s;

    vector<int> treeArray = {10,6,14,4,8,12,16};

    TreeNode* t = tree_build_level(&treeArray);

    tree_traversal_level(t);

    TreeNode* ret = s.Convert(t);

    printList(ret);

    return 0;
}