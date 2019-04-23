#include <iostream>
using namespace std;

struct binaryTreeNode {
    int data;
    binaryTreeNode * left;
    binaryTreeNode * right;
};
typedef binaryTreeNode * treePtr;

void initialization(treePtr &root);
bool heap(treePtr root);

int main() {
    treePtr root;
    initialization(root);
    cout << heap(root);
}

bool heap(treePtr root){
    if(root == NULL) return true;
    if(root-> right == NULL && root -> left == NULL) return true;
    bool leftMax = heap(root -> left);
    bool rightMax = heap(root -> right);
    int parent = root -> data;
    treePtr children1 = root -> left;
    treePtr children2 = root -> right;
    if(children1->data < parent && children2->data > parent && leftMax && rightMax) return true;
    else return false;
}

void initialization(treePtr &root){
  binaryTreeNode * node1 = new binaryTreeNode;
  binaryTreeNode * node2 = new binaryTreeNode;
  binaryTreeNode * node3 = new binaryTreeNode;
  binaryTreeNode * node4 = new binaryTreeNode;
  binaryTreeNode * node5 = new binaryTreeNode;
  node1->data = 10;
  node2->data = 7;
  node3->data = 11;
  node4->data = 6;
  node5->data = 8;
  root = node1;
  node1->left = node2;
  node1->right = node3;
  node2->left = node4;
  node2->right = node5;
  node3->left = NULL;
  node3->right = NULL;
  node4->left = NULL;
  node5->right = NULL;
  node1 = node2 = node3 = node4 = node5 = NULL;
}