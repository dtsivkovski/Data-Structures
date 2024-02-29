#include "SingleLinkedList.h"

SingleLinkedList::SingleLinkedList() {
    // create an empty list
    front = NULL;
    back = NULL;
    size = 0;
}

SingleLinkedList::~SingleLinkedList() {
    // another character building exercise
}

void SingleLinkedList::insertFront(int d) {
    ListNode *node = new ListNode(d);

    if (isEmpty()) {
        back = node;
    }
    else {
        // it's not an empty list
        node->next = front;
    }
    front = node;
    size++;
}

void SingleLinkedList::insertBack(int d) {
    ListNode *node = new ListNode(d)        ;

    if (isEmpty())                            {
        front = node                        ;
                                            }
    else                                    {
        back->next = node                   ;
                                            }
    back = node                             ;
    size++                                  ;
                                            }

bool SingleLinkedList::isEmpty() {
    return (size == 0);
}

unsigned int SingleLinkedList::getSize() {
    return size;
}

int SingleLinkedList::removeFront() {
    
    if (isEmpty()) {
        cerr << "list is empty" << endl;
        return -1;
    }

    int temp = front->data;
    ListNode *ft = front;

    front = front->next;
    ft->next = NULL;
    delete ft;

    if (size == 1) {
        back = NULL;
    }

    size--;
    return temp;

}

int SingleLinkedList::find(int value) {
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

int SingleLinkedList::deleteAtPos(int pos) {

    // check if empty and then check that pos is valid
    if (isEmpty()) {
        cerr << "List is empty" << endl;

    }

    int count = 0;
    ListNode *curr = front;
    ListNode *prev = front;

    while (count != pos) {
        prev = curr;
        curr = curr->next;
        count++;
    }
    if (curr == front) {
        front = curr->next;
    }
    if (curr == back) {
        back = prev;
    }
    if (curr != front && curr != back) {
        prev->next = curr->next;
    }

    curr->next = NULL;
    int temp = curr->data;
    size--;
    
    delete curr;

    return temp;
}




