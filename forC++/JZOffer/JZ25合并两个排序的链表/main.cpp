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
     * @param pHead1 ListNode类 
     * @param pHead2 ListNode类 
     * @return ListNode类
     */
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2) {
        // 特殊情况
        if (!pHead1) return pHead2;
        if (!pHead2) return pHead1;

        // 一般情况
        ListNode* pMergedHead = NULL;               // 合并后的链表头节点指针，可以视为虚拟头节点的next指针
        ListNode** pTempOfNext = &(pMergedHead);    // 记录next指针的指针
        ListNode* pTemp1 = pHead1;
        ListNode* pTemp2 = pHead2;
        while (pTemp1 && pTemp2) {
            if (pTemp1->val < pTemp2->val) {
                *pTempOfNext = pTemp1;              // 将合并后链表尾节点的next指针 指向 值更小的那个节点
                pTemp1 = pTemp1->next;
            } else {
                *pTempOfNext = pTemp2;
                pTemp2 = pTemp2->next; 
            }
            pTempOfNext = &(*pTempOfNext)->next;    // 更新合并后链表尾节点的next指针
        }

        // 将剩余节点加入结果链表中
        while (pTemp1) {
            *pTempOfNext = pTemp1;
            pTemp1 = pTemp1->next;
            pTempOfNext = &(*pTempOfNext)->next;
        }
        while (pTemp2) {
            *pTempOfNext = pTemp2;
            pTemp2 = pTemp2->next;
            pTempOfNext = &(*pTempOfNext)->next;
        }
        
        return pMergedHead;
    }
};

int main() {
    Solution s;

    ListNode* pHead1 = new ListNode(1);
    pHead1->next = new ListNode(3);
    pHead1->next->next = new ListNode(5);

    ListNode* pHead2 = new ListNode(2);
    pHead2->next = new ListNode(4);
    pHead2->next->next = new ListNode(6);

    printListNode(pHead1);
    printListNode(pHead2);

    ListNode* ret = s.Merge(pHead1, pHead2);

    printListNode(ret);

    return 0;
}