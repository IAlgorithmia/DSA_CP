#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct StackElement {
    int data;
    // Add any other fields you need for your stack element
};

struct Stack {
    struct StackElement stackArray[MAX_SIZE];
    int top;
};

void initialize(struct Stack* stack) {
    stack->top = -1;
}

int isEmpty(struct Stack* stack) {
    return (stack->top == -1);
}

int isFull(struct Stack* stack) {
    return (stack->top == MAX_SIZE - 1);
}

void push(struct Stack* stack, int data) {
    if (isFull(stack)) {
        printf("Stack Overflow: Cannot push element onto the stack.\n");
        return;
    }

    stack->top++;
    stack->stackArray[stack->top].data = data;
    // Set other fields of the stack element as needed
}

void pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow: Cannot pop element from an empty stack.\n");
        return;
    }

    stack->top--;
}

int top(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty.\n");
        return -1; // Return a default value or handle the error as needed
    }

    return stack->stackArray[stack->top].data;
    // Access other fields of the top element as needed
}

int main() {
    struct Stack stack;
    initialize(&stack);

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    printf("Top element: %d\n", top(&stack));

    pop(&stack);
    printf("Top element after pop: %d\n", top(&stack));

    return 0;
}