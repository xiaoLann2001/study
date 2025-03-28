#include <bits/stdc++.h>

using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
};

void printListNode(ListNode* pHead) {
    while (pHead) {
        cout << pHead->val << " -> ";
        pHead = pHead->next;
    }
    cout << "NULL" << endl;
}

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param pHead ListNode类 
     * @param k int整型 
     * @return ListNode类
     */
    ListNode* FindKthToTail(ListNode* pHead, int k) {
        if (!pHead) return NULL;

        // 双指针法
        int i = 0;  // 记录pAhead正向的位置
        ListNode* pAhead = pHead;
        while (pAhead && i < k) {   // pAhead先走k步
            pAhead = pAhead->next;
            i++;
        }
        if (i < k)  // 链表长度不足k个
            return NULL;
        
        ListNode* pLater = pHead;
        while (pAhead) {    // 当pAhead到达链表末尾时，pLater相距pAhead k个位置，返回pLater即返回最后k个节点
            pAhead = pAhead->next;
            pLater = pLater->next;
        }
        return pLater;
    }
};

int main() {
    Solution s;

    ListNode* pHead = new ListNode(1);
    pHead->next = new ListNode(2);
    pHead->next->next = new ListNode(3);
    pHead->next->next->next = new ListNode(4);
    pHead->next->next->next->next = new ListNode(5);

    printListNode(pHead);

    ListNode* ret = s.FindKthToTail(pHead, 2);

    printListNode(ret);

    return 0;
}