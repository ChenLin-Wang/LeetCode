#include "header.h"

struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

ListNode* Solution::reverseList(ListNode* head) {
    ListNode * curNode = head;
    ListNode * preNode = nullptr;
    ListNode * x;
    while (curNode) {
        x = new ListNode(curNode->val);
        x->next = preNode;
        preNode = x;
        curNode = curNode->next;
    }
    return x;
}



void Test::test206() {
    vector<int> list = {1,2,3,4,5};
    ListNode * inp = nullptr;
    for (int i = list.size() - 1; i >= 0; i--) {
        int x = list[i];
        inp = new ListNode(x, inp);
    }
    auto res = Solution::reverseList(inp);
    while(res) {
        cout << res->val << endl;
        res = res->next;
    }
}