#include <stdio.h>
#define MAX 100
char infix[MAX];
char postfix[MAX];
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
        printf("STACK OVERFLOW ENCOUNTERED\n");
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
        return ';';
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
    while (infix[i] != '\0')
    {
        ascii = infix[i];
        if (ascii <= 90 && ascii >= 65)
        {
            postfix[j] = infix[i];
            j++;
        }
        else
        {
            if (infix[i] == '(')
            {
                push(infix[i]);
            }
            else if (infix[i] == ')')
            {
                while (peek() != '(')
                {
                    postfix[j] = pop();
                    j++;
                }
                pop();
            }
            else
            {
            again:
                if (top == -1)
                {
                    push(infix[i]);
                }
                else if (priority(infix[i]) > priority(peek()))
                {
                    push(infix[i]);
                }
                else if (priority(infix[i]) < priority(peek()))
                {
                    postfix[j] = pop();
                    j++;
                    goto again;
                    //while mein bhi kar sakte the
                }
                else
                {
                    postfix[j] = pop();
                    j++;
                    push(infix[i]);
                }
            }
        }
        i++;
    }
    while (!isempty())
    {
        postfix[j] = pop();
        j++;
    }
    postfix[j] = '\0';
}
int main()
{
    printf("Welcome to the infix to postfix converter!\nBasic Assumptions : \n1. Infix operation is always valid\n2. Operators are binary\n3. Operands are single digit\nEnter the infix expression to be converted to postfix : \n");
    scanf("%s", &infix);
    converter();
    printf("\nThe converted expression is : \n");
    printf("%s", postfix);
    return 0;
}
