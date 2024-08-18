#include <bits/stdc++.h>
using namespace std;

/*
Explanation : We are given denominations and sum, we need to find total number of ways to reach to the sum, unlimited supply
*/

//Recursive

int getCountRec(int sum, vector<int> coins, int n){
    if (sum == 0) return 1; //sum is 0 means we found a way
    if (n == 0) return 0; //n is 0 and sum is not, hence no way
    int res = getCountRec(sum, coins, n - 1);
    if (coins[n - 1] <= sum){
        res += getCountRec(sum - coins[n - 1], coins, n); //n was kept the same since unlimited coins
    }
    return res;
}

//Apply memoization here

int getCountIter(int sum, vector<int> coins, int n){
    vector<vector<int>> memo(sum + 1, vector<int>(n, 0));
    // we have sum and n changing so 2d array
    // dp[i][j] will represent number of ways to get sum i through the first j coins, ie from 0 to j - 1 index
    // for the first row when sum is 0, we have always found a way no matter the n
    for (int i = 0; i <= n; i++){
        memo[0][i] = 1;
    }
    //for the first col, if the number of considered coins is 0, a way is only there if sum is 0, which is now already 1, rest should be 0, which they are by default
    for (int i = 1; i <= sum; i++){
        for (int j = 1; j <= n; j++){
            memo[i][j] = memo[i][j - 1]; //not considering that coin, sum stays as is, considered portion of coins reduces by 1
            if (coins[j - 1] <= i){ //testing jth coin, always -1 with data array
                memo[i][j] += memo[i - coins[j - 1]][j]; //j was kept the same since unlimited coins
            } 
        }
    }
    return memo[sum][n]; 
}

//we cant make the table n X sum, it has to be sum X n because for each coin we will be counting sums whereas we need to do the opposite. Sum dekhna h kaise ban sakta h konse konse coins se, coins konsa konsa sum bana sakte hain not that

//there exist a space optimized solution for this, see it and write it!

int main(){
    cout << "Enter the sum you want, the number of distinct coins, then enter the coins : " << endl;
    int sum;
    cin >> sum;
    int n;
    cin >> n;
    vector<int> coins;
    for (int i = 0; i < n; i++){
        int item;
        cin >> item;
        coins.push_back(item);
    }
    cout << getCountIter(sum, coins, n) << endl << getCountRec(sum, coins, n) << endl;
}