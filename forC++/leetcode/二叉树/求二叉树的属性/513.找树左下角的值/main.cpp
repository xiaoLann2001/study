#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>

#define null (-2147483648)

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        // 找最底层最左边的元素，用层序遍历
        queue<TreeNode*> que;
        TreeNode *level_first;  // 记录每层第一个节点
        int size;

        // 假设二叉树最少有一个节点
        que.push(root);
        while (!que.empty()) {
            size = que.size();
            for (int i = 0; i < size; i++) {
                TreeNode *node = que.front();
                que.pop();
                if (0 == i) level_first = node; // 记录每层第一个节点
                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
            }
        }
        return level_first->val;
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

    if (null == (*p_vals)[idx])
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

int main() {
    Solution s;

    vector<int> vals = {1,2,3,4,null,5,6,null,null,7};   // NULL_FLAG代表空
    TreeNode *t = tree_build_level(&vals);
    tree_traversal_level(t);

    int result = s.findBottomLeftValue(t);

    cout << result << endl;

    return 0;
}