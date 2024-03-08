#include "header.h"

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


ListNode * Solution::deleteDuplicates(ListNode * head) {
    if (!head) return head;
    ListNode * curNode = head;
    ListNode * numLead = curNode;
    while (curNode) {
        if (numLead->val != curNode->val) {
            numLead->next = curNode;
            numLead = curNode;
        }
        curNode = curNode->next;
    }
    numLead->next = nullptr;
    return head;
}


void Test::test83() {
    vector<int> list = {1, 1, 2, 3, 3};
    ListNode * inp = nullptr;
    for (int i = list.size() - 1; i >= 0; i--) {
        int x = list[i];
        inp = new ListNode(x, inp);
    }
    auto res = Solution::deleteDuplicates(inp);
    while(res) {
        cout << res->val << endl;
        res = res->next;
    }
}