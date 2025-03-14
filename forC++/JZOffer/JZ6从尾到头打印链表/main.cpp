#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};

class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int> result;
        if (NULL == head) return result;
        // 栈存放已访问数据，然后取出，实现倒序
        stack<int> st;
        ListNode *p = head;
        while (p != NULL) {
            st.push(p->val);
            p = p->next;
        }
        while (!st.empty()) {
            result.push_back(st.top());
            st.pop();
        }
        return result;
    }
};


int main() {
    Solution s;

    ListNode input(1);
    input.next = new ListNode(2);
    input.next->next = new ListNode(3);

    vector<int> ret = s.printListFromTailToHead(&input);

    cout << "[";
    for (int i = 0; i < ret.size() - 1; i++) cout << ret[i] << ',';
    cout << ret.back() << "]" << endl;

    return 0;
}