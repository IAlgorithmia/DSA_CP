#include <bits/stdc++.h>
using namespace std;

/*
Explanation : We are given n and we need to count how many unique BSTs we can make using n distinct keys

res(n) = res(0) * res(n - 1) + ... + res(n - 1) * res(0)
*/

int countBST(int n){
    vector<int> dp(n + 1);
    dp[0] = 1;
    for (int i = 1; i <= n; i++){
        int res = 0;
        for (int j = 0; j < i; j++){
            res += dp[j] * dp[i - 1 - j];
        }
        dp[i] = res;
    }
    return dp[n];
}

//Aux space O(n)
// Actually the answer is catalyn number : 2n C n * (1 / (n + 1))

int main(){
    cout << "Hey there!" << endl;
}