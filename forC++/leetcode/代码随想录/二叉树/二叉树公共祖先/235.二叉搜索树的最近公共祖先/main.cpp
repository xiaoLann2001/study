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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // 确保p < q
        if (p->val > q->val) return lowestCommonAncestor(root, q, p);
        while (root) {
            // 若根为p或q返回根
            if (root == p || root == q) return root;
            // 若p<root<q，返回根
            if (p->val < root->val && root->val < q->val) return root;
            // 若p<q<root，遍历左子树
            else if (p->val < q->val && q->val < root->val) root = root->left;
            // 若root<p<q，遍历右子树
            else if (root->val < p->val && p->val < q->val) root = root->right;
        }
        return root;
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
TreeNode *tree_build_level(vector<int>* p_vals, int p_val, int q_val, TreeNode*& p, TreeNode*& q)
{
    if (0 == p_vals->size()) return NULL;

    TreeNode *root = new TreeNode((*p_vals)[0]);
    queue<TreeNode*> queue;
    if (root->val == p_val) p = root;   //
    if (root->val == q_val) q = root;   //
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
            if (temp_root->left->val == p_val) p = temp_root->left; //
            if (temp_root->left->val == q_val) q = temp_root->left; //
            queue.push(temp_root->left);
        }
        i++;
        if (i >= p_vals->size()) break;
        if (null == (*p_vals)[i]) {
            temp_root->right = NULL;
        } else {
            temp_root->right = new TreeNode((*p_vals)[i]);
            if (temp_root->right->val == p_val) p = temp_root->right;   //
            if (temp_root->right->val == q_val) q = temp_root->right;   //
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

    vector<int> vals = {6,2,8,0,4,7,9,null,null,3,5};   // NULL_FLAG代表空
    int p_val = 2, q_val = 4;
    TreeNode *p, *q;
    TreeNode *t = tree_build_level(&vals, p_val, q_val, p, q);
    tree_traversal_level(t);

    
    TreeNode *result = s.lowestCommonAncestor(t, p, q);

    tree_traversal_level(result);

    return 0;
}