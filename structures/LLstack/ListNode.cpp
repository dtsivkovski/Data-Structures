#include "ListNode.h"

ListNode::ListNode() {};

ListNode::ListNode(int d) {
    next = NULL;
    prev = NULL;
    data = d;
}

ListNode::~ListNode() {
    // you can research this
}