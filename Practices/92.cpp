#include "header.h"

struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

ListNode* Solution::reverseBetween(ListNode* head, int left, int right) {
    if (right - left == 0) return head;
    ListNode * curNode = head;
    ListNode * rightNode = nullptr;
    ListNode * midNode = nullptr;
    ListNode * leftNode = nullptr;
    int i = 0;
    while (curNode) {
        if (i == left - 2) leftNode = curNode; 
        else if (i == left - 1) midNode = curNode;
        else if (i == right - 1) {
            rightNode = curNode->next; 
            curNode->next = nullptr;
            break;
        }
        i ++;
        curNode = curNode->next;
    }

    ListNode * reversed = nullptr;
    ListNode * preNode = nullptr;
    while (midNode) {
        if (!reversed) reversed = new ListNode(midNode->val, rightNode);
        else reversed = new ListNode(midNode->val, preNode);
        preNode = reversed;
        midNode = midNode->next;
    }

    if (leftNode) leftNode->next = reversed;
    else return reversed;
    return head;
}


void Test::test92() {
    vector<int> list = {3, 5};
    ListNode * inp = nullptr;
    for (int i = list.size() - 1; i >= 0; i--) {
        int x = list[i];
        inp = new ListNode(x, inp);
    }
    auto res = Solution::reverseBetween(inp, 1, 2);
    while(res) {
        cout << res->val << endl;
        res = res->next;
    }
}