#ifndef BST_H
#define BST_H

#include<iostream>
using namespace std;

template <class T>
class TreeNode {
    public:
        TreeNode();
        TreeNode(T k);
        virtual ~TreeNode();

        T key; // key = data
        TreeNode<T> *left;
        TreeNode<T> *right;
};

template <class T>
TreeNode<T>::TreeNode() {
    left = NULL;
    right = NULL;
    key = NULL;
}

template <class T>
TreeNode<T>::TreeNode(T k) {
    left = NULL;
    right = NULL;
    key = k;
}

template <class T>
TreeNode<T>::~TreeNode() {
    left = NULL;
    right = NULL;
}

template <class T>
class BST {
    public:
        BST(); // empty tree
        virtual ~BST();
        void insert(T value);
        bool contains(T value);
        bool deleteNode(T k);
        TreeNode<T> *getSuccessor(TreeNode<T> *d); // this method for finding the successor of the node about to be deleted

        bool isEmpty();
        T* getMin();
        T* getMax();

        void printTree();
        void recPrint(TreeNode<T> *node);

    private:
        TreeNode<T> *root;
};

template <class T>
BST<T>::BST() {
    root = NULL;
}

template <class T>
BST<T>::~BST() {

}

template <class T>
void BST<T>::recPrint(TreeNode<T> *node) {
    if (node == null) return;

    cout << node->key << endl;
    recPrint(node->left);
    recPrint(node->right);
}

template <class T>
void BST<T>::printTree() {
    recPrint(root);
}

template <class T>
bool BST<T>::isEmpty() {
    return (root == NULL);
}

template <class T>
T* BST<T>::getMin() {
    if (isEmpty()) return NULL;

    TreeNode<T> *current = root;

    while (current->left != NULL) {
        current = current->left;
    }

    return &(current->key);
}

template <class T>
T* BST<T>::getMax() {
    if (isEmpty()) return NULL;

    TreeNode<T> *current = root;

    while (current->right != NULL) {
        current = current->right;
    }

    return &(current->key);
}

template <class T>
void BST<T>::insert(T value) {
    TreeNode<T> *node = new TreeNode<T>(value);

    if (isEmpty()) {
        root = node;
    }
    else {
        // tree had 1+ nodes
        TreeNode<T> *current = root;
        TreeNode<T> *parent = root;

        while(true) {
            parent = current;
            
            if (value < current) {
                // go left
                current = current->left;

                if (current == NULL) {
                    // found the insertion point
                    parent->left = node;
                    break;
                }

            }
            else {
                current = current->right;

                if (current == NULL) {
                    // isertion point
                    parent->right = node;
                    break;
                }
            }
        }
    }
}

template <class T>
bool BST<T>::contains(T value) {

    if (isEmpty()) return false;

    TreeNode<T> *current = root;

    while(current->key != value) {
        if (val < current->key) {
            current = current->left;
        }
        else {
            current = current->right;
        }

        if (current == NULL) return false;
    }
    return true;
}

template <class T>
bool BST<T>::deleteNode(T k) {
    if (isEmpty()) return false;

    TreeNode<T> *current = root;
    TreeNode<T> *parent = root;
    bool isLeft = true;

    // find the node to delete
    while (current->key != k) {
        parent = current;

        if (k < current->key) {
            isLeft = true;
            current = current->left;
        }
        else {
            isLeft = false;
            current = current->right;
        }

        if (current == NULL) return false;
    }

    // if we make it here, we have found the node to be deleted
    //! LEAF NODE CASE:
    if (current->left == NULL && current->right == NULL) {
        if (current == root) root = NULL; // null it if only node in tree
        else if (isLeft) {
            parent->left = NULL;
        }
        else {
            parent->right = NULL;
        }

    }
    //! ONE LEFT CHILD CASE:
    else if (current->right == NULL) {
        if (current == root) {
            root = current->left;
        }
        else if (isLeft) {
            parent->left = current->left;
        }
        else {
            parent->right = current->left;
        }
    }
    //! ONE RIGHT CHILD CASE:
    else if (current->left == NULL) {
        if (current == root) {
            root = current->right;
        }
        else if (isLeft) {
            parent->left = current->right;
        }
        else {
            parent->right = current->right;
        }
    }
    //! TWO CHILDREN CASE:
    else {
        TreeNode<T> *successor = getSuccessor(current);

        if (current == root) {
            root = successor;
        }
        else if (isLeft) {
            parent->left = successor;
        }
        else {
            parent->right = successor;
        }
        successor->left = current->left;
        current->left = NULL;
        current->right = NULL;
    }
    delete current;
    return true;

}

template <class T>
TreeNode<T>* BST<T>::getSuccessor(TreeNode<T> *d) {
    TreeNode<T> *sp = d;
    TreeNode<T> *successor = d;
    TreeNode<T> *current = d->right;

    // get variables in the right spot
    while (current != NULL) {
        sp = successor;
        successor = current;
        current = current->left;
    }

    // we found the successor, now check if successor is a descendant of the right child
    if (successor != d->right) {
        sp->left = successor->right;
        successor->right = d->right;
    }
    return successor;
}

#endif