#include <bits/stdc++.h>

using namespace std;

#define null (-2147483648)

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
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
    vector<vector<int>> findPath(TreeNode* root, int target) {
        result.clear();
        path.clear();
        if (NULL == root)
            return result;
        
        path.push_back(root->val);
        traversal(root, target);
        return result;
    }

    void traversal(TreeNode* root, int target) {
        // 回溯法，寻找求和为指定值的根到叶子的路径
        if (NULL == root->left && NULL == root->right) {    // 叶子节点
            if (root->val == target)                // 当前路径和刚好等于目标值
                result.push_back(path);     // 保存路径
            return;
        }
        
        if (root->left) {   // 存在左子树
            path.push_back(root->left->val);
            traversal(root->left, target - root->val);    // 值传递自动回溯
            path.pop_back();
        }
        if (root->right) {   // 存在右子树
            path.push_back(root->right->val);
            traversal(root->right, target - root->val);    // 值传递自动回溯
            path.pop_back();
        }
    }

private:
    vector<vector<int>> result;
    vector<int> path;
};

int main() {
    Solution s;

    vector<int> treeArray = {10,5,12,4,7};
    TreeNode* root = tree_build_level(&treeArray);
    int target = 22;

    vector<vector<int>> ret = s.findPath(root, target);

    for (const auto& v : ret) {
        for (const auto& n : v)
            cout << n << " ";
        cout << endl;
    }

    return 0;
}