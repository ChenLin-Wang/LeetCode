#include "../header.h"

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* Solution::addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode * n1 = l1, * n2 = l2, * res, * cur = nullptr;
    int i = 0;
    int carry = 0;
    bool n1Null = false;
    bool n2Null = false;
    while(true) {
        int r = n1->val + n2->val + carry;
        if (cur == nullptr) {
            cur = new ListNode(r % 10);
            res = cur;
        } else {
            ListNode * temp = new ListNode(r % 10);
            cur->next = temp;
            cur = temp;
        }
        carry = r / 10;

        if (n1->next == nullptr) {
            n1 = new ListNode(0);
            n1Null = true;
        } else n1 = n1->next;
        if (n2->next == nullptr) {
            n2 = new ListNode(0);
            n2Null = true;
        } else n2 = n2->next;
        if (n1Null && n2Null) break;
    }
    if (carry == 1) {
        cur->next = new ListNode(1);
    }
    return res;
}

void Test::test2() {

}