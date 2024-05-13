#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 给你一个链表的头节点 head 和一个整数 val ，请你删除链表中所有满足 Node.val == val 的节点，并返回 新的头节点 。

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


// 直接使用原来的链表来进行删除操作
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if (nullptr == head) return nullptr;
        
        ListNode *result;
        ListNode *p = head;         // 删除头节点的操作有所不同，因为头节点没有前驱，将头指针后移，便可删除头节点
        while (p != nullptr && p->val == val) {
            ListNode *temp = p;
            p = p->next;
            delete(temp);
        }
        result = p;

        // while (p != nullptr)     // 为了删除当前元素，需要保存前一个结点的指针
                                    // 所以用p->next != nullptr作为条件，来遍历
                                    // 但是这样到倒数第二个元素访问之后，p = p->next = nullptr,
                                    // 再进入(p->next != nullptr)就会越界访问
                                    // 使用p->next != nullptr也有这个问题
        // while (p != nullptr && p->next != nullptr)  // 1.直接做两个判断，利用惰性求值，屏蔽掉越界访问
        while (p->next != nullptr) {
            if (p->next->val == val) {          // 如果有连续两个需要删除的，会跳过第二个
                ListNode *temp = p->next;
                p->next = p->next->next;
                delete(temp);
            }
            // p = p->next; // 1
            else {          // 2.若不删除才前进，防止跳过待删除的节点
                p = p->next;
            }
        }

        return result;
    }
};

// 设置一个虚拟头结点再进行统一删除操作
class Solution1 {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *dummy = new ListNode();
        dummy->next = head;
        ListNode *p = dummy;
        while (p->next != nullptr) {
            if (p->next->val == val) {
                ListNode* temp = p->next;
                p->next = p->next->next;
                delete temp;
            } else {
                p = p->next;
            }
        }
        return dummy->next;
    }
};

int main(){
    Solution1 s;

    int array[] = {1,2,6,3,4,5,6};
    // 将数组转换为链表，链表头节点也有数据
    ListNode *head = new ListNode(array[0]);
    ListNode *p = head;
    for(int i = 1; i < sizeof(array)/sizeof(array[0]); i++){
        ListNode *node = new ListNode(array[i]);
        p->next = node;
        p = p->next;
    }
    p->next = nullptr;

    ListNode *res = s.removeElements(head, 2);

    while(res != nullptr){
        cout << res->val << " ";
        res = res->next;
    }
    cout << endl;
    

    return 0;
}