#include <stdio.h>
#include <stdlib.h>

// Structure for a node
struct node {
    int key;
    struct node* left;
    struct node* right;
};

// Function to create a new node
struct node* createNode(int key) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->key = key;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a node
struct node* insertNode(struct node* root, int key) {
    if (root == NULL) {
        return createNode(key);
    }

    if (key < root->key) {
        root->left = insertNode(root->left, key);
    } else if (key > root->key) {
        root->right = insertNode(root->right, key);
    }

    return root;
}

// Function to delete a node
struct node* deleteNode(struct node* root, int key) {
    if (root == NULL) {
        return root;
    }

    if (key < root->key) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->key) {
        root->right = deleteNode(root->right, key);
    } else {
        if (root->left == NULL) {
            struct node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct node* temp = root->left;
            free(root);
            return temp;
        }

        struct node* temp = root->right;
        while (temp && temp->left != NULL) {
            temp = temp->left;
        }

        root->key = temp->key;
        root->right = deleteNode(root->right, temp->key);
    }

    return root;
}

// Function to perform inorder traversal
void inorderTraversal(struct node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->key);
        inorderTraversal(root->right);
    }
}

// Function to display the tree
void displayTree(struct node* root, int level) {
    if (root != NULL) {
        displayTree(root->right, level + 1);
        printf("\n");

        if (root == NULL) {
            for (int i = 0; i < level; i++) {
                printf("\t");
            }
        } else {
            for (int i = 0; i < level; i++) {
                printf("\t\t");
            }
            printf("%d", root->key);
        }

        displayTree(root->left, level + 1);
    }
}

// Main function
int main() {
    struct node* root = NULL;
    int choice, key;

    do {
        printf("Binary Search Tree Operations:\n");
        printf("1. Insert a node\n");
        printf("2. Delete a node\n");
        printf("3. Inorder traversal\n");
        printf("4. Display the tree\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the key to be inserted: ");
                scanf("%d", &key);
                root = insertNode(root, key);
                break;
            case 2:
                printf("Enter the key to be deleted: ");
                scanf("%d", &key);
                root = deleteNode(root, key);
                break;
            case 3:
                printf("Inorder traversal: ");
                inorderTraversal(root);
                printf("\n");
                break;
            case 4:
                printf("Displaying the tree:\n");
                displayTree(root, 0);
                printf("\n");
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 5);

    return 0;
}