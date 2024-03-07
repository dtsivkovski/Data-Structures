#include <iostream>
#include "LinkedList.h"

int main(int argc, char **argv) {

    LinkedList *ll = new LinkedList;

    ll->insertFront(4);
    ll->insertFront(44);
    ll->insertBack(56);
    ll->insertBack(67);

    ll->removeNode(1);
    cout << ll->find(44) << endl;

    delete ll;

}