#include <stdio.h>
#include <stdlib.h>
//Standard method for doing coding of SinglyLinkedList i.e. using create
typedef struct node
{
	int val;
	struct node* after;
} node;
node* create()
{
	int value;
	node *head, *curr, *temp; 
	head = curr = temp = NULL;
	printf("\nEnter the values you want to add (Enter -1 to stop entering): ");
	scanf("%d", &value);
	if (value != -1)
	{
		head = (node *)malloc(sizeof(node));
		head->val = value;
		head->after = NULL;
		curr = head;
	}
	while (value != -1)
	{
		scanf("%d", &value);
		if (value != -1)
		{
			temp = (node *)malloc(sizeof(node));
			temp->val = value;
			temp->after = NULL;
			curr->after = temp;
			curr = temp;
		}
	}
	return head;
}
void traverse(node *head)
{
	if (head == NULL)
	{
		printf("\nThe linked list is empty!\n\n");
	}
	else
	{
		printf("\nThe linked list is : \n");
		node *temp = head;
		while (temp != NULL)
		{	
			printf("%d ", temp->val);
			temp = temp->after;
		}
		printf("\n");
	}
}
void reverse(node *(*head))
{
	if ((*head) == NULL)
	{
		printf("\nThe linked list is empty!\n\n");
	}
	else
	{
		node *prevnode, *currnode, *nextnode;
		prevnode = NULL;
		currnode = nextnode = (*head);
		while (nextnode != NULL)
		{
			nextnode = nextnode->after;
			currnode->after = prevnode;
			prevnode = currnode;
			currnode = nextnode;
		}
		(*head) = prevnode;
	}
}
int main()
{
	node *head;
	head = NULL;
	int choice, mode = 1;
	while (mode)
	{
		printf("Your choices are as follows : \n1. Create \n2. Traverse\n3. Reverse\n4. Exit\nEnter your choice : ");
		scanf("%d", &choice);
		switch (choice)
		{
			case 1:
				head = create();
				break;
			case 2:
				traverse(head);
				break;
			case 3:
				reverse(&head);
				break;
			case 4:
				mode = 0;
				break;
			default:
				printf("\nEnter a valid input!\n");
				break;
		}
	}
}
