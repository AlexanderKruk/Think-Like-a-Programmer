#include <iostream>
using namespace std;

class binaryTree {
    public:
        int publicLeafCount();
    private:
        struct  binaryTreeNode {
            int data;
            binaryTreeNode * left;
            binaryTreeNode * right;
        };
        typedef binaryTreeNode * treePtr;
        treePtr _root;
        int privateLeafCount(treePtr rootPtr);
};

int binaryTree::privateLeafCount(treePtr rootPtr) {
    if (rootPtr == NULL) return 0;
    if (rootPtr -> right == NULL && rootPtr -> left == NULL)
        return 1;
    int leftCount = privateLeafCount(rootPtr -> left);
    int rightCount = privateLeafCount(rootPtr -> right);
    return leftCount + rightCount;
}

int binaryTree::publicLeafCount(){
    return privateLeafCount(_root);
}

struct binaryTreeNode {
    int data;
    binaryTreeNode * left;
    binaryTreeNode * right;
};
typedef binaryTreeNode * treePtr;
int leafCount(treePtr rootPtr) {
    if (rootPtr == NULL) return 0;
    if (rootPtr -> right == NULL && rootPtr -> left == NULL)
        return 1;
    int leftCount = leafCount(rootPtr -> left);
    int rightCount = leafCount(rootPtr -> right);
    return leftCount + rightCount;
}