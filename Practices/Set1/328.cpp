#include "../header.h"

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* Solution::oddEvenList(ListNode* head) {
    if (!head) return nullptr;
    ListNode * firstEven = head->next;
    ListNode * lastOdd = nullptr;
    ListNode * lastEven = nullptr;
    ListNode * curNode = head;
    int i = 0;
    while(curNode) {
        if (i % 2 == 1) {   
            if (lastEven) lastEven->next = curNode;
            lastEven = curNode;
        } else {
            if (lastOdd) lastOdd->next = curNode;
            lastOdd = curNode;
        }
        curNode = curNode->next;
        i ++;
    }
    if (lastEven) lastEven->next = nullptr;
    lastOdd->next = firstEven;
    return head;
}


void Test::test328() {
    vector<int> list = {1};
    ListNode * inp = nullptr;
    for (int i = list.size() - 1; i >= 0; i--) {
        int x = list[i];
        inp = new ListNode(x, inp);
    }
    auto res = Solution::oddEvenList(inp);
    while(res) {
        cout << res->val << endl;
        res = res->next;
    }
}