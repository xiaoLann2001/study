#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define null INT32_MAX

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
    int result;

    int traversal(TreeNode* current_node) {
        // 若为空节点，返回2，表示已覆盖
        if (NULL == current_node) return 2;
        // 求出左右孩子的状态
        int left = traversal(current_node->left);
        int right = traversal(current_node->right);
        // 若左右孩子都已覆盖
        if (left == 2 && right == 2) {
            return 0;   // 返回未覆盖，以让父节点放置摄像头
        }
        // 若左右孩子有一个及以上没有被覆盖的
        if (left == 0 || right == 0) {
            result++;
            return 1;   // 需要放置摄像头
        }
        // 若左右孩子有一个及以上有摄像头
        if (left == 1 || right == 1) {
            return 2;   // 返回已覆盖
        }

        return -1;  // 随便返回，逻辑不会执行到这里
    }

    int minCameraCover(TreeNode* root) {
        result = 0;
        int ret = traversal(root);
        // 若根节点未覆盖，在根节点放置摄像头，结果加一
        if (ret == 0) {
            result++;
        }
        return result;
    }
};

int main() {
    Solution s;

    vector<int> nums = {0,0,null,0,0};

    TreeNode *root = tree_build_level(&nums);

    int result = s.minCameraCover(root);

    cout << result << endl;

    return 0;
}