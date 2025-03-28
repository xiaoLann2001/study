#include <bits/stdc++.h>

using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
};

void printListNode(ListNode* pHead, int n) {
    int i = 0;
    while (pHead && i < n) {
        cout << pHead->val << "(" << reinterpret_cast<void*>(pHead) << ")" << " -> ";
        pHead = pHead->next;
        i++;
    }
    if (!pHead)
        cout << "NULL";
    cout << endl;
}

class Solution {
public:
    ListNode* EntryNodeOfLoop(ListNode* pHead) {
        if (!pHead || !pHead->next) return nullptr;
        
        // 快慢指针
        ListNode* pSlow = pHead;
        ListNode* pFast = pHead;
        
        while (pFast && pFast->next) {
            pSlow = pSlow->next;
            pFast = pFast->next->next;
            if (pSlow == pFast) break; // 相遇，说明有环
        }
        
        if (!pFast || !pFast->next) return nullptr; // 无环，直接返回
        
        // 寻找环的入口
        ListNode* pEntry = pHead;
        while (pEntry != pSlow) {
            pEntry = pEntry->next;
            pSlow = pSlow->next;
        }

        return pEntry;
    }
};

int main() {
    Solution s;

    ListNode* pHead = new ListNode(1);
    pHead->next = new ListNode(2);
    pHead->next->next = new ListNode(3);
    pHead->next->next->next = new ListNode(4);
    pHead->next->next->next->next = new ListNode(5);
    pHead->next->next->next->next->next = pHead->next->next;

    printListNode(pHead, 6);

    ListNode* ret = s.EntryNodeOfLoop(pHead);

    cout << reinterpret_cast<void*>(ret) << endl;

    return 0;
}