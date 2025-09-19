#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        // 以数组中点为根，递归构建二叉树
        return sortedSubArrayToBST(nums, 0, nums.size() - 1);
    }

    TreeNode* sortedSubArrayToBST(vector<int>& nums, int left, int right) {
        if (left > right) return nullptr;
        if (left == right) return (new TreeNode(nums[left]));

        // int mid = left + (right - left) >> 1;    // left = 3, right = 4, mid = 2
        int mid = left + ((right - left) >> 1);
        
        // 递归构建左右子树
        TreeNode* leftTree = nullptr;
        TreeNode* rightTree = nullptr;
        if (mid > left) leftTree = sortedSubArrayToBST(nums, left, mid - 1);
        if (mid < right) rightTree = sortedSubArrayToBST(nums, mid + 1, right);

        return new TreeNode(nums[mid], leftTree, rightTree);
    }
};

void traversal(TreeNode* root) {
    if (root == nullptr) return;

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();

        cout << node->val << " ";

        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);
    }
     
    cout << endl;

    return;
}

int main() {
    Solution s;

    vector<int> input = {-10,-3,0,5,9};

    TreeNode *ret = s.sortedArrayToBST(input);

    traversal(ret);

    return 0;
}