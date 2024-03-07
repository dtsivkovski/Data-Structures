#ifndef LISTNODE_H
#define LISTNODE_H

#include <iostream>
#include <exception>

using namespace std;

class ListNode {
    
    public:
        ListNode();
        ListNode(int d);
        ~ListNode();
        int data;
        ListNode *next;
        ListNode *prev;

};

#endif