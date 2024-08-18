#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
} node;
node *start, *curr, *temp, *travel;
int findlength()
{
    int length = 0;
    travel = start;
    while (travel != NULL)
    {
        length++;
        travel = travel->next;
    }
    return length;
}
int isempty()
{
    if (start == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void insert_node_end(int val)
{
    if (start == NULL)
    {
        start = (node *)malloc(sizeof(node));
        if (start == NULL)
        {
            printf("\nMALLOC FAILED!\n");
            exit(1);
        }
        else
        {
        start->data = val;
        start->next = start;
        curr = start;
        }
    }
    else
    {
        temp = (node *)malloc(sizeof(node));
        if (temp == NULL)
        {
            printf("\nMALLOC FAILED!\n");
            exit(1);
        }
        else
        {
        temp->data = val;
        temp->next = start;
        curr->next = temp;
        curr = temp;
        }
    }
}
void display()
{
    int var = isempty();
    if (var == 1)
    {
        printf("The LinkedList is empty!\n");
    }
    else
    {
        printf("\nThe linked list is : \n");
        travel = start;
        while (travel->next != start)
        {
            printf("%d ", travel->data);
            travel = travel->next;
        }
        printf("%d ", travel->data);
    }
}
void reversell()
{
    int var = isempty();
    if (var == 1)
    {
        printf("The LinkedList is empty!\n");
    }
    else
    {
        node *prevnode, *currentnode, *nextnode;
        travel = start;
        while (travel->next != start)
        {
            travel = travel->next;
        }
        prevnode = travel;
        currentnode = nextnode = start;
        while (prevnode->next != start)
        {
            nextnode = nextnode->next;
            currentnode->next = prevnode;
            prevnode = currentnode;
            currentnode = nextnode;
        }
        start = prevnode;
        printf("\nThe linked list has been reversed!");
    }
}
int main()
{
    insert_node_end(5);
    display();
    insert_node_end(66);
    display();
    insert_node_end(123);
    display();
    reversell();
    display();
    return 0;
}
