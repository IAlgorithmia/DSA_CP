#include <stdio.h>
#define MAX 100
char reversed[MAX];
char actual_prefix_answer[MAX];
char infix[MAX];
char prefix[MAX];
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
void reverser(char array1[], char array2[])
{
    int len = 0;
    while (array1[len] != '\0')
    {
        len++;
    }
    for (int i = 0; i < (len); i++)
    {
        array2[i] = array1[len - 1 - i];
    }
    array2[len] = '\0';
}
int priority(char symbol)
{
    if (symbol == '(' || symbol == ')')
    {
        return 0;
    }
    else if (symbol == '-' || symbol == '+')
    {
        return 1;
    }
    else if (symbol == '/' || symbol == '*')
    {
        return 2;
    }
    else if (symbol == '^')
    {
        return 3;
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
void push(char value)
{
    int var = isfull();
    if (var == 1)
    {
        printf("STACK OVERFLOW ENCOUNTERED!\n");
    }
    else
    {
        top++;
        stack[top] = value;
    }
}
char pop()
{
    int var = isempty();
    if (var == 1)
    {
        printf("STACK UNDERFLOW ENCOUNTERED!");
    }
    else
    {
        return stack[top--];
    }
}
void converter()
{
    int i = 0, j = 0;
    int ascii;
    while (reversed[i] != '\0')
    {
        ascii = reversed[i];
        if (ascii <= 90 && ascii >= 65)
        {
            prefix[j] = reversed[i];
            j++;
        }
        else
        {
            if (reversed[i] == ')')
            {
                push(reversed[i]);
            }
            else if (reversed[i] == '(')
            {
                while (peek() != ')')
                {
                    prefix[j] = pop();
                    j++;
                }
                pop();
            }
            else
            {
            again:
                if (top == -1)
                {
                    push(reversed[i]);
                }
                else if (priority(reversed[i]) > priority(peek()))
                {
                    push(reversed[i]);
                }
                else if (priority(reversed[i]) < priority(peek()))
                {
                    prefix[j] = pop();
                    j++;
                    goto again;
                }
                else
                {
                    push(reversed[i]);
                }
            }
        }
        i++;
    }
    while (!isempty())
    {
        prefix[j] = pop();
        j++;
    }
    prefix[j] = '\0';
}
int main()
{
    printf("Welcome to the infix to prefix converter!\nBasic Assumptions : \n1. Infix operation is always valid\n2. Operators are binary\n3. Operands are single digit\nEnter the infix expression to be converted to prefix : \n");
    scanf("%s", &infix);
    reverser(infix, reversed);
    converter();
    reverser(prefix, actual_prefix_answer);
    printf("\nThe converted expression is : \n");
    printf("%s", actual_prefix_answer);
    return 0;
}
