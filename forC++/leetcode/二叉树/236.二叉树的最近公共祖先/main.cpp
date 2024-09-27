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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // 终止
        if (NULL == root) return NULL;
        if (root == p || root == q) return root;                // 终止条件
        // 左右
        TreeNode* ret_left = lowestCommonAncestor(root->left, p, q);    // 递归
        TreeNode* ret_right = lowestCommonAncestor(root->right, p, q);  // 递归
        // 中
        if (ret_left && ret_right) return root;               // 合并
        else if (!ret_left && ret_right) return ret_right;      // 传递
        else if (ret_left && !ret_right) return ret_left;       // 传递
        else return NULL;
    }
};

class Solution0 {
public:
    TreeNode* result;

    int traversal(TreeNode* root, TreeNode* p, TreeNode* q) {
        // 终止条件
        if (NULL == root) return 0;
        // f_xxx:0-未找到pq，1-找到其中一个，2-找到两个,-1-快速返回不赋值     
        int f_root = 0;
        int f_left = 0; 
        int f_right = 0;
        f_root = (root == p || root == q) ? 1 : 0;

        f_left = traversal(root->left, p, q);
        if (-1 == f_left) return -1;
        if (f_root + f_left == 2) {
            result = root;  // 记录结果，怎么快速返回？
            return -1;      // -1做返回值，跳过判断子树是否返回2  
        }

        f_right = traversal(root->right, p, q);
        if (-1 == f_right) return -1;
        if (f_root + f_left + f_right == 2) {
            result = root;
            return -1;
        }

        return f_root + f_left + f_right;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        traversal(root, p, q);
        return result;
    }
};

class Solution1 {
public:
    bool findPath(TreeNode* root, TreeNode* target, vector<TreeNode*>& path) {
        // 终止条件
        if (NULL == root) return false;
        if (root == target) {   // 找到路径，加入数组，快速返回
            path.push_back(root);
            return true;
        }
        path.push_back(root);   // 记录当前节点到数组中

        bool found_l = false;
        bool found_r = false;
        if (root->left) {
            found_l = findPath(root->left, target, path);
            if (found_l) return true;   // 若找到，快速返回
            else path.pop_back();       // 若还没找到，回溯，继续找
        }
        if (root->right) {
            found_r = findPath(root->right, target, path);
            if (found_r) return true;   // 若找到，快速返回
            else path.pop_back();       // 若还没找到，回溯，继续找
        }
        return false;   // 没找到
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> path1, path2;
        // 遍历两次，找到两条路径，并记录在数组内
        findPath(root, p, path1);
        findPath(root, q, path2);
        // 从第一层开始，寻找路径分叉点
        int i;
        for (i = 0; i < min(path1.size(), path2.size()); i++) {
            if (path1[i] != path2[i]) break;    // 若提前退出，说明i - 1是分叉点
        }
        // 若遍历到最后minlength才退出，说明短数组末尾是分叉点即i = minlength - 1
        return path1[i - 1];
    }
};

class Solution2 {
public:
    vector<TreeNode*> path;
    int min_depth_bt = INT32_MAX;
    int first_depth = 0;
    bool first = true;

    TreeNode* findPath(TreeNode* root, TreeNode* p, TreeNode* q, int depth) {
        if (NULL == root) return NULL;  // 返回空代表未结束，返回非空代表找到
        if (p == root || q == root) {
            if (first) {    // 若找到第一个节点，记录深度，计数加一
                first = false;
                first_depth = depth;
            } else  {   // 若找到第二个节点，比较回溯深度和第一次深度，取较小值
                int min_idx = min(min_depth_bt, first_depth);
                return path[min_idx];
            }    
        }
        // 若不是目标节点，记录当前节点
        path.push_back(root);
        // 递归左右子树，查看是否有结果
        if (root->left) {
            TreeNode* ret;
            if ((ret = findPath(root->left, p, q, depth + 1)) != NULL) {
                return ret;         // 若有结果，快速返回
            } else {
                path.pop_back();   // 若没有结果，回溯继续寻找
                // 记录第一次找到目标值后，回溯到达的最浅深度
                if (!first) min_depth_bt = min(min_depth_bt, depth);
            }
        }
        if (root->right) {
            TreeNode* ret;
            if ((ret = findPath(root->right, p, q, depth + 1)) != NULL) {
                return ret;         // 若有结果，快速返回
            } else  {
                path.pop_back();   // 若没有结果，回溯继续寻找
                // 记录第一次找到目标值后，回溯到达的最浅深度
                if (!first) min_depth_bt = min(min_depth_bt, depth);
            }
        }
        return NULL;    // 无结果
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // 遍历一次，找到路径分叉点
        return findPath(root, p, q, 0);
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
TreeNode *tree_build_level(vector<int>* p_vals, int p_val, int q_val, TreeNode*& p, TreeNode*& q)
{
    if (0 == p_vals->size()) return NULL;

    TreeNode *root = new TreeNode((*p_vals)[0]);
    queue<TreeNode*> queue;
    if (root->val == p_val) p = root;   //
    if (root->val == q_val) q = root;   //
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
            if (temp_root->left->val == p_val) p = temp_root->left; //
            if (temp_root->left->val == q_val) q = temp_root->left; //
            queue.push(temp_root->left);
        }
        i++;
        if (i >= p_vals->size()) break;
        if (null == (*p_vals)[i]) {
            temp_root->right = NULL;
        } else {
            temp_root->right = new TreeNode((*p_vals)[i]);
            if (temp_root->right->val == p_val) p = temp_root->right;   //
            if (temp_root->right->val == q_val) q = temp_root->right;   //
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

    vector<int> vals = {3,5,1,6,2,0,8,null,null,7,4};   // NULL_FLAG代表空
    int p_val = 7, q_val = 4;
    TreeNode *p, *q;
    TreeNode *t = tree_build_level(&vals, p_val, q_val, p, q);
    tree_traversal_level(t);

    
    TreeNode *result = s.lowestCommonAncestor(t, p, q);

    tree_traversal_level(result);

    return 0;
}