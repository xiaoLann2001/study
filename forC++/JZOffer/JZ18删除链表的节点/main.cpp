#include <bits/stdc++.h>

using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param head ListNode类 
     * @param val int整型 
     * @return ListNode类
     */
    ListNode* deleteNode(ListNode* head, int val) {
        // 若链表为空
        if (!head) return NULL;
        
        // 查找 val
        ListNode *p = head;
        ListNode *dummy = new ListNode(-1); // 虚拟头节点保证原来链表的头节点也可被删除
        dummy->next = head;
        ListNode *pre = dummy;
        while (p) {
            if (p->val == val) {
                // 删除链表节点，即当前节点的上一个节点指向当前节点的下一个节点
                pre->next = p->next;
                free(p);
                break;
            } 
            p = p->next;
            pre = pre->next;
        }
        ListNode *result = dummy->next;
        free(dummy);
        return result;
    }
};

int main() {
    Solution s;

    ListNode* pHead = new ListNode(2);
    pHead->next = new ListNode(5);
    pHead->next->next = new ListNode(1);
    pHead->next->next->next = new ListNode(9);

    int val = 5;

    ListNode* ret = s.deleteNode(pHead, val);

    ListNode* pNode = ret;
    while (pNode) {
        cout << pNode->val << endl;
        pNode = pNode->next;
    }

    return 0;
}