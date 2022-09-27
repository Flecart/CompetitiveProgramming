#include <iostream>

struct Node {
    int leftNodes;
    int rightNodes;
    int val;
    Node *left;
    Node *right;
};

class Heap {
private:
    Node *head;
    Node *createNode(int n);
    void bubbleToLeaf(); // gets the head to the leaf and deletes
public:
    void insert(int n);
    int extractMax();
    Heap(int n);
    Heap();
};

Node *Heap::createNode(int n) {
    Node *node = new Node;
    node = new Node;
    node->leftNodes = 0;
    node->rightNodes = 0;
    node->val = n;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void Heap::bubbleToLeaf() {
    Node *oldhead = this->head;
    while(oldhead->left != NULL || oldhead->right != NULL) {
        if (oldhead->leftNodes <= oldhead->rightNodes) {
            oldhead->leftNodes -= 1;
            if (oldhead->left != NULL) std::swap(oldhead->val, oldhead->left->val);
            
            

        }
    }
}

Heap::Heap(int n) {
    this->head = createNode(n);
}

Heap::Heap() {
    this->head = NULL;
}

void Heap::insert(int n) {
    Node *head = this->head;
    if (head == NULL) {
        head = createNode(n);
        return;
    }
    Node *currNode = head;
    while(true) {
        if (currNode->left == NULL) {
            currNode->left = createNode(n);
            currNode->leftNodes += 1;
            break;
        } else if (currNode->right == NULL) {
            currNode->right = createNode(n);
            currNode->rightNodes += 1;
            break;
        }

        if (currNode->leftNodes <= currNode->rightNodes) {
            currNode->leftNodes += 1;
            currNode = currNode->left;
        } else {
            currNode->rightNodes += 1;
            currNode = currNode->right;
        }
    }
}

int Heap::extractMax() {
    Node *head = this->head;
    if (head == NULL) {
        throw std::invalid_argument( "head of the heap is null" );
    }
    int returnValue = this->head->val;

}