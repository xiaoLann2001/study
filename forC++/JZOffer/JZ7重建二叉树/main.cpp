#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param preOrder int整型vector 
     * @param vinOrder int整型vector 
     * @return TreeNode类
     */
    TreeNode* reConstructBinaryTree(vector<int>& preOrder, vector<int>& vinOrder) {
        if (preOrder.size() == 0) return NULL;
        // 以前序遍历为突破口，子树根节点一定在前序遍历第一个位置
        // 中序遍历根节点左边一定是左子树，右边一定是右子树，以此得知左右子树节点个数
        // 知道左右子树节点数之后，就知道前序遍历中左右子树的位置，根左右

        // 用子树的子数组继续此操作，当数组只有一个元素时，说明到达了叶子节点，则返回
        TreeNode *root = travel(preOrder, vinOrder, 0, preOrder.size() - 1, 0, vinOrder.size() - 1);
        return root;
    }

    TreeNode* travel(vector<int>& preOrder, vector<int>& vinOrder, int pres, int pree, int vins, int vine) {
        // 前序遍历第一个一定是根节点
        TreeNode *root = new TreeNode(preOrder[pres]);

        // 叶子节点
        if (pres == pree) return root;

        // 计算出左右子树元素个数
        int rootloc_in_vinOrder = 0, leftlen = 0, rightlen = 0;
        for (int i = vins; i <= vine; i++) {
            if (vinOrder[i] == preOrder[pres]) {
                rootloc_in_vinOrder = i;
                leftlen = i - vins;
                rightlen = vine - i;
                break;
            }
        }

        // 递归构造左右子树
        if (leftlen > 0) root->left = travel(preOrder, vinOrder, pres + 1, pres + leftlen, vins, rootloc_in_vinOrder - 1);
        if (rightlen > 0) root->right = travel(preOrder, vinOrder, pres + leftlen + 1, pree, rootloc_in_vinOrder + 1, vine);

        return root;
    }
};

int main() {
    Solution s;

    vector<int> pre = {1,2,4,7,3,5,6,8};
    vector<int> vin = {4,7,2,1,5,3,8,6};

    TreeNode* ret = s.reConstructBinaryTree(pre, vin);

    // 输出层序二叉树
    int count = pre.size();
    queue<TreeNode*> que;
    que.push(ret);
    while (!que.empty() && count > 0) {
        TreeNode* node_cur = que.front();
        que.pop();
        if (node_cur == NULL) {
            cout << "#";
            continue;
        }
        cout << node_cur->val;
        count--;
        que.push(node_cur->left);
        que.push(node_cur->right);
    }
    cout << endl;

    return 0;
}