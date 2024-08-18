#include <stdio.h>
#include <stdlib.h>
// Standard method for doing coding of DoublyLinkedList i.e. using create
typedef struct node
{
	int val;
	struct node *before;
	struct node *after;
} node;
node *create()
{
	int value;
	node *head, *curr, *temp;
	head = curr = temp = NULL;
	printf("\nEnter the values you want to add (Enter -1 to stop): \n");
	scanf("%d", &value);
	if (value != -1)
	{
		head = (node *)malloc(sizeof(node));
		head->val = value;
		head->before = NULL;
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
			temp->before = curr;
			curr->after = temp;
			curr = temp;
		}
	}
	return head;
}
void traverse_fwd(node *head)
{
	if (head == NULL)
	{
		printf("\nThe linked list is empty!\n");
	}
	else
	{
		printf("\nThe linked list is : \n");
		node *travel;
		travel = head;
		while (travel != NULL)
		{
			printf("%d ", travel->val);
			travel = travel->after;
		}
		printf("\n");
	}
}
void traverse_bwd(node *head)
{
	if (head == NULL)
	{
		printf("\nThe linked list is empty!\n");
	}
	else
	{
		node *travel;
		travel = head;
		while (travel->after != NULL)
		{
			travel = travel->after;
		}
		printf("\nThe linked list is : \n");
		while (travel != NULL)
		{
			printf("%d ", travel->val);
			travel = travel->before;
		}
		printf("\n");
	}
}
void reversalM1(node *(*head))
{
	// Values swap kardo
	if ((*head) == NULL)
	{
		printf("\nThe linked list is empty!\n");
	}
	else
	{
		int temp, length = 0;
		node *leftside, *rightside, *storerightside;
		leftside = rightside = (*head);
		while (rightside->after != NULL)
		{
			length++;
			rightside = rightside->after;
		}
		storerightside = rightside;
		length++;
		for (int i = 0; i < length / 2; i++)
		{
			temp = leftside->val;
			leftside->val = rightside->val;
			rightside->val = temp;
			leftside = leftside->after;
			rightside = rightside->before;
		}
	}
}
void reversalM2(node *(*head))
{
	// After and before variables swap kardo
	if ((*head) == NULL)
	{
		printf("\nThe linked list is empty!\n");
	}
	else
	{
		node *currentnode = (*head);
		node *temp, *travel;
		travel = (*head);
		while (travel->after != NULL)
		{
			travel = travel->after;
		}
		while (currentnode != NULL)
		{
			temp = currentnode->after;
			currentnode->after = currentnode->before;
			currentnode->before = temp;
			currentnode = temp;
		}
		(*head) = travel;
	}
}
void reversalM3(node *(*head))
{
	// Vahi Singly vala
	if ((*head) == NULL)
	{
		printf("\nThe linked list is empty\n");
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
			currnode->before = nextnode;
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
	int mode = 1;
	int choice;
	while (mode)
	{
		printf("Your choices are as follows : \n1. Create\n2. Traverse Forward\n3. Traverse Backward\n4. Reversal - Method 1\n5. Reversal - Method 2\n6. Reversal - Method 3\n7. Exit\nEnter your choice : ");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			head = create();
			break;
		case 2:
			traverse_fwd(head);
			break;
		case 3:
			traverse_bwd(head);
			break;
		case 4:
			reversalM1(&head);
			break;
		case 5:
			reversalM2(&head);
			break;
		case 6:
			reversalM3(&head);
			break;
		case 7:
			mode = 0;
			break;
		default:
			printf("\nEnter a valid input\n");
			break;
		}
	}
}
