#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Stack {
    Node* top;
} Stack;

void initialize(Stack* stack) {
    stack->top = NULL;
}

int isEmpty(Stack* stack) {
    return (stack->top == NULL);
}

void push(Stack* stack, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Stack Overflow: Cannot push element.\n");
        return;
    }

    newNode->data = data;
    newNode->next = stack->top;
    stack->top = newNode;
}

int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow: Cannot pop element.\n");
        return -1; // Return a default value or handle the error as needed
    }

    Node* temp = stack->top;
    int data = temp->data;
    stack->top = temp->next;
    free(temp);

    return data;
}

int peek(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty.\n");
        return -1; // Return a default value or handle the error as needed
    }

    return stack->top->data;
}

int main() {
    Stack stack;
    initialize(&stack);

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    printf("Top element: %d\n", peek(&stack));

    printf("Popped element: %d\n", pop(&stack));
    printf("Top element after popping: %d\n", peek(&stack));

    return 0;
}
