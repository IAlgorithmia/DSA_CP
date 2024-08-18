#include <stdio.h>
#include <stdlib.h>

// Linked List Node
struct Node {
    int data;
    struct Node* next;
};

// Function to insert a node at the beginning of the linked list
void push(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

// Function to split the linked list into two lists
void splitLinkedList(struct Node* head, struct Node** oddList, struct Node** evenList) {
    struct Node* odd = NULL; // Head of the odd list
    struct Node* even = NULL; // Head of the even list
    struct Node* oddTail = NULL; // Tail of the odd list
    struct Node* evenTail = NULL; // Tail of the even list
    int count = 1;

    while (head != NULL) {
        if (count % 2 != 0) { // Odd position
            if (odd == NULL) {
                odd = head;
                oddTail = head;
            } else {
                oddTail->next = head;
                oddTail = oddTail->next;
            }
        } else { // Even position
            if (even == NULL) {
                even = head;
                evenTail = head;
            } else {
                evenTail->next = head;
                evenTail = evenTail->next;
            }
        }
        head = head->next;
        count++;
    }
    if (oddTail != NULL)
        oddTail->next = NULL;
    if (evenTail != NULL)
        evenTail->next = NULL;
    *oddList = odd;
    *evenList = even;
}
// Function to print a linked list
void printLinkedList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// Function to free the memory allocated for the linked list
void freeLinkedList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    struct Node* head = NULL;
    struct Node* oddList = NULL;
    struct Node* evenList = NULL;

    // Create the linked list
    push(&head, 9);
    push(&head, 7);
    push(&head, 5);
    push(&head, 3);
    push(&head, 1);

    printf("Original Linked List: ");
    printLinkedList(head);

    splitLinkedList(head, &oddList, &evenList);

    printf("Odd Position List: ");
    printLinkedList(oddList);

    printf("Even Position List: ");
    printLinkedList(evenList);

    // Free the memory allocated for the linked lists
    freeLinkedList(oddList);
    freeLinkedList(evenList);

    return 0;
}
