#include <stdio.h>
#include <stdlib.h>
//Start ki jagah bas *top kardo
typedef struct node
{
    int data;
    struct node *before;
} node;
void push(int val, node *(*top))
//Here the top is different from the stack's top, this top is a pointer to a pointer. We are changing the value of a pointer which points to a data tyoe of node using a pointer to a pointer
//Just take *top as start everything is same. 
{
    if ((*top) == NULL)
    {
        (*top) = (node *)malloc(sizeof(node));
        if ((*top) == NULL)
        {
            printf("\nMALLOC FAILED!\n");
            exit(1);
        }
        (*top)->data = val;
        (*top)->before = NULL;
    }
    else
    {
        node *newnode;
        newnode = (node *)malloc(sizeof(node));
        if (newnode == NULL)
        {
            printf("\nMALLOC FAILED!\n");
            exit(1);
        }
        newnode->data = val;
        newnode->before = (*top);
        (*top) = newnode;
    }
}
int isempty(node *(*top))
{
    if ((*top) == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int pop(node *(*top))
{
    int var = isempty(top);
    if (var == 1)
    {
        printf("The stack is empty!\n");
        return -9999;
    }
    else
    {
        var = (*top)->data;
        (*top) = (*top)->before;
        return var;
    }
}
int peek(node *(*top))
{
    int var = isempty(top);
    if (var == 1)
    {
        printf("The stack is empty!\n");
        return -9999;
    }
    else
    {
        return (*top)->data;
    }
}
int display(node *(*top))
{
    int var = isempty(top);
    if (var == 1)
    {
        printf("The stack is empty!\n");
        return -9999;
    }
    else
    {
        printf("The stack is as follows : \n");
        node *travel;
        travel = (*top);
        while (travel != NULL)
        {
            printf("%d \n", travel->data);
            travel = travel->before;
        }
    }
}
int main()
{
    node (*top);
    top = NULL;
    printf("Welcome to the stack game!\n");
    int mode = 1;
    int input;
    int var;
    while (mode)
    {
        printf("Here are your options :\n1. Push\n2. Pop\n3. Check whether the stack is empty\n4. Display Stack contents\n5. Exit\nEnter your choice : ");
        scanf("%d", &input);
        int val;
        switch (input)
        {
            case 1:
       	    printf("Enter the value to be pushed into the stack : \n");
            scanf("%d", &val);
            push(val, &top);
            break;
            case 2:
            var = pop(&top);
            if (var != -9999)
            {
                printf("Element %d has been removed from the stack!\n", var);
            }
            break;
            case 3:
            var = isempty(&top);
            if (var == 1)
            {
                printf("The stack is empty!\n");
            }
            else
            {
                printf("The stack is not empty!\n");
            }
            break;
            case 4:
            display(&top);
            break;
            case 5:
            printf("Nice having you! Hope to see you soon!");
            mode = 0;
            break;
            default :
            printf("Invalid input! Please enter a valid input!\n");
            break;
        }
    }
    return 0;
}
