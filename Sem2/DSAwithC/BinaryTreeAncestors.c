#include <stdio.h>
#include <stdlib.h>

// Structure for a binary tree node
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Function to create a new binary tree node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to find ancestors of a given node
int findAncestors(Node* root, int key) {
    // Base case: If tree is empty or key is present at the root
    if (root == NULL)
        return 0;

    if (root->data == key)
        return 1;

    // If the key is present in the left or right subtree
    // or if it is one of the ancestors
    if (findAncestors(root->left, key) || findAncestors(root->right, key)) {
        printf("%d ", root->data);
        return 1;
    }

    // Key is not present in the tree
    return 0;
}

int main() {
    // Create the binary tree
    Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    int key = 5;
    printf("Ancestors of %d are: ", key);
    findAncestors(root, key);

    return 0;
}