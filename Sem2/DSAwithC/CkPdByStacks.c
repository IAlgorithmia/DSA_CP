#include <stdio.h>
#define MAX 100
char stack[MAX];
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
void push(char val)
{
    int var = isfull();
    if (var == 1)
    {
        printf("STACK OVERFLOW ENCOUNTERED");
    }
    else
    {
        stack[++top] = val;
    }
}
char pop()
{
    int var = isempty();
    if (var == 1)
    {
        printf("STACK UNDERFLOW ENCOUNTERED!\n");
        return -100;
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
        printf("The stack is empty!\n");
    }
    else
    {
        printf("\nThe stack is as follows : \n");
        int i;
        for (i = 0; i <= top; i++)
        {
            printf("%c \n", stack[top - i]);
        }
    }
}
int palindrome()
{
    int traverse = 0;
    int temp;
    temp = top;
    while (traverse < top)
    {
        if (stack[traverse] != pop(stack))
        {
            top = temp;
            return 0;
        }
        traverse++;
    }
    top = temp;
    return 1;
}
int main()
{
    printf("Welcome to the stack game!\n");
    int mode = 1;
    int input;
    int var;
    char var1;
    while (mode)
    {
        printf("Here are your options :\n1. Push\n2. Pop\n3. Check whether the stack is full\n4. Check whether the stack is empty\n5. Display Stack contents\n6. Exit\n7. Check whether the stack is a palindrome or not\nEnter your choice : \n");
        scanf("%d", &input);
        var = isfull();
        switch (input)
        {
            case 1:
            if (var == 1)
            {
            	printf("STACK OVERFLOW ENCOUNTERED");
			}
			else
			{
           	printf("Enter the value to be pushed into the stack : ");
        	scanf(" %c", &var1); //Space before %c to clear the buffer and ignore white spaces enterd in the input!
            push(var1);
        	}
            break;
            case 2:
            var1 = pop();
            if (var1 != -100)
            {
                printf("Element %c has been removed from the stack!\n", var1);
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
            case 7:
            var = palindrome();
            if (var == 1)
            {
                printf("The stack is a palindrome!\n");
            }
            else
            {
                printf("The stack is not a palindrome!\n");
            }
            break;
            default :
            printf("Invalid input! Please enter a valid input!\n");
            break;
        }
    }
    return 0;
}
