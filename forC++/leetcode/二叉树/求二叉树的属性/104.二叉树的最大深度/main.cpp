#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>

#define NULL_FLAG (-2147483648)

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 递归法，先序遍历
class Solution {
public:
    int result = 0;

    void getDepth(TreeNode* root, int depth) {
        // 结束条件
        if (NULL == root) return;
        result = max(result, depth + 1);    // 中
        getDepth(root->left, depth + 1);    // 左
        getDepth(root->right, depth + 1);   // 右
    }

    int maxDepth(TreeNode* root) {
        getDepth(root, 0);
        return result;
    }
};

// 递归法，后序遍历
class Solution2 {
public:
    int maxDepth(TreeNode* root) {
        // 结束条件
        if (NULL == root) return 0; 
        // 左子树最大深度
        int max_l = maxDepth(root->left);
        // 右子树最大深度
        int max_r = maxDepth(root->right);
        // 带上根节点的最大深度
        int max_all = 1 + max(max_l, max_r);
        return max_all;
    }
};

// 迭代法，层序遍历
class Solution3 {
public:
    int maxDepth(TreeNode* root) {
        int result = 0;
        queue<TreeNode*> q;
        if (root != NULL) q.push(root);
        while (!q.empty()) {
            int size = q.size();
            result++;
            while (size--) {
                TreeNode * node = q.front();
                q.pop();
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
        } 
        return result;
    }
};

/**
 * @brief 先序构造二叉树
 * @param p_vals-按先序顺序排列的数组指针，数组的值为NULL_FLAG时表示空
 * @return 按先序顺序构造的二叉树的根节点
*/
TreeNode *tree_build_preoder(vector<int>* p_vals)
{
    static int idx = 0;

    if (idx > p_vals->size() - 1) return NULL;

    TreeNode *root = new TreeNode();

    if (NULL_FLAG == (*p_vals)[idx])
    {
        idx++;
        return NULL;
    }

    root->val = (*p_vals)[idx];
    idx++;
    root->left = tree_build_preoder(p_vals);
    root->right = tree_build_preoder(p_vals);

    return root;
}

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
        if (NULL_FLAG == (*p_vals)[i]) {
            temp_root->left = NULL;
        } else {
            temp_root->left = new TreeNode((*p_vals)[i]);
            queue.push(temp_root->left);
        }
        i++;
        if (i >= p_vals->size()) break;
        if (NULL_FLAG == (*p_vals)[i]) {
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

int main() {
    Solution s;

    vector<int> vals = {3,9,20,NULL_FLAG,NULL_FLAG,15,7};   // NULL_FLAG代表空
    TreeNode *t = tree_build_level(&vals);
    tree_traversal_level(t);

    int result = s.maxDepth(t);

    cout << "maxdepth: " << result << endl;

    return 0;
}