#include <iostream>
#include <vector>
#include <queue>
#include <stack>

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
    vector<vector<int>> result;

    void preorder_traversal(TreeNode* root, vector<int>& vec, int count) {
        // 从根到叶子算一条路径，用先序遍历
        if (NULL == root) return;
        vec.push_back(root->val);

        if (!root->left && !root->right && 0 == count)    // 中若为叶子，加到末尾并加入到结果集
            result.push_back(vec);
        else {
            if (root->left) {
                // 递归，处理节点
                preorder_traversal(root->left, vec, count - root->left->val);
                // 回溯，撤销处理，寻找新路径
                vec.pop_back();
            }
            if (root->right) {
                preorder_traversal(root->right, vec, count - root->right->val);
                vec.pop_back();
            }
        }
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if (NULL == root) return result;
        vector<int> vec;
        preorder_traversal(root, vec, targetSum - root->val);
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

    vector<int> vals = {5,4,8,11,null,13,4,7,2,null,null,null,5,1};   // NULL_FLAG代表空
    TreeNode *t = tree_build_level(&vals);
    tree_traversal_level(t);

    int target = 22;

    vector<vector<int>> result = s.pathSum(t, target);

    for (vector<int> path : result) {
        for (int n : path) {
            cout << n << ", ";
        }
        cout << endl;
    }

    return 0;
}