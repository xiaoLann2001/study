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
    bool VerifySquenceOfBST(vector<int> sequence) {
        // 二叉搜索树的性质：左子树的值 小于等于 根节点 小于等于 右子树
        // 二叉搜索树的子树也是二叉搜索树
        // 后序遍历为 左右中，可以根据最后一个值来划分左右子树，然后递归判断
        // （左子树全在剩下的数组左边，右子树全在剩下的数组右边）
        if (sequence.empty())
            return false;
        return VerifySubSquenceOfBST(sequence, 0, sequence.size() - 1);
    }

    bool VerifySubSquenceOfBST(const vector<int>& sequence, int low, int high) {
        if (low >= high)     // 空树或叶子
            return true;
        // 最后一位一定是根节点
        int partitionIndex = low;   // 左右子树划分点，为右子树开始的位置，如果等于 low 说明没有左子树，等于 high 说明没有右子树
        while (partitionIndex < high && sequence[partitionIndex] <= sequence[high]) {
            partitionIndex++;
        }
        bool ret = true;
        if (low <= partitionIndex - 1) {    // 有左子树
            // 判断数据范围符不符合要求
            ret &= (sequence[high] >= *max_element(sequence.begin() + low, sequence.begin() + partitionIndex)); // 左闭右开
            // 递归判断
            ret &= VerifySubSquenceOfBST(sequence, low, partitionIndex - 1);
        }
        if (partitionIndex <= high - 1) {   // 有右子树
            ret &= (sequence[high] <= *min_element(sequence.begin() + partitionIndex, sequence.begin() + high));
            ret &= VerifySubSquenceOfBST(sequence, partitionIndex, high - 1);
        }
        return ret;
    }
};

int main() {
    Solution s;

    vector<int> treeArray = {3,1,2};
    // TreeNode* root = tree_build_level(&treeArray);

    bool ret = s.VerifySquenceOfBST(treeArray);

    cout << ret << endl;

    return 0;
}