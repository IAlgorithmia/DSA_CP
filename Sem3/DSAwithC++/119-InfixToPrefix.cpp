#include <bits/stdc++.h>
using namespace std;

/*
Explanation : 
*/

// DONT FORGET TO FKIN EMPTY THE STACK INTO THE STRING
// AFTER ALL IS SAID AND DONE

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

string infixToPrefix(string infix){
    stack<char> opStack;
    string prefix;

    for (int i = 0; i < infix.size(); i++){
        char item = infix[i];
        cout << "Utem is " << item << endl;

        if (item == ' '){
            continue;
        }
        //space check above
        if ((int)item >= 97 && (int)item <= 122){
            prefix.push_back(item);
        }
        else{
            if (item == ')'){
                opStack.push(item);
            }
            else if (item == '('){
                while (opStack.top() != ')'){
                    prefix.push_back(opStack.top());
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
                    prefix.push_back(opStack.top());
                    opStack.pop();
                    goto again;
                }
                else{
                    opStack.push(item);
                }
            }
        }
    }
    
    while (!opStack.empty()){
        prefix.push_back(opStack.top());
        opStack.pop();
    }

    return prefix;

}

int main(){

    cout << "Enter a VALID expression in infix in all lowercase : " << endl;

    string infix;
    getline(cin, infix);

    reverse(infix.begin(), infix.end());
    
    string received = infixToPrefix(infix);
    reverse(received.begin(), received.end());

    cout << received << endl;
}