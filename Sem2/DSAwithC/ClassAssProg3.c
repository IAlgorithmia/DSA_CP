#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next, *before;
} node;
node *start, *curr, *temp, *travel;
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
int findlength()
{
    if (start == NULL)
    {
        return 0;
    }
    else
    {
        int length = 0;
        travel = start;
        while (travel->next != start)
        {
            length++;
            travel = travel->next;
        }
        length++;
        return length;
    }
}
void insert_node_beginning(int val)
{
    if (start == NULL)
    {
        start = (node *)malloc(sizeof(node));
        start->data = val;
        start->before = start;
        start->next = start;
    }
    else
    {
        temp = (node *)malloc(sizeof(node));
        if (temp == NULL)
        {
            printf("\nMALLOC FAILED!\n");
            exit(1);
        }
        temp->before = start->before;
        temp->data = val;
        temp->next = start;
        start->before = temp;
        travel = start;
        while (travel->next != start)
        {
            travel = travel->next;
        }
        travel->next = temp;
        start = temp;
    }
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
        travel = start;
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
        printf("\n");
    }
}
int delete_from_beginning()
{
    int var = isempty();
    if (var == 1)
    {
        printf("The LinkedList is empty!\n");
        return -9999;
    }
    else
    {
        travel = start;
        while (travel->next != start)
        {
            travel = travel->next;
        }
        temp = start;
        start = start->next;
        start->before = travel;
        travel->next = start;
        var = temp->data;
        free(temp);
        return var;
    }
}
int delete_at_position(int pos)
{
    int length = findlength();
    int var = isempty();
    if (var == 1)
    {
        printf("The LinkedList is empty!\n");
        return -9999;
    }
    if (pos < 1 || pos > (length))
    {
        printf("Invalid position entered!");
        return -9999;
    }
    else
    {
        if (pos == 1)
        {
            var = delete_from_beginning();
            return var;
        }
        else
        {
            travel = start;
            int i;
            for (i = 1; i < pos - 1; i++)
            {
                travel = travel->next;
            }
            temp = travel->next;
            var = temp->data;
            travel->next = temp->next;
            if (temp->next != NULL)
            {
                temp->next->before = travel;
                //(Associativity is left to right, o no brackets is also okay)
            }
            free(temp);
            return var;
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
        travel = start;
        while (travel->next != start)
        {
            travel = travel->next;
        }
        node *prevnode, *currentnode, *nextnode;
        prevnode = travel;
        currentnode = nextnode = start;
        while (currentnode->next != start)
        {
            nextnode = currentnode->next;
            currentnode->before = nextnode;
            currentnode->next = prevnode;
            prevnode = currentnode;
            currentnode = nextnode;
        }
        nextnode = currentnode->next;
        currentnode->before = nextnode;
        currentnode->next = prevnode;
        prevnode = currentnode;
        currentnode = nextnode;
        start = prevnode;
        printf("\nThe linked list has been reversed!\n");
    }
}
int main()
{
    insert_at_position(1, 12);
    display();
    insert_at_position(2, 55);
    display();
    insert_at_position(3, -12);
    display();
    delete_at_position(2);
    display();
    reverse_linked_list();
    display();
    return 0;
}