#include <bits/stdc++.h>
using namespace std;

/*
Explanation : Same as postfix eval just r to l
*/

int prefixEval(string preFix){
    stack<int> Result;
    for (int i = 0; i < preFix.size(); i++){
        if (preFix[i] == ' '){
            continue;
        }
        if ((int)preFix[i] >= 48 && (int)preFix[i] <= 57){
            Result.push((int)preFix[i] - 48);
        }
        else {
            int opd1 = Result.top();
            Result.pop();
            int opd2 = Result.top();
            Result.pop();
            if (preFix[i] == '+'){
                Result.push(opd1 + opd2);
            }
            else if (preFix[i] == '-'){
                Result.push(opd2 - opd1);
            }
            else if (preFix[i] == '*'){
                Result.push(opd1 * opd2);
            }
            else if (preFix[i] == '/'){
                Result.push(opd2 / opd1);
            }
            else if (preFix[i] == '^'){
                Result.push(pow(opd2, opd1));
            }
        }
    }
    int result = Result.top();
    return result;
}

int main(){
    cout << "Enter a VALID expression in Prefix in all lowercase : " << endl;
    string prefix;
    getline(cin, prefix);
    reverse(prefix.begin(), prefix.end());
    cout << prefixEval(prefix) << endl;
}