#include <bits/stdc++.h>
using namespace std;

/*
Explanation : THE BELOW CODE ONLY DEALS WITH SINGLE DIGIT EXPRESSIONS, WE CAN HANDLE MULTIPLE DIGIT EXPRESSIONS BY PROVIDING SPACE BETWEEN THEM AND THEN DOING THE SAME STUFF
*/

int postfixEval(string postFix){
    stack<int> Result;
    for (int i = 0; i < postFix.size(); i++){
        if (postFix[i] == ' '){
            continue;
        }
        if ((int)postFix[i] >= 48 && (int)postFix[i] <= 57){
            Result.push((int)postFix[i] - 48);
        }
        else {
            int opd1 = Result.top();
            Result.pop();
            int opd2 = Result.top();
            Result.pop();
            if (postFix[i] == '+'){
                Result.push(opd1 + opd2);
            }
            else if (postFix[i] == '-'){
                Result.push(opd2 - opd1);
            }
            else if (postFix[i] == '*'){
                Result.push(opd1 * opd2);
            }
            else if (postFix[i] == '/'){
                Result.push(opd2 / opd1);
            }
            else if (postFix[i] == '^'){
                Result.push(pow(opd2, opd1));
            }
        }
    }
    int result = Result.top();
    //result is the only remaining element in the stack
    return result;
}

int main(){
    cout << "Enter a VALID expression in POSTFIX in all lowercase : " << endl;
    string postfix;
    getline(cin, postfix);
    cout << postfixEval(postfix) << endl;
}