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

class Solution1 {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param pRoot TreeNode类 
     * @return TreeNode类
     */
    TreeNode* Mirror(TreeNode* pRoot) {
        // 方法一，新建一个树，遍历原来的树来镜像创建新的树，空间复杂度O(n)，时间复杂度O(n)
        if (!pRoot)
            return NULL;
        TreeNode* pNew;
        traversal(pRoot, &pNew);
        return pNew;
    }

    void traversal(TreeNode* pRoot, TreeNode** pNew) {
        if (!pRoot) // 若原来位置为空节点，返回
            return;
        
        *pNew = new TreeNode(pRoot->val);    // 构造根节点
        if (pRoot->left)
            traversal(pRoot->left, &(*pNew)->right);    // 镜像构造
        if (pRoot->right)
            traversal(pRoot->right, &(*pNew)->left);
    }
};

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param pRoot TreeNode类 
     * @return TreeNode类
     */
    TreeNode* Mirror(TreeNode* pRoot) {
        // 方法二，原地修改树，用后序遍历（先序遍历也行），等子树都镜像后，再镜像左右子节点，空间复杂度O(1)，时间复杂度O(n)
        if (!pRoot)
            return NULL;
        if (!pRoot->left && !pRoot->right)
            return pRoot;

        if (pRoot->left) 
            Mirror(pRoot->left);    // 先镜像左右子树
        if (pRoot->right)
            Mirror(pRoot->right);
        
        swap(pRoot->left, pRoot->right);    // 再镜像左右子节点
        
        return pRoot;
    }
};

int main() {
    Solution s;

    vector<int> vals1 = {8,6,10,5,7,9,11};   // NULL_FLAG代表空
    TreeNode *t1 = tree_build_level(&vals1);
    tree_traversal_level(t1);

    TreeNode* ret = s.Mirror(t1);

    tree_traversal_level(ret);

    return 0;
}