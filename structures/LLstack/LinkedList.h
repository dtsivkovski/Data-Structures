#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "ListNode.h"

class LinkedList {
    private:
        unsigned int size;
        ListNode *front;
        ListNode *back;

    public:
        LinkedList();
        ~LinkedList();
        // insert and remove
        void insertFront(int d);
        void insertBack(int d);
        int removeFront();
        int removeBack();
        int find(int value);
        int getFront();
        int removeNode(int value);
        // aux
        bool isEmpty();
        unsigned int getSize();

        void printList(bool printLink);
};

#endif