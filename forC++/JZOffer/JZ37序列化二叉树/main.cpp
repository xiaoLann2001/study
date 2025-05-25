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
    char* Serialize(TreeNode *root) {    
        // 用层序遍历输出节点值为字符串
        int index = 0;
        char* result = (char*)malloc(512 * sizeof(char));
        memset(result, '\0', 512 * sizeof(char));
        
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if (!node) {
                result[index] = '#';
                index++;
            } else {
                result[index] = (char)('0' + node->val);
                index++;
                q.push(node->left);
                q.push(node->right);
            }
        }

        // 去掉尾部的 #
        index--;
        while (result[index] == '#') {
            result[index] = '\0';
            index--;
        }

        return result;
    }   
    TreeNode* Deserialize(char *str) {
        // 反序列化即根据层序遍历结果，构造二叉树，规定 '#' 为空节点
        if (!str)
            return NULL;
        
        int index = 0;
        TreeNode* root = NULL;
        queue<TreeNode*> q;
        if (str[index] == '#')
            return NULL;
        else {
            root = new TreeNode(str[index] - '0');
            q.push(root);
            index++;
        }

        while (!q.empty() && index < strlen(str)) {
            // 当前待处理节点
            TreeNode* node = q.front();
            q.pop();

            // 左子节点
            if (str[index] == '#')
                node->left = NULL;
            else {
                node->left =  new TreeNode(str[index] - '0');
                q.push(node->left);
            }
            index++;

            // 右子节点
            if (index >= strlen(str))
                break;
            if (str[index] == '#')
                node->right = NULL;
            else {
                node->right =  new TreeNode(str[index] - '0');
                q.push(node->right);
            }
            index++;
        }

        return root;
    }
};

int main() {
    Solution s;

    char str[] = {'1', '2', '3', '#', '#', '6', '7'};

    TreeNode* ret = s.Deserialize(str);

    tree_traversal_level(ret);

    cout << s.Serialize(ret) << endl;

    return 0;
}