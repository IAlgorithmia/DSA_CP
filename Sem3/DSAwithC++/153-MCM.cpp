#include <bits/stdc++.h>
using namespace std;

/*
Explanation : WE are given an array, of size n lets say, they represent sizes of n - 1 matrices, common lena hai for each dimension
Just think in terms of first partition
*/

int recur(vector<int> arr, int i, int j){
    if (i + 1 == j){
        return 0;
    }
    int res = INT_MAX;
    for (int k = i + 1; k < j; k++){
        res = min(res, recur(arr, i, k) + recur(arr, k, j) + arr[i] * arr[k] * arr[j]);
    }
    return res;
}

int MCMdp(vector<int> arr){
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(n));
    for (int i = 0; i < n -1 ; i++){
        dp[i][i + 1] = 0;
    }
    for (int gap = 2; gap < n; gap++){
        for (int i = 0; i + gap < n; i++){
            int j = i + gap;
            dp[i][j] = INT_MAX;
            for (int k = i + 1; k < j; k++){
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[j][k] + (arr[i] * arr[k] * arr[j]))
            }
        }
    }
    return dp[0][n - 1];
}

int main(){
    cout << "Hey there!" << endl;
}