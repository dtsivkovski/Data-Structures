#include <iostream>
#include "SingleLinkedList.h"

int main(int argc, char **argv) {

    SingleLinkedList *sll = new SingleLinkedList;

    sll->insertFront(4);
    sll->insertFront(44);
    sll->insertBack(56);
    sll->insertBack(67);

    sll->deleteAtPos(1);
    cout << sll->find(44) << endl;

    delete sll;

}