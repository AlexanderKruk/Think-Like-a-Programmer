#include <iostream>
using namespace std;

struct binaryTreeNode {
    int data;
    binaryTreeNode * left;
    binaryTreeNode * right;
};
typedef binaryTreeNode * treePtr;

void initialization(treePtr &root);
int maxValue(treePtr root);
void insert(treePtr &current, int key);

int main() {
    treePtr root;
    initialization(root);
    insert(root, 55);
    cout << maxValue(root);
}

void insert(treePtr &current, int key){
    if(current == NULL)
    {
        binaryTreeNode *newnode = new binaryTreeNode;
        newnode->data = key;
        newnode->left = NULL;
        newnode->right = NULL;
        current = newnode;
        newnode = NULL;
    }
    else{
        if(key<current->data)
            insert(current->left, key);
        else
            insert(current->right, key);
    }
    return;
}

int maxValue(treePtr root){
    if(root == NULL) return 0;
    if(root-> right == NULL && root -> left == NULL) return root -> data;
    int leftMax = maxValue(root -> left);
    int rightMax = maxValue(root -> right);
    int maxNum = root -> data;
    if (leftMax > maxNum) maxNum = leftMax;
    if (rightMax > maxNum) maxNum = rightMax;
    return maxNum;
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