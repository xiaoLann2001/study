#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <climits>

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
    bool isValidBST(TreeNode* root) {
        bool left_is_vaild = true;
        bool right_is_vaild = true;
        if (root->left) {   // 若左子树存在
            // 若左孩子小于根，遍历左孩子
            if (root->left->val < root->val) left_is_vaild = isValidBST(root->left);
            // 否则返回false
            else left_is_vaild = false;
            // 求左子树最大元素
            TreeNode *temp = root->left;
            while (temp->right) temp = temp->right;
            if (temp->val >= root->val) left_is_vaild = false;
        }
        if (root->right) {
            if (root->right->val > root->val) right_is_vaild = isValidBST(root->right);
            else right_is_vaild = false;
            // 求右子树最小元素
            TreeNode *temp = root->right;
            while (temp->left) temp = temp->left;
            if (temp->val <= root->val) right_is_vaild = false;
        }
        return left_is_vaild && right_is_vaild;
    }
};

class Solution1 {
public:
    bool isValidBST(TreeNode* root) {
        if (root->left) {   // 若左子树存在
            // 若左孩子小于根，遍历左孩子
            if (root->left->val < root->val) {
                if (!isValidBST(root->left)) return false;
            }
            // 否则返回false
            else return false;
            // 求左子树最大元素
            TreeNode *temp = root->left;
            while (temp->right) temp = temp->right;
            if (temp->val >= root->val) return false;
        }
        if (root->right) {
            if (root->right->val > root->val) {
                if (!isValidBST(root->right)) return false;
            }
            else return false;
            // 求右子树最小元素
            TreeNode *temp = root->right;
            while (temp->left) temp = temp->left;
            if (temp->val <= root->val) return false;
        }
        return true;
    }
};

class Solution2 {
public:
    long long maxVal = LONG_MIN; // 因为后台测试数据中有int最小值
    bool isValidBST(TreeNode* root) {
        if (root == NULL) return true;

        bool left = isValidBST(root->left);
        // 中序遍历，验证遍历的元素是不是从小到大
        if (maxVal < root->val) maxVal = root->val;
        else return false;
        bool right = isValidBST(root->right);

        return left && right;
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

    vector<int> vals = {5,1,4,null,null,3,6};   // NULL_FLAG代表空
    TreeNode *t = tree_build_level(&vals);
    tree_traversal_level(t);

    bool result = s.isValidBST(t);

    if (result) cout << "true" << endl;
    else cout << "false" << endl;

    return 0;
}