#include "../header.h"

struct LinkNode {
    LinkNode * next;
    int val;
    LinkNode(int val): val(val) {};
};

class MyLinkedList {
public:

    LinkNode * head;
    int length;

    MyLinkedList() {
        this->head = nullptr;
        this->length = 0;             
    }
    
    int get(int index) {
        LinkNode * node = this->getNode(index);
        return (node) ? node->val : -1;
    }

    LinkNode * getNode(int index) {
        if (index < 0) return nullptr;
        LinkNode * curNode = this->head;
        int i = 0;
        while(curNode) {
            if (i == index) return curNode;
            curNode = curNode->next;
            i++;
        }
        return nullptr;
    }
    
    void addAtHead(int val) {
        this->addAtIndex(0, val);
    }
    
    void addAtTail(int val) {
        this->addAtIndex(this->length, val);
    }

    void addAtIndex(int index, int val) {
        LinkNode * newNode = new LinkNode(val);
        if (index == 0) {
            newNode->next = this->head;
            this->head = newNode;          
        } else if (index > 0) {
            LinkNode * curNode = this->getNode(index);
            LinkNode * preNode = this->getNode(index - 1);
            if (!preNode) return;
            newNode->next = curNode;
            preNode->next = newNode;
        }
        this->length ++;
    }
    
    void deleteAtIndex(int index) {
        LinkNode * curNode = this->getNode(index);
        if (!curNode) return;
        if (index == 0) {
            this->head = curNode->next;
            curNode->next = nullptr;
        } else if (index > 0) {
            LinkNode * preNode = this->getNode(index - 1);
            preNode->next = curNode->next;
            curNode->next = nullptr;
        }
        this->length--;
    }
};

void Test::test707() {


}