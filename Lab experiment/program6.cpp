/**
 * 
 * Write a program to insert an element in binary search tree.
 * 
 * Author: Shourya Gupta 
 * Copyright: ShouryaBrahmastra
 * 
 * **/
#include <iostream>
using namespace std;


struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
};


TreeNode* createNode(int data) {
    TreeNode* newNode = new TreeNode();
    if (!newNode) {
        cout << "Memory error\n";
        return NULL;
    }
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}


TreeNode* insertNode(TreeNode* root, int data) {
    
    if (root == NULL) {
        root = createNode(data);
        return root;
    }


    if (data < root->data) {
        root->left = insertNode(root->left, data);
    } else {
        root->right = insertNode(root->right, data);
    }

    return root;
}


void preOrder(TreeNode* temp) {
    if (temp == NULL) {
        return;
    }
    cout << temp->data << " ";
    preOrder(temp->left);
    preOrder(temp->right);
}

int main() {
    TreeNode* root = NULL;
    int values[] = { 50, 30, 20, 40, 70, 60, 80 };
    int n = sizeof(values)/sizeof(values[0]);

    for (int i = 0; i < n; i++) {
        root = insertNode(root, values[i]);
    }

    cout << "Pre-order traversal: ";
    preOrder(root);
    cout << endl;

    int valueToInsert;
    cout << "Enter a value to insert into the BST: ";
    cin >> valueToInsert;

    root = insertNode(root, valueToInsert);

    cout << "Pre-order traversal after insertion: ";
    preOrder(root);
    cout << endl;

    return 0;
}
