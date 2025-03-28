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
     * @param head ListNode类 
     * @return ListNode类
     */
    ListNode* ReverseList(ListNode* head) {
        // 空链表，或只有一个节点
        if (!head || !(head->next)) return NULL;

        // 用三个指针记录，前一个节点指针，当前节点指针，后一个节点指针
        ListNode* pPrev = NULL;
        ListNode* pNode = head;
        ListNode* pNext = NULL;

        while (pNode) {
            pNext = pNode->next;    // 备份下一个节点
            pNode->next = pPrev;    // 将当前节点的next指针指向上一个节点
            pPrev = pNode;          // 备份当前节点为上一个节点
            pNode = pNext;          // 将当前节点移动到下一个节点
        }

        return pPrev;
    }
};

int main() {
    Solution s;

    ListNode* pHead = new ListNode(1);
    pHead->next = new ListNode(2);
    pHead->next->next = new ListNode(3);

    printListNode(pHead);

    ListNode* ret = s.ReverseList(pHead);

    printListNode(ret);

    return 0;
}