#include <iostream>
// #include "header.h"

// using namespace std;


typedef struct LinkNode {
    int val;
    LinkNode * next;
} LinkNode;

LinkNode makeLinkNode(int val, LinkNode * next) {
    LinkNode node;
    node.val = val;
    node.next = next;
    return node;
}

int main() {

    LinkNode firstNode = makeLinkNode(1, nullptr);
    LinkNode * node = &firstNode;

    printf("%d", node->val);

    // Test::test328();
    return 0;
} 