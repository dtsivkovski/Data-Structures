#include "LinkedList.h"

LinkedList::LinkedList() {
    front = NULL;
    back = NULL;
    size = 0;
}

LinkedList::~LinkedList() {
    // you guessed it, research it
    // HINT: use a loop
    ListNode *node = front;
    ListNode *toBeDeleted = front;
    while (node != NULL) {
        // no need to NULL pointers for this since we're deleting everything anyway
        toBeDeleted = node->next;
        delete node;
        node = toBeDeleted;
    }
}

void LinkedList::insertFront(int d) {
    ListNode *node = new ListNode(d); // create node with int value

    if (isEmpty()) {
        back = node;
    }
    else {
        // not an empty list
        node->next = front;
        front->prev = node;
    }
    front = node;
    ++size;
}

int LinkedList::find(int value) {
    int pos = -1;
    ListNode *curr = front;

    while (curr != NULL) {

        ++pos;
        if (curr->data == value) {
            break;
        }
        curr = curr->next;

    }
    if (curr == NULL) {
        pos = -1;
    }

    return pos;
}

void LinkedList::insertBack(int d) {
    ListNode *node = new ListNode(d);

    if (isEmpty()) {
        front = node;
    }
    else {
        node->prev = back;
        back->next = node;
    }
    back = node;
    ++size;
    
}

int LinkedList::removeFront() {
    
    if (isEmpty()) {
        throw runtime_error("List is empty");
    }

    ListNode *temp = front;

    if (front->next == NULL) {
        back = NULL;
    }
    else {
        // node to be removed is not the only one
        front->next->prev = NULL;
    }
    front = front->next;
    temp->next = NULL;
    int data = temp->data;
    --size;
    delete temp;

    return data;
}

int LinkedList::removeBack() {

    if (isEmpty()) {
        throw runtime_error("list is empty");
    }

    ListNode *temp = back;
    if (back->prev == NULL) {
        front = NULL;
    }
    else {
        // more than one node in list
        back->prev->next = NULL;
    }
    back = back->prev;
    temp->prev = NULL;
    int data = temp->data;
    --size;
    delete temp;

    return data;
}

int LinkedList::removeNode(int value) {
    // continue this

    if (isEmpty()) {
        throw runtime_error("List is empty");
    }
    
    ListNode *curr = front;
    while (curr->data != value) {
        curr = curr->next;

        if (curr == NULL) return -1;
    }
    // if we get here, then curr should be at the position of the node to be deleted
    if (curr == front) {
        front = curr->next;
        front->prev = NULL;
    }
    if (curr == back) {
        back = curr->prev;
        back->next = NULL;
    }
    else {
        // node must be between front and back
        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;
    }

    curr->next = NULL;
    curr->prev = NULL;

    int temp = curr->data;
    --size;
    delete curr;
    return temp;
}

unsigned int LinkedList::getSize() {
    return size;
}

bool LinkedList::isEmpty() {
    return (size == 0);
}


