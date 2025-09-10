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
        cout << ret->val << ",";

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
                string numStr = to_string(node->val);
                strncpy(result + index, numStr.c_str(), numStr.size());
                index += numStr.size();
                q.push(node->left);
                q.push(node->right);
            }
            result[index] = ',';    // 节点数值分隔符
            index++;
        }

        // 去掉尾部的 # 和 ,
        index--;
        while (result[index] == ',' || result[index] == '#') {
            result[index] = '\0';
            index--;
        }

        return result;
    }   
    TreeNode* Deserialize(const char *str) {
        if (!str || *str == '\0') return nullptr;

        stringstream ss(str);
        string token;

        // 读取根节点
        if (!getline(ss, token, ',')) return nullptr;
        if (token == "#") return nullptr;

        TreeNode* root = new TreeNode(stoi(token));
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();

            // 左子节点
            if (!getline(ss, token, ',')) break;
            if (token != "#") {
                curr->left = new TreeNode(stoi(token));
                q.push(curr->left);
            }

            // 右子节点
            if (!getline(ss, token, ',')) break;
            if (token != "#") {
                curr->right = new TreeNode(stoi(token));
                q.push(curr->right);
            }
        }

        return root;
    }
};

int main() {
    Solution s;

    char str[] = "100,50,#,#,150";

    TreeNode* ret = s.Deserialize(str);

    tree_traversal_level(ret);

    cout << s.Serialize(ret) << endl;

    return 0;
}