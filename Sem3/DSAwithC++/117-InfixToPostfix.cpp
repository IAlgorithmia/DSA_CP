#include <bits/stdc++.h>
using namespace std;

/*
Explanation : THE BELOW CODE ONLY DEALS WITH SINGLE DIGIT EXPRESSIONS, WE CAN HANDLE MULTIPLE DIGIT EXPRESSIONS BY PROVIDING SPACE BETWEEN THEM AND THEN DOING THE SAME STUFF
*/

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
    return 0;
}

string infixToPostfix(string infix){
    stack<char> opStack;
    string postfix;

    for (int i = 0; i < infix.size(); i++){
        char item = infix[i];

        if (item == ' '){
            continue;
        }
        //space check above
        if ((int)item >= 97 && (int)item <= 122){
            postfix.push_back(item);
        }
        else{
            if (item == '('){
                opStack.push(item);
            }
            else if (item == ')'){
                while (opStack.top() != '('){
                    postfix.push_back(opStack.top());
                    opStack.pop();
                }
                opStack.pop();
            }
            else{
                again : 
                if (opStack.empty() || priority(item) > priority(opStack.top())){
                    opStack.push(item);
                }
                else if (priority(item) < priority(opStack.top())){
                    postfix.push_back(opStack.top());
                    opStack.pop();
                    goto again;
                }
                else{
                    postfix.push_back(opStack.top());
                    opStack.pop();
                    opStack.push(item);
                }
            }
        }
    }
    
    while (!opStack.empty()){
        postfix.push_back(opStack.top());
        opStack.pop();
    }

    return postfix;
}

int main(){
    cout << "Enter a VALID expression in INFIX in all lowercase : " << endl;
    string infix;
    getline(cin, infix);
    cout << infixToPostfix(infix) << endl;
}