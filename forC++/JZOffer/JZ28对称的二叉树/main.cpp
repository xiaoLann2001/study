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
    bool isSymmetrical(TreeNode* pRoot) {
        if (NULL == pRoot)  // 规定根节点为空，对称
            return true;
        // 比较左右子树的前序遍历和对称前序遍历是否相等
        return traversal(pRoot->left, pRoot->right);
    }

    bool traversal(TreeNode* pRoot1, TreeNode* pRoot2) {
        // 若左右子树都为空，视为对称
        if (NULL == pRoot1)
            return pRoot1 == pRoot2;
        else if (NULL == pRoot2)
            return pRoot1 == pRoot2;
        
        bool ret = true;  
        // 都不为空，比较根节点的值
        ret &= pRoot1->val == pRoot2->val;
        
        // 递归遍历左右子树，若左右子树都对称，才视为对称
        ret &= traversal(pRoot1->left, pRoot2->right);
        ret &= traversal(pRoot1->right, pRoot2->left);
        return ret;
    }
};

int main() {
    Solution s;

    vector<int> vals1 = {8,6,6,5,7,7,5};   // NULL_FLAG代表空
    TreeNode *t1 = tree_build_level(&vals1);
    tree_traversal_level(t1);

    bool ret = s.isSymmetrical(t1);

    cout << ret << endl;

    return 0;
}