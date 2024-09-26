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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if (1 == nums.size()) return (new TreeNode(nums[0]));
        int max = 0;
        int idx;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > max) {
                max = nums[i];
                idx = i;
            }
        }
        TreeNode *root = new TreeNode(max);
        if (idx > 0) {
            vector<int> left_tree = vector<int>(nums.begin(), nums.begin() + idx);
            root->left = constructMaximumBinaryTree(left_tree);
        }
        if (idx < nums.size() - 1) {
            vector<int> right_tree = vector<int>(nums.begin() + idx + 1, nums.end());
            root->right = constructMaximumBinaryTree(right_tree);
        }
        return root;
    }
};

class Solution1 {
private:
    // [begin, end)
    TreeNode* traversal (vector<int>& nums, int begin, int end) {
        if (1 == end - begin) return (new TreeNode(nums[begin]));
        int max = 0;
        int idx;
        for (int i = begin; i < end; i++) {
            if (nums[i] > max) {
                max = nums[i];
                idx = i;
            }
        }
        TreeNode *root = new TreeNode(max);
        if (begin < idx) {
            root->left = traversal(nums, begin, idx);
        }
        if (idx < end - 1) {
            root->right = traversal(nums, idx + 1, end);
        }
        return root;
    }
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return traversal(nums, 0, nums.size());
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
    Solution1 s;

    // vector<int> vals = {5,4,8,11,null,13,4,7,2,null,null,null,5,1};   // NULL_FLAG代表空
    // TreeNode *t = tree_build_level(&vals);
    // tree_traversal_level(t);
    vector<int> nums = {3,2,1,6,0,5};

    TreeNode *result = s.constructMaximumBinaryTree(nums);

    tree_traversal_level(result);

    return 0;
}