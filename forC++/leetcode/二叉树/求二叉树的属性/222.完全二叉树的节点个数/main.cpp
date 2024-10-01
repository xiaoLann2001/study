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

class Solution {
public:
    int isMaxTree(TreeNode* root) {
        int depth_l = 1;
        int depth_r = 1;
        TreeNode *temp = root;
        while (temp->left) {    // 遍历左孩子
            depth_l++;
            temp = temp->left;
        } 
        temp = root;
        while (temp->right) {   // 遍历右孩子
            depth_r++;
            temp = temp->right;
        }
        if (depth_l == depth_r) {
            return depth_l; // 是满二叉树，返回其深度
        } else {
            return -1;      // 不是满二叉树，返回-1
        }
    }
    
    int countNodes(TreeNode* root) {
        // 终止条件
        if (NULL == root) return 0;
        
        int num_l = 0;
        int num_r = 0;

        if (root->left) {
            int depth_l = isMaxTree(root->left);
            if (-1 == depth_l) {    // 若不是满二叉树，继续递归左右子树
                num_l = countNodes(root->left);
            } else {                // 是满二叉树，计算公式
                num_l = (1 << depth_l) - 1;
            }
        }

        if (root->right) {
            int depth_r = isMaxTree(root->right);
            if (-1 == depth_r) {
                num_r = countNodes(root->right);
            } else {
                num_r = (1 << depth_r) - 1;
            }
        }

        int num_all = 1 + num_l + num_r;

        return num_all;
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

    vector<int> vals = {1,2,3,4,5,6};   // NULL_FLAG代表空
    TreeNode *t = tree_build_level(&vals);
    tree_traversal_level(t);

    int result = s.countNodes(t);

    cout << result << endl;

    return 0;
}