#include <stdio.h>
#include <stdlib.h>

// Structure for a linked list node
struct Node {
    int data;
    struct Node* next;
};

// Function to insert a node at the end of a linked list
void append(struct Node** headRef, int newData) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    struct Node* last = *headRef;

    newNode->data = newData;
    newNode->next = NULL;

    if (*headRef == NULL) {
        *headRef = newNode;
        return;
    }

    while (last->next != NULL)
        last = last->next;

    last->next = newNode;
}

// Function to split a linked list into two lists based on positive and negative values
void splitLinkedList(struct Node* head, struct Node** positiveList, struct Node** negativeList) {
    struct Node* positivePtr = NULL;
    struct Node* negativePtr = NULL;

    while (head != NULL) {
        if (head->data >= 0) {
            if (*positiveList == NULL) {
                *positiveList = head;
                positivePtr = *positiveList;
            } else {
                positivePtr->next = head;
                positivePtr = positivePtr->next;
            }
        } else {
            if (*negativeList == NULL) {
                *negativeList = head;
                negativePtr = *negativeList;
            } else {
                negativePtr->next = head;
                negativePtr = negativePtr->next;
            }
        }

        head = head->next;
    }

    if (positivePtr != NULL)
        positivePtr->next = NULL;

    if (negativePtr != NULL)
        negativePtr->next = NULL;
}

// Function to print a linked list
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

// Function to free memory allocated to a linked list
void freeList(struct Node* node) {
    struct Node* temp;

    while (node != NULL) {
        temp = node;
        node = node->next;
        free(temp);
    }
}

// Main function
int main() {
    struct Node* head = NULL;
    struct Node* positiveList = NULL;
    struct Node* negativeList = NULL;

    // Example list: 1 -> -2 -> 3 -> -4 -> 5 -> NULL
    append(&head, 1);
    append(&head, -2);
    append(&head, 3);
    append(&head, -4);
    append(&head, 5);

    printf("Original Linked List: ");
    printList(head);

    splitLinkedList(head, &positiveList, &negativeList);

    printf("Positive Value Linked List: ");
    printList(positiveList);

    printf("Negative Value Linked List: ");
    printList(negativeList);

    // Free memory
    freeList(head);
    freeList(positiveList);
    freeList(negativeList);

    return 0;
}
