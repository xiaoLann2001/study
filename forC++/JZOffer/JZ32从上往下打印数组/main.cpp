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
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        vector<int> result;
        // 空树
        if (NULL == root)
            return result;
        // 层序遍历
        queue<TreeNode*> que;
        que.push(root);
        while (!que.empty()) {
            TreeNode* cur = que.front();
            que.pop();
            result.push_back(cur->val);
            if (cur->left)
                que.push(cur->left);
            if (cur->right)
                que.push(cur->right);
        }
        return result;
    }

    // 分层打印
    vector<vector<int>> PrintFromTopToBottomByLevel(TreeNode* root) {
        vector<vector<int>> result;
        // 空树
        if (NULL == root)
            return result;
        // 层序遍历
        int level = -1;
        int toBePrint = 0;
        int willBePrintNext = 0;
        queue<TreeNode*> que;
        que.push(root);
        willBePrintNext++;
        while (!que.empty()) {
            if (0 == toBePrint) {                   // 若本层打印完
                result.push_back(vector<int>{});    // 开辟新的行
                level++;                            // 层数加一
                toBePrint = willBePrintNext;        // 将下一层待打印节点数 赋给 本层待打印节点数
                willBePrintNext = 0;                // 重新统计下一层待打印节点数
            }
            TreeNode* cur = que.front();
            que.pop();
            result[level].push_back(cur->val);
            toBePrint--;

            if (cur->left) {
                que.push(cur->left);
                willBePrintNext++;
            }
            if (cur->right) {
                que.push(cur->right);
                willBePrintNext++;
            }
        }
        return result;
    }

    // 之字形打印，栈加队列
    vector<vector<int>> PrintFromTopToBottomByZshape(TreeNode* root) {
        vector<vector<int>> result;
        // 空树
        if (NULL == root)
            return result;
        // 层序遍历
        int level = -1;
        int toBePrint = 0;
        int willBePrintNext = 0;
        queue<TreeNode*> que;
        stack<TreeNode*> stNext;   // 辅助栈：下一层待打印节点栈
        stNext.push(root);
        willBePrintNext++;
        while (!que.empty() || !stNext.empty()) {
            if (0 == toBePrint) {                   // 若本层打印完
                result.push_back(vector<int>{});    // 开辟新的行
                while (!stNext.empty()) {           // 将下一层节点从栈中全部取出，压入队列
                    que.push(stNext.top());
                    stNext.pop();
                }
                level++;                            // 层数加一
                toBePrint = willBePrintNext;        // 将下一层待打印节点数 赋给 本层待打印节点数
                willBePrintNext = 0;                // 重新统计下一层待打印节点数
            }
            TreeNode* cur = que.front();
            que.pop();
            result[level].push_back(cur->val);
            toBePrint--;

            if (cur->left) {
                if (0 == level % 2)
                    stNext.push(cur->left);         // 每隔一层，调换一次顺序
                else
                    que.push(cur->left);
                willBePrintNext++;
            }
            if (cur->right) {
                if (0 == level % 2)
                    stNext.push(cur->right);
                else
                    que.push(cur->right);
                willBePrintNext++;
            }
        }
        return result;
    }

    // 之字形打印，两个栈
    vector<vector<int>> PrintFromTopToBottomByZshape2(TreeNode* root) {
        vector<vector<int>> result;
        // 空树
        if (NULL == root)
            return result;
        // 层序遍历
        int level = -1;
        int toBePrint = 0;
        int willBePrintNext = 0;
        int cur = 0;
        int next = 1;
        stack<TreeNode*> stLevel[2];   // 辅助栈
        stLevel[next].push(root);
        willBePrintNext++;
        while (!stLevel[0].empty() || !stLevel[1].empty()) {
            if (0 == toBePrint) {                   // 若本层打印完
                result.push_back(vector<int>{});    // 开辟新的行
                level++;                            // 层数加一
                toBePrint = willBePrintNext;        // 将下一层待打印节点数 赋给 本层待打印节点数
                willBePrintNext = 0;                // 重新统计下一层待打印节点数
                swap(cur, next);                    // 调换当前层和下一层节点的栈
            }
            TreeNode* curNode = stLevel[cur].top();
            stLevel[cur].pop();
            result[level].push_back(curNode->val);
            toBePrint--;

            if (0 == level % 2) {
                if (curNode->left) {
                    stLevel[next].push(curNode->left);
                    willBePrintNext++;
                }
                if (curNode->right) {
                    stLevel[next].push(curNode->right);
                    willBePrintNext++;
                }
            } else {
                if (curNode->right) {
                    stLevel[next].push(curNode->right);
                    willBePrintNext++;
                }
                if (curNode->left) {
                    stLevel[next].push(curNode->left);
                    willBePrintNext++;
                }
            }
        }
        return result;
    }
};

int main() {
    Solution s;

    vector<int> treeArray = {8,6,10,null,null,2,1};
    TreeNode* root = tree_build_level(&treeArray);

    vector<int> ret = s.PrintFromTopToBottom(root);

    for (const auto& n : ret)
        cout << n << " ";
    cout << endl;
    cout << endl;

    vector<vector<int>> ret2 = s.PrintFromTopToBottomByLevel(root);

    for (const auto& v : ret2) {
        for (const auto& n : v)
            cout << n << " ";
        cout << endl;
    }
    cout << endl;

    vector<vector<int>> ret3 = s.PrintFromTopToBottomByZshape2(root);

    for (const auto& v : ret3) {
        for (const auto& n : v)
            cout << n << " ";
        cout << endl;
    }
    cout << endl;

    return 0;
}