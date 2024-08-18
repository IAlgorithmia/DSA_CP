#include <stdio.h>
#include <math.h>
#include <string.h>
#define MAX 100
float stack[MAX];
char postfix[MAX];
int top = -1;
void push(float value)
{
    int var = isfull();
    if (var == 1)
    {
        printf("STACK OVERFLOW ENCOUNTERED!\n");
    }
    else
    {
        top++;
        stack[top] =  value;
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
float pop()
{
    int var = isempty();
    if (var)
    {
        printf("STACK UNDERFLOW ENCOUNTERED!\n");
    }
    else
    {
        return stack[top--];
    }
}
float evaluate()
{
    // Digits have an ascii value form 48 to 57, + = 43, * = 42, - = 45, / = 47, ^ = 94
    int i = 0;
    int ascii;
    float res, opd1, opd2;
    while (postfix[i] != '\0')
    {
        ascii = postfix[i];
        if (ascii <= 57 && ascii >= 48)
        {
            push(ascii - 48);
        }
        else
        {
            opd1 = pop(stack);
            opd2 = pop(stack);
            if (postfix[i] == '+')
            {
                res = opd2 + opd1;
                push(res);
            }
            else if (postfix[i] == '*')
            {
                res = opd2 * opd1;
                push(res);
            }
            else if (postfix[i] == '/')
            {
                res = opd2 / opd1;
                push(res);
            }
            else if (postfix[i] == '-')
            {
                res = opd2 - opd1;
                push(res);
            }
            else if (postfix[i] == '^')
            {
                res = pow(opd2, opd1);
                push(res);
            }
        
        }
        i++;
    }
    return pop(stack);
}
int main()
{
    printf("Welcome to the PostFix Evaluation game!\nBasic Requirements : \n1. Postfix expression should be valid\n2. Every operand should be of 1 digit\n3. Operators should be binary\n\nEnter the postfix expression below : \n");
    scanf("%s", &postfix);
    float ans;
    ans = evaluate(postfix);
    printf("The evaluated postfix expression is : %.2f", ans);
    return 0;
}