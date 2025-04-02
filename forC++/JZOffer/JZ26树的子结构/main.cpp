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
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2) {
        if (!pRoot1 || !pRoot2)
            return false;
        
        // 遍历树pRoot1，检查根节点是否与pRoot2相等
        // 选层序遍历
        queue<TreeNode*> que;
        que.push(pRoot1);
        while (!que.empty()) {
            TreeNode* pTemp = que.front();
            que.pop();

            bool ret = false;
            if (pTemp->val == pRoot2->val)
                ret = traversal(pTemp, pRoot2);
            if (ret)
                return true;

            if (pTemp->left)
                que.push(pTemp->left);
            if (pTemp->right)
                que.push(pTemp->right);
        }
        
        return false;
    }

    bool traversal(TreeNode* pRoot1, TreeNode* pRoot2) {
        if (!pRoot2)    // 若小树到达空节点，视为具有相同结构（与题中定义不同，这里只是为了方便控制终止条件）
            return true;
        if (!pRoot1)    // 若大树没有的节点，小树有，那么没有相同的结构
            return false;
        
        bool ret = true;
        ret &= (pRoot1->val == pRoot2->val);
        ret &= traversal(pRoot1->left, pRoot2->left);       // 检查左子树是否具有相同结构
        ret &= traversal(pRoot1->right, pRoot2->right);     // 检查右子树是否具有相同结构
        
        return ret; // 根节点相等且左右子树结构相同才视为结构相同
    }
};

int main() {
    Solution s;

    vector<int> vals1 = {8,8,7,9,2,null,null,null,null,4,7};   // NULL_FLAG代表空
    TreeNode *t1 = tree_build_level(&vals1);
    // tree_traversal_level(t1);

    vector<int> vals2 = {8,9,2};   // NULL_FLAG代表空
    TreeNode *t2 = tree_build_level(&vals2);
    // tree_traversal_level(t2);

    bool ret = s.HasSubtree(t1, t2);

    cout << ret << endl;

    return 0;
}