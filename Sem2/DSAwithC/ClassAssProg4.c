#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
} node;
node *tail, *curr, *temp, *travel;
int findlength()
{
    if (tail == NULL)
    {
        return 0;
    }
    else
    {
        int length = 0;
        travel = tail->next;
        while (travel != tail && travel != NULL)
        {
            length++;
            travel = travel->next;
        }
        length++;
        return length;
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
void insert_node_beginning(int val)
{
    if (tail == NULL)
    {
        tail = (node *)malloc(sizeof(node));
        tail->data = val;
        tail->next = tail;
    }
    else
    {
        temp = (node *)malloc(sizeof(node));
        if (temp == NULL)
        {
            printf("\nMALLOC FAILED!\n");
            exit(1);
        }
        temp->data = val;
        temp->next = tail->next;
        tail->next = temp;
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
        travel = tail->next;
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
        temp->data = val;
        temp->next = travel->next;
        travel->next = temp;
        if (pos == length + 1)
        {
            tail = temp;
        }
    }
}
int delete_beginning()
{
    int var = isempty();
    if (var == 1)
    {
        printf("\nThe linked list is empty!\n");
        return -9999;
    }
    else
    {
        temp = tail->next;
        var = temp->data;
        tail->next = temp->next;
        free(temp);
        return var;
    }
}
int delete_at_position(int pos)
{
    int var;
    int length = findlength();
    if (pos < 1 || pos > (length))
    {
        printf("Invalid position entered!");
    }
    else if (pos == 1)
    {
        var = delete_beginning();
    }
    else
    {
        travel = tail->next;
        int i;
        for (i = 1; i < pos - 1; i++)
        {
            travel = travel->next;
        }
        temp = travel->next;
        var = temp->data;
        travel->next = temp->next;
        free(temp);
        if (pos == length)
        {
            tail = travel;
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
        travel = tail->next;
        while (travel != tail)
        {
            printf("%d ", travel->data);
            travel = travel->next;
        }
        printf("%d ", travel->data);
    }
}
int main()
{
    insert_at_position(1, 12);
    display();
    insert_at_position(2, 23);
    display();
    insert_at_position(3, 77);
    display();
    delete_at_position(3);
    display();
    return 0;
}
