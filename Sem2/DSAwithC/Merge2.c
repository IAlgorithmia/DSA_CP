#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void insertNode(struct Node** head, int value) {
    struct Node* newNode = createNode(value);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

void displayList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

struct Node* mergeLists(struct Node* list1, struct Node* list2) {
    struct Node* mergedList = NULL;
    struct Node* tail = NULL;

    while (list1 != NULL && list2 != NULL) {
        if (list1->data <= list2->data) {
            if (mergedList == NULL) {
                mergedList = tail = list1;
            } else {
                tail->next = list1;
                tail = list1;
            }
            list1 = list1->next;
        } else {
            if (mergedList == NULL) {
                mergedList = tail = list2;
            } else {
                tail->next = list2;
                tail = list2;
            }
            list2 = list2->next;
        }
    }

    if (list1 != NULL) {
        if (mergedList == NULL) {
            mergedList = list1;
        } else {
            tail->next = list1;
        }
    }

    if (list2 != NULL) {
        if (mergedList == NULL) {
            mergedList = list2;
        } else {
            tail->next = list2;
        }
    }

    return mergedList;
}

int main() {
    struct Node* list1 = NULL;
    struct Node* list2 = NULL;

    insertNode(&list1, 5);
    insertNode(&list1, 10);
    insertNode(&list1, 15);
    printf("List 1: ");
    displayList(list1);

    insertNode(&list2, 2);
    insertNode(&list2, 7);
    insertNode(&list2, 12);
    printf("List 2: ");
    displayList(list2);

    struct Node* mergedList = mergeLists(list1, list2);
    printf("Merged List: ");
    displayList(mergedList);

    return 0;
}
