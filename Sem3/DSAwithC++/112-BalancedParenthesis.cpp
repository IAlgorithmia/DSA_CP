#include <bits/stdc++.h>
using namespace std;

/*
Explanation : 
*/

bool checkParenthesis(string sample_string){
    stack<char> myStack;
    for (int i = 0; i < sample_string.size(); i++){
        char curr_char = sample_string[i];
        if (curr_char == '{' || curr_char == '[' || curr_char == '(') myStack.push(curr_char);
        else if (curr_char == '}' || curr_char == ']' || curr_char == ')'){
            if (myStack.empty()){
                return false;
            }
            char popped_item = myStack.top();
            myStack.pop();
            switch(curr_char){
                case '}':
                if (popped_item != '{') return false;
                break;
                case ')':
                if (popped_item != '(') return false;
                break;
                case ']':
                if (popped_item != '[') return false;
                break;
            }
        };
    }
    return (sample_string.empty() == true); //since last mein kuch bachna nahi chahiye
}

int main(){
    cout << "Enter the string" << endl;
    string sample_string;
    cin >> sample_string;
    cout << checkParenthesis(sample_string) << endl;
}