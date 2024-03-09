#include "header.h"

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* Solution::reverseKGroup(ListNode* head, int k) {
    ListNode * curNode = head;
    ListNode * res = nullptr;
    ListNode * partNode = nullptr;
    ListNode * lastPartN = nullptr;
    int i = 0;
    int length = 0;
    while (curNode) { curNode = curNode->next; length ++; }
    curNode = head;
    while (curNode) {
        ListNode * lNode = lastPartN;
        if (i + k > length) { lNode->next = curNode; break; }
        if (i % k != 0) { i ++; continue; }
        partNode = nullptr;
        for (int j = 0; j < k; j++) {
            if (!curNode) break;
            ListNode * newNode = new ListNode(curNode->val, partNode);
            if (j == 0) lastPartN = newNode;
            partNode = newNode;
            curNode = curNode->next;
        }
        if (i == 0) res = partNode;
        if (lNode) lNode->next = partNode;
        i ++;
    }
    return res;
}

void Test::test25() {
    vector<int> list = {1,2,3,4,5};
    ListNode * inp = nullptr;
    for (int i = list.size() - 1; i >= 0; i--) {
        int x = list[i];
        inp = new ListNode(x, inp);
    }
    auto res = Solution::reverseKGroup(inp, 3);
    while(res) {
        cout << res->val << endl;
        res = res->next;
    }
}