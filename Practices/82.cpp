#include "header.h"

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


ListNode * Solution::deleteDuplicates2(ListNode * head) {
    if (!head) return head;
    ListNode * curNode = head;
    ListNode * preNode = nullptr;
    ListNode * curLead = nullptr;
    ListNode * res = nullptr;
    int i = -1;
    bool jump = false;
    while (curNode) {
        i++;
        if (curLead && curLead->val == curNode->val) {
            jump = true;
        } else {
            if (!jump && preNode) preNode->next = curLead; 
            if (!jump) preNode = curLead;
            if (!jump && !res) res = curLead;
            curLead = curNode;
            jump = false;
        }
        curNode = curNode->next;
    }
    if (!jump && preNode) preNode->next = curLead;
    if (jump && preNode) preNode->next = nullptr;
    if (!jump) preNode = curLead;
    if (!jump && !res) res = curLead;
    curLead->next = nullptr;
    return res;
}


void Test::test82() {
    vector<int> list = {1,2,2};
    ListNode * inp = nullptr;
    for (int i = list.size() - 1; i >= 0; i--) {
        int x = list[i];
        inp = new ListNode(x, inp);
    }
    auto res = Solution::deleteDuplicates2(inp);
    while(res) {
        cout << res->val << endl;
        res = res->next;
    }
}