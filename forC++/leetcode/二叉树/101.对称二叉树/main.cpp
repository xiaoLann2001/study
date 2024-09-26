#include <iostream>
#include <vector>
#include <queue>
#include <stack>

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
    bool isSymmetric(TreeNode* root) {
        if (NULL == root->left && NULL == root->right) return true;
        // 用栈来遍历左右子树，左子树入栈顺序为中右左，右子树为中左右
        stack<TreeNode*> st_l;
        stack<TreeNode*> st_r;
        if (root->left && root->right) {
            st_l.push(root->left);
            st_r.push(root->right);
        }
        if ((!root->right && root->left) || 
            (root->right && !root->left)) {
            return false;
        }
        while (!st_l.empty() && !st_r.empty()) {
            TreeNode* node_l = st_l.top();  // 中
            TreeNode* node_r = st_r.top();  // 中
            st_l.pop();
            st_r.pop();
            if (!node_l && !node_r) continue;   // 若两边都为空
            else if ((!node_l && node_r) || (node_l && !node_r)) return false;   // 若一边为空，一边不为空

            if (node_l->val != node_r->val) return false;   // 若两边值不相等

            // 左右节点入栈，不管是不是空
            st_l.push(node_l->left);
            st_l.push(node_l->right);
            st_r.push(node_r->right);
            st_r.push(node_r->left);
        }
        return true;
    }
};

class Solution1 {
public:
    bool compare(TreeNode* left, TreeNode* right) {
        if (left == NULL && right != NULL) return false;
        else if (left != NULL && right == NULL) return false;
        else if (left == NULL && right == NULL) return true;
        else if (left->val != right->val) return false;
        else return compare(left->left, right->right) && compare(left->right, right->left);

    }
    bool isSymmetric(TreeNode* root) {
        if (root == NULL) return true;
        return compare(root->left, root->right);
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

    vector<int> vals = {1,2,2,3,NULL_FLAG,3,NULL_FLAG};   // NULL_FLAG代表空
    TreeNode *t = tree_build_level(&vals);
    tree_traversal_level(t);

    bool result = s.isSymmetric(t);

    if (result) cout << "true\n";
    else cout << "false\n";

    return 0;
}