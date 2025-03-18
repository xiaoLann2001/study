#include <bits/stdc++.h>

using namespace std;

struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {
        
    }
};

class Solution {
public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode) {
        // 若存在右子树，找右子树最左边的节点
        if (pNode->right) {
            TreeLinkNode* p = pNode->right;
            while (p->left) p = p->left;
            return p;
        } 
        
        // 若存在父节点，找到当前节点属于左子树的那个父节点
        if (pNode->next){
            TreeLinkNode* p = pNode->next;
            while (p && pNode == p->right) {
                pNode = p;
                p = p->next;
            }
            return p;
        }

        // 不存在右子树，也不存在父节点
        return NULL;
    }
};

int main() {
    

    return 0;
}