#include <bits/stdc++.h>

using namespace std;

struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};

class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead) {
        if (NULL == pHead)  // 空链表
            return NULL;
        
        // 先沿着后向指针拷贝链表值，并记录random指向的节点的索引
        RandomListNode* pNew = new RandomListNode(pHead->label);
        RandomListNode* pTempSrc = pHead;
        RandomListNode* pTempDst = pNew;
        while (pTempSrc->next) {
            pTempDst->next = new RandomListNode(pTempSrc->next->label);
            pTempSrc = pTempSrc->next;
            pTempDst = pTempDst->next;
        }

        // 记录原始链表节点指针和索引的映射
        unordered_map<RandomListNode*, int> umapNode2IndexOrignal;
        int index = 0;
        pTempSrc = pHead;
        while (pTempSrc) {
            umapNode2IndexOrignal[pTempSrc] = index;
            index++;
            pTempSrc = pTempSrc->next;
        }

        // 将链表节点指针间的关系，抽象为索引间的关系，然后通过结点指针和索引的关系，构建新的链表

        // 记录原始链表索引和指向的索引关系
        unordered_map<int, int> umapIndex2RandomIndex;
        index = 0;
        pTempSrc = pHead;
        while (pTempSrc) {
            if (pTempSrc->random)
                umapIndex2RandomIndex[index] = umapNode2IndexOrignal[pTempSrc->random];
            else
                umapIndex2RandomIndex[index] = -1;  // 表示没有指向任何节点
            index++;
            pTempSrc = pTempSrc->next;
        }

        // 记录新链表索引和节点指针的映射
        unordered_map<int, RandomListNode*> umapIndex2NodeNew;
        index = 0;
        pTempDst = pNew;
        while (pTempDst) {
            umapIndex2NodeNew[index] = pTempDst;
            index++;
            pTempDst = pTempDst->next;
        }

        // 再沿着后向指针处理新链表的random指针
        pTempDst = pNew;
        index = 0;
        while (pTempDst) {
            if (umapIndex2RandomIndex[index] != -1)
                pTempDst->random = umapIndex2NodeNew[umapIndex2RandomIndex[index]];
            else
                pTempDst->random = NULL;
            index++;
            pTempDst = pTempDst->next;
        }
        return pNew;
    }
};

int main() {
    Solution s;

    RandomListNode* root = new RandomListNode(1);
    root->next = new RandomListNode(2);
    root->next->next = new RandomListNode(3);
    root->next->next->next = new RandomListNode(4);
    root->next->next->next->next = new RandomListNode(5);

    root->random = root->next->next;
    root->next->random = root->next->next->next->next;
    root->next->next->next->random = root->next;

    cout << "root: " << root << endl;
    RandomListNode* temp = root;
    while (temp) {
        cout << "val: " << temp->label 
             << "\tnode: " << temp 
             << "\tnext: " << temp->next 
             << "\trandom: " << temp->random 
             << endl;
        temp = temp->next;
    }

    RandomListNode* ret =  s.Clone(root);

    cout << "ret: " << ret << endl;
    temp = ret;
    while (temp) {
        cout << "val: " << temp->label 
             << "\tnode: " << temp 
             << "\tnext: " << temp->next 
             << "\trandom: " << temp->random 
             << endl;
        temp = temp->next;
    }

    return 0;
}