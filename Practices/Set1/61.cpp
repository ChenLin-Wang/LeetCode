#include "../header.h"

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode * reverse(ListNode * head) {
    ListNode * curNode = head;
    ListNode * newHead = nullptr;
    while (curNode) {
        ListNode * newNode = new ListNode(curNode->val, newHead);
        newHead = newNode;
        curNode = curNode->next;
    }
    return newHead;
}

ListNode* Solution::rotateRight(ListNode * head, int k) {
    if (!head) return head;
    int length = 0;
    ListNode * curNode = head;
    while (curNode) {
        curNode = curNode->next;
        length ++;
    }
    int l = k % length;
    if (l == 0) return head;

    ListNode * newHead = reverse(head);

    curNode = newHead;
    ListNode * head2 = nullptr;

    int i = 0;
    while (curNode) {
        if (i == l - 1) break;
        curNode = curNode->next;
        i ++;
    }
    head2 = curNode->next;
    curNode->next = nullptr;
    
    newHead = reverse(newHead);
    head2 = reverse(head2);

    curNode = newHead;
    while (curNode->next) curNode = curNode->next;
    curNode->next = head2;

    return newHead;
}



void Test::test61() {
    vector<int> list = {1, 2, 3, 4, 5};
    ListNode * inp = nullptr;
    for (int i = list.size() - 1; i >= 0; i--) {
        int x = list[i];
        inp = new ListNode(x, inp);
    }
    auto res = Solution::rotateRight(inp, 2);
    while(res) {
        cout << res->val << endl;
        res = res->next;
    }
 }
