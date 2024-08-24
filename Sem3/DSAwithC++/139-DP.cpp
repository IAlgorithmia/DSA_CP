#include <bits/stdc++.h>
using namespace std;

//Do maximal square and maxinaml rectangle

/*
Explanation : 

TRY TO WRITE THE RECURSIVE SOLUTION IN THE FORM OF INCLUDE EXCLUDE, THEN TAKE THEIR MAX OR MIN OR SUM OR WHATEVER
IMPROVES CLARITY

DP is just an optimization over plain recursion, the idea is to reuse the solution of subproblems when  they are overlapping
DP ways : 

Memoization - Top Down
Tabulation - Bottom Up

Bellman Ford
Floyd Warshal
Diff Utility (LCS)
Search Closed Words (Edit Distance)
Resource Allocation (0 - 1 knapsack)

The dimensions of the memo array are picked as per the number of parameters we are passing to the recursive function that need to be memoized, if one then single array, if two then matrix and so on
The size is picked by the maximum values that we will be passing to those parameters + 1

The first part of DP is to make a recursive solution

Fibo example : 

vector<int> memo(n, -1);

int fib(int n){
    if (memo[n] == -1){
        int res;
        if (n == 0 || n == 1){
            res = n;
            return n;
        }
        else{
            res = fib(n - 1) + fib(n - 2);
        }
        memo[n] = res;
    }
    return memo[n];
}

Tabulation : 

vector<int> fib(n + 1);

int fib(int n){
    int fib[n + 1];
    f[0] = 0;
    f[1] = 1;
    for (int i = 2; i <= n; i++){
        f[i] = f[i - 1] + fib[i - 2];
    }
    return f[n];
}

Memoization is easy after you have deviced the recursive solution
Tabulation is sometimes a little less easy

FOR DP THINK IN TERMS OF OVERLAPPING SUBPROBLEMS 
HUMESHA HUMESHA PEHLE RECURSIVE SOLUTION BANANA H US SE TABULATION/MEMOIZATION KE HINTS MILENGE, AND SAME CHEEZ KRNI H IN TABULATION, RECURSIVE LIKHNA H PEHLE

*/

int main(){
    cout << "Hey there!" << endl;
}