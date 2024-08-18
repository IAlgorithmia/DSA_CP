#include <stdio.h>

struct Node {
    int data;
    struct Node* next;
};

void insertNode(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* curr = *head;
        while (curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = newNode;
    }
}

void mergeLinkedLists(struct Node** head1, struct Node** head2) {
    if (*head1 == NULL) {
        *head1 = *head2;
        return;
    }
    if (*head2 == NULL) {
        return;
    }

    struct Node* curr1 = *head1;
    struct Node* curr2 = *head2;
    struct Node* prev = NULL;

    while (curr1 != NULL && curr2 != NULL) {
        if (curr1->data <= curr2->data) {
            prev = curr1;
            curr1 = curr1->next;
        } else {
            struct Node* temp = curr2;
            curr2 = curr2->next;

            temp->next = curr1;
            if (prev != NULL) {
                prev->next = temp;
            } else {
                *head1 = temp;
            }
            prev = temp;
        }
    }

    if (curr2 != NULL) {
        prev->next = curr2;
    }
}

void displayLinkedList(struct Node* head) {
    struct Node* curr = head;
    while (curr != NULL) {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");
}

int main() {
    struct Node* head1 = NULL;
    insertNode(&head1, 1);
    insertNode(&head1, 3);
    insertNode(&head1, 5);

    struct Node* head2 = NULL;
    insertNode(&head2, 2);
    insertNode(&head2, 4);
    insertNode(&head2, 6);

    printf("Linked List 1: ");
    displayLinkedList(head1);
    printf("Linked List 2: ");
    displayLinkedList(head2);

    mergeLinkedLists(&head1, &head2);

    printf("Merged Linked List: ");
    displayLinkedList(head1);

    return 0;
}
