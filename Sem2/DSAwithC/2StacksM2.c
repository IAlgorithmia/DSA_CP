#include <stdio.h>
#define MAX 100
#define N 2
int arr[MAX];
// 0 to 49 is stack 1, 50 to 99 is stack 2
int top1 = -1;
int top2 = MAX / N - 1;
int peek(int which)
{
	switch (which)
	{
		int var;
	case 1:
		var = isfull(which);
		if (var == 1)
		{
			printf("The stack 1 is empty\n");
			return -9999;
		}
		else
		{
			return arr[top1];
		}
		break;
	case 2:
		var = isfull(which);
		if (var == 1)
		{
			printf("The stack 2 is empty\n");
			return -9999;
		}
		else
		{
			return arr[top2];
		}
		break;
	}
}
int isfull(int which)
{
	switch (which)
	{
	case 1:
		if (top1 == MAX / N - 1)
		{
			return 1;
		}
		else
		{
			return 0;
		}
		break;
	case 2:
		if (top2 == MAX - 1)
		{
			return 1;
		}
		else
		{
			return 0;
		}
		break;
	}
}
int isempty(int which)
{
	switch (which)
	{
	case 1:
		if (top1 == -1)
		{
			return 1;
		}
		else
		{
			return 0;
		}
		break;
	case 2:
		if (top2 == MAX / N - 1)
		{
			return 1;
		}
		else
		{
			return 0;
		}
		break;
	}
}
void push(int which, int val)
{
	switch (which)
	{
		int var;
	case 1:
		var = isfull(which);
		if (var == 1)
		{
			printf("Stack 1 Overflow encountered\n");
		}
		else
		{
			arr[++top1] = val;
		}
		break;
	case 2:
		var = isfull(which);
		if (var == 1)
		{
			printf("Stack 2 Overflow encountered\n");
		}
		else
		{
			arr[++top2] = val;
		}
		break;
	}
}
int pop(int which)
{
	switch (which)
	{
		int var;
	case 1:
		var = isempty(which);
		if (var == 1)
		{
			printf("Stack 1 Underflow encountered\n");
			return -9999;
		}
		else
		{
			return arr[top1--];
		}
		break;
	case 2:
		var = isempty(which);
		if (var == 1)
		{
			printf("Stack 2 Underflow encountered\n");
			return -9999;
		}
		else
		{
			return arr[top2--];
		}
		break;
	}
}
void display(int which)
{
	switch (which)
	{
		int var;
	case 1:
		var = isempty(which);
		if (var == 1)
		{
			printf("Stack 1 is empty\n");
		}
		else
		{
			int i;
			for (i = top1; i >= 0; i--)
			{
				printf("%d \n", arr[i]);
			}
		}
		break;
	case 2:
		var = isempty(which);
		if (var == 1)
		{
			printf("Stack 2 is empty\n");
		}
		else
		{
			int i;
			for (i = top2; i >= 50; i--)
			{
				printf("%d \n", arr[i]);
			}
		}
		break;
	}
}
int main()
{
	printf("Welcome to the stack game!\n");
	int mode = 1;
	int which, input, var;
	while (mode)
	{

		printf("Here are your options for either of the stacks :\n1. Push\n2. Pop\n3. Check whether the stack is full\n4. Check whether the stack is empty\n5. Display Stack contents\n6. Exit\nEnter the stack number (1 or 2) and your choice from the above options : \n");
		scanf("%d %d", &which, &input);
		var = isfull(which);
		if (which != 1 && which != 2)
		{
			printf("Enter a valid input!\n");
			continue;
		}
		switch (input)
		{
		case 1:
			if (var == 1)
			{
				printf("Stack %d overflow encountered!\n", which);
			}
			else
			{
				printf("Enter the value you want to push : ");
				scanf("%d", &var);
				push(which, var);
			}
			break;
		case 2:
			var = pop(which);
			if (var != -9999)
			{
				printf("%d has been removed from the stack!\n", var);
			}
			break;
		case 3:
			var = isfull(which);
			if (var == 1)
			{
				printf("The stack %d is full\n", which);
			}
			else
			{
				printf("The stack %d is not full\n", which);
			}
			break;
		case 4:
			var = isempty(which);
			if (var == 1)
			{
				printf("The stack %d is empty\n", which);
			}
			else
			{
				printf("The stack %d is not empty\n", which);
			}
			break;
		case 5:

			display(which);
			break;
		case 6:
			printf("Nice having you, hope to see you soon\n");
			mode = 0;
			break;
		default:
			printf("Please enter a valid input");
			break;
		}
	}
}
