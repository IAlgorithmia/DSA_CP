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
        start->next = NULL;
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
        temp->next = NULL;
        curr->next = temp;
        curr = temp;
        }
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
    temp->data = val;
    temp->next = start;
    start = temp;
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
        temp->data = val;
        temp->next = travel->next;
        travel->next = temp;
    }
}
void insert_after_val(int thevalue, int val)
{
    int var = isempty();
    if (var == 1)
    {
        printf("The LinkedList is empty!\n");
    }
    else
    {
        travel = start;
        while (travel != NULL && travel->data != thevalue) // NULL condition is checked before because NULL se access ka try nahi karna kabhi bhi
        {
            travel = travel->next;
        }
        if (travel == NULL)
        {
            printf("Value doesn't exist in the linked list!\n");
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
    }
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
void display()
{
    int var = isempty();
    if (var == 1)
    {
        printf("The LinkedList is empty!\n");
    }
    else
    {
        travel = start;
        while (travel != NULL)
        {
            printf("%d ", travel->data);
            travel = travel->next;
        }
    }
}
int delete_after_val(int thevalue)
{
    int num;
    travel = start;
    while (travel != NULL && travel->data != thevalue)
    {
        travel = travel->next;
    }
    if (travel == NULL)
    {
        printf("Value doesn't exist in the linked list!\n");
    }
    temp = travel->next;
    if (temp == NULL)
    {
        printf("Deletion after the last element is senseless!\n");
    }
    num = temp->data;
    travel->next = temp->next;
    free(temp);
    return num;
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
        int var;
        temp = start;
        start = start->next;
        var = temp->data;
        free(temp);
        return var;
    }
}
int delete_at_position(int pos)
{
    int var = isempty();
    int length = findlength();
    if (var == 1)
    {
        printf("The LinkedList is empty!\n");
        return -9999;
    }
    if (pos < 1 || pos > (length + 1))
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
            free(temp);
            return var;
        }
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
        prevnode = NULL;
        currentnode = nextnode = start;
        while (nextnode != NULL)
        {
            nextnode = nextnode->next;
            currentnode->next = prevnode;
            prevnode = currentnode;
            currentnode = nextnode;
        }
        start = prevnode;
        printf("The linked list has been reversed!");
    }
}
int main()
{
    printf("Welcome to the LinkedList Game!\n");
    int val, choice, pos, thevalue, mode = 1;
    while (mode)
    {
        printf("\nHere are your choices : \n1. Add a new node at the end of the linked list\n2. Insert after a specific value\n3. Insert at a specific position\n4. Delete after a specific value\n5. Delete from a specific position\n6. Display the LinkedList\n7. Check whether the linked list is empty\n8. Reverse the linked list\n9. Exit\nEnter your choice : ");
        scanf("%d", &choice);
        // Insert at position 3 means inserted node should become the 3rd node, at position 1 means at beginning
        // Similarly with deletion
        switch (choice)
        {
        case 1:
            printf("Enter the number you want to insert : ");
            scanf("%d", &val);
            insert_node_end(val);
            break;
        case 2:
            printf("Enter the value you want to insert and the value after which you want it inserted\n");
            scanf("%d %d", &val, &thevalue);
            insert_after_val(thevalue, val);
            break;
        case 3:
            printf("Enter the value you want to insert and the position where you want it inserted : ");
            scanf("%d %d", &val, &pos);
            insert_at_position(pos, val);
            break;
        case 4:
            if (!isempty())
            {
                printf("Enter the value whose immediately next element you want to delete\n");
                scanf("%d", &thevalue);
                val = delete_after_val(thevalue);
                if (val != -9999)
                {
                    printf("The element %s has been deleted!", val);
                }
            }
            else
            {
                printf("The linkedlist has no items\n");
            }
            break;
        case 5:
            if (!isempty())
            {
                printf("Enter the position after which you want the element deleted : ");
                scanf("%d", &pos);
                val = delete_at_position(pos);
                if (val != -9999)
                {
                    printf("The element %s has been deleted!", val);
                }
            }
            else
            {
                printf("The linkedlist has no items!\n");
            }
            break;
        case 6:
            display();
            break;
        case 7:
            val = isempty();
            if (val == 1)
            {
                printf("The linked list is empty!\n");
            }
            else
            {
                printf("The linked list is not empty!\n");
            }
            break;
        case 8:
            reversell();
            break;
        case 9:
            mode = 0;
            printf("Nice having you, hope to see you soon!\n");
            break;
        default:
            printf("Enter a valid choice!\n");
            break;
        }
    }
    return 0;
}
