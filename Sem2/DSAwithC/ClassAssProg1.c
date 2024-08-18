#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next, *before;
} node;
node *tail, *curr, *temp, *travel;
int findlength()
{
    int length = 1;
    travel = tail;
    while (travel != NULL)
    {
        length++;
        travel = travel->before;
    }
    return length;
}
void insert_node_end(int val)
{
    if (tail == NULL)
    {
        tail = (node *)malloc(sizeof(node));
        if (tail == NULL)
        {
            printf("\nMALLOC FAILED!\n");
            exit(1);
        }
        tail->before = NULL;
        tail->data = val;
        tail->next = NULL;
        curr = tail;
    }
    else
    {
        temp = (node *)malloc(sizeof(node));
        if (temp == NULL)
        {
            printf("\nMALLOC FAILED!\n");
            exit(1);
        }
        temp->before = tail;
        temp->data = val;
        temp->next = NULL;
        tail->next = temp;
        tail = curr = temp;
    }
}
void insert_node_beginning(int val)
{
    temp = (node *)malloc(sizeof(node));
    if (temp == NULL)
    {
        printf("\nMALLOC FAILED!\n");
        exit(1);
    }
    temp->before = NULL;
    temp->data = val;
    travel = tail;
    while (travel->before != NULL)
    {
        travel = travel->before;
    }
    temp->next = travel;
    travel->before = temp;
}
void insert_at_position(int pos, int val)
{
    int length = findlength();
    if (pos < 1 || pos > (length + 1))
    {
        printf("Invalid position entered!");
    }
    else if (pos == 1)
    {
        insert_node_beginning(val);
    }
    else
    {
        travel = tail;
        while (travel->before != NULL)
        {
            travel = travel->before;
        }
        // travel reaches the start now
        int i;
        for (i = 1; i < pos - 1; i++)
        {
            travel = travel->next;
        }
        temp = (node *)malloc(sizeof(node));
        if (temp == NULL)
        {
            printf("\nMALLOC FAILED!\n");
            exit(1);
        }
        temp->before = travel;
        temp->data = val;
        temp->next = travel->next;
        travel->next = temp;
        if (temp->next != NULL)
        {
            temp->next->before = temp;
        }
        if (pos == length + 1)
        {
            tail = temp;
        }
    }
}
void insert_after_position(int pos, int val)
{
    int length = findlength();
    if (pos < 0 || pos > (length))
    {
        printf("Invalid position entered!");
    }
    else
    {
        travel = tail;
        while (travel->before != NULL)
        {
            travel = travel->before;
        }
        // travel reaches the tail now
        int i;
        for (i = 1; i < pos; i++)
        {
            travel = travel->next;
        }
        temp = (node *)malloc(sizeof(node));
        if (temp == NULL)
        {
            printf("\nMALLOC FAILED!\n");
            exit(1);
        }
        temp->before = travel;
        temp->data = val;
        temp->next = travel->next;
        travel->next = temp;
        if (temp->next != NULL)
        {
            temp->next->before = temp;
        }
        if (pos == length)
        {
            tail = temp;
        }
    }
}
int isempty()
{
    if (tail == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void display()
{
    int var = isempty();
    if (var == 1)
    {
        printf("\nThe LinkedList is empty!\n");
    }
    else
    {
        printf("The linked list is : \n");
        travel = tail;
        while (travel->before != NULL)
        {
            travel = travel->before;
        }

        while (travel != NULL)
        {
            printf("\n%d\n", travel->data);
            travel = travel->next;
        }
        
    }
}
void reverse_linked_list()
{
    int var = isempty();
    if (var == 1)
    {
        printf("The LinkedList is empty!\n");
    }
    else
    {
        node *prevnode, *currentnode, *nextnode;
        prevnode = NULL;
        currentnode = nextnode = tail;
        while (nextnode != NULL)
        {
            nextnode = currentnode->before;
            currentnode->before = prevnode;
            currentnode->next = nextnode;
            prevnode = currentnode;
            currentnode = nextnode;
        }
        tail = prevnode;
        printf("\nThe linked list has been reversed!\n");
    }
}
int main()
{
    insert_node_end(55);
    display();
    insert_at_position(2, 56);
    display();
    insert_after_position(2, 88);
    display();
    reverse_linked_list();
    display();
    return 0;
}