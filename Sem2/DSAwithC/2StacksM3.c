#include <stdio.h>
#define MAX 10
int array[MAX];
int top1 = -1;
int top2 = MAX;
int isfull()
{
    if (top1 == top2 - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int peek1()
{
    int var = isempty1();
    if (var == 1)
    {
        printf("STACK 1 IS EMPTY!");
        return -9999;
    }
    else
    {
        return array[top1];
    }
}
void push1(int val)
{
    int var = isfull();
    if (var == 1)
    {
        printf("STACK 1 OVERFLOW ENCOUNTERED\n");
    }
    else
    {
        array[++top1] = val;
    }
}
int pop1()
{
    int var = isempty1();
    if (var == 1)
    {
        printf("STACK 1 UNDERFLOW ENCOUNTERED\n");
        return -9999;
    }
    else
    {
        return array[top1--];
    }
}
int isempty1()
{
    if (top1 == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void display1()
{
    int var = isempty1();
    if (var == 1)
    {
        printf("The stack 1 is empty!\n");
    }
    else
    {
        printf("\nThe stack 1 is as follows : \n");
        int i;
        for (i = top1; i >= 0; i--)
        {
            printf("%d \n", array[i]);
        }
    }
}
int peek2()
{
    int var = isempty2();
    if (var == 1)
    {
        printf("STACK 2 IS EMPTY!\n");
        return -9999;
    }
    else
    {
        return array[top2];
    }
}
void push2(int val)
{
    int var = isfull();
    if (var == 1)
    {
        printf("STACK 2 OVERFLOW ENCOUNTERED\n");
    }
    else
    {
        array[--top2] = val;
    }
}
int pop2()
{
    int var = isempty2();
    if (var == 1)
    {
        printf("STACK 2 UNDERFLOW ENCOUNTERED\n");
        return -9999;
    }
    else
    {
        return array[top2++];
    }
}
int isempty2()
{
    if (top2 == MAX)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void display2()
{
    int var = isempty2();
    if (var == 1)
    {
        printf("The stack 2 is empty!\n");
    }
    else
    {
        printf("\nThe stack 2 is as follows : \n");
        int i;
        for (i = top2; i < MAX; i++)
        {
            printf("%d \n", array[i]);
        }
    }
}
int main()
{
    printf("Welcome to the stack game!\n");
    int mode = 1;
    int input, which, var, val;
    while (mode)
    {
        printf("Here are your options for either of the stacks :\n1. Push\n2. Pop\n3. Check whether the stack is full\n4. Check whether the stack is empty\n5. Display Stack contents\n6. Exit\nEnter the stack number (1 or 2) and your choice from the above options : \n");
        scanf("%d %d", &which, &input);
        var = isfull();
        switch (which)
        {
        case 1:
            switch (input)
            {
            case 1:
                if (var == 1)
                {
                    printf("STACK 1 OVERFLOW ENCOUNTERED\n");
                }
                else
                {
                    printf("Enter the value to be pushed into the stack 1 : \n");
                    scanf("%d", &val);
                    push1(val);
                }
                break;
            case 2:
                var = pop1();
                if (var != -9999)
                {
                    printf("Element %d has been removed from the stack 1!\n", var);
                }
                break;
            case 3:
                var = isfull();
                if (var == 1)
                {
                    printf("The stack 1 is full!\n");
                }
                else
                {
                    printf("The stack 1 is not full!\n");
                }
                break;
            case 4:
                var = isempty1();
                if (var == 1)
                {
                    printf("The stack 1 is empty!\n");
                }
                else
                {
                    printf("The stack 1 is not empty!\n");
                }
                break;
            case 5:
                display1();
                break;
            case 6:
                printf("Nice having you! Hope to see you soon!");
                mode = 0;
                break;
            default:
                printf("Invalid input! Please enter a valid input!\n");
                break;
            }
            break;
        case 2:
            switch (input)
            {
            case 1:
                if (var == 1)
                {
                    printf("STACK OVERFLOW ENCOUNTERED\n");
                }
                else
                {
                    printf("Enter the value to be pushed into the stack 2 : \n");
                    scanf("%d", &val);
                    push2(val);
                }
                break;
            case 2:
                var = pop2();
                if (var != -9999)
                {
                    printf("Element %d has been removed from the stack 2!\n", var);
                }
                break;
            case 3:
                var = isfull();
                if (var == 1)
                {
                    printf("The stack 2 is full!\n");
                }
                else
                {
                    printf("The stack 2 is not full!\n");
                }
                break;
            case 4:
                var = isempty2();
                if (var == 1)
                {
                    printf("The stack 2 is empty!\n");
                }
                else
                {
                    printf("The stack 2 is not empty!\n");
                }
                break;
            case 5:
                display2();
                break;
            case 6:
                printf("Nice having you! Hope to see you soon!");
                mode = 0;
                break;
            default:
                printf("Invalid input! Please enter a valid input!\n");
                break;
            }
            break;
        default:
            printf("Invalid input! Please enter a valid input!\n");
            break;
        }
    }
    return 0;
}
