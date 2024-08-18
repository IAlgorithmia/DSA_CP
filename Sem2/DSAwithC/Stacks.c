#include <stdio.h>
#define MAX 100
int stack[MAX];
int top = -1;
int peek()
{
    int var = isempty();
    if (var == 1)
    {
        printf("STACK IS EMPTY!");
        return -9999;
    }
    else
    {
        return stack[top];
    }
}
void push(int val)
{
    int var = isfull();
    if (var == 1)
    {
    	printf("STACK OVERFLOW ENCOUNTERED\n");
	}
    else
    {
        stack[++top] = val;
    }
}
int pop()
{
    int var = isempty();
    if (var == 1)
    {
    	printf("STACK UNDERFLOW ENCOUNTERED\n");
    	return -9999;
	}
    else
    {
        return stack[top--];
    }
}
int isfull()
{
    if (top == MAX - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isempty()
{
    if (top == -1)
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
    	printf("The stack is empty!");
	}
    else
    {
        printf("\nThe stack is as follows : \n");
        int i;
        for (i = top; i >= 0; i--)
        {
            printf("%d \n", stack[i]);
        }
    }
}
int main()
{
    printf("Welcome to the stack game!\n");
    int mode = 1;
    int input;
    int var;
    while (mode)
    {
        printf("Here are your options :\n1. Push\n2. Pop\n3. Check whether the stack is full\n4. Check whether the stack is empty\n5. Display Stack contents\n6. Exit\nEnter your choice : \n");
        scanf("%d", &input);
        int val;
        int var = isfull();
        switch (input)
        {
            case 1:
            if (var == 1)
            {
         	    printf("STACK OVERFLOW ENCOUNTERED\n");
        	}
        	else
        	{
       	    printf("Enter the value to be pushed into the stack : \n");
            scanf("%d", &val);
            push(val);
        	}    
            break;
            case 2:
            var = pop();
            if (var != -9999)
            {
                printf("Element %d has been removed from the stack!\n", var);
            }
            break;
            case 3:
            var = isfull();
            if (var == 1)
            {
                printf("The stack is full!\n");
            }
            else
            {
                printf("The stack is not full!\n");
            }
            break;
            case 4:
            var = isempty();
            if (var == 1)
            {
                printf("The stack is empty!\n");
            }
            else
            {
                printf("The stack is not empty!\n");
            }
            break;
            case 5:
            display();
            break;
            case 6:
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
