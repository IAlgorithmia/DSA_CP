#include <bits/stdc++.h>
using namespace std;

/*
Explanation : Egg dropped from the lowest floor such that it breaks is called as threshold floor
if threshold floor is i, then greater than i floors also break the egg
egg may break from the first flor itself
egg may not break even from the top most floor 10th floor

floors are 1 to 10

we have the return the number of trials we will need in the worst case

Recursive Solution : 

let res(f, e) = minimum number of trials needed for finding out the threshold floor with f floors remaining to test and e unbroken eggs left, in the worst case

base cases : 

res(1, e) = 1
res(0, e) = 0
res(f, 1) = f

Lets say we are dropping from the xth floor

res(x, e) = Max(res(x - 1, e - 1), res(f - x, e))

Out of all the values from x = 1 to f, both inclusive, we have to assign the minimum to res(f, e)
Sabhi floors ka worst case dekh lia, ab uska minimum lena h

*/

//dp solution

int eggsDP(int e, int f){
    vector<vector<int>> dp(f + 1, vector<int>(e));
    for (int i = 1; i <= e; i++){
        dp[1][i] = 1;
        dp[0][i] = 0;
    }
    for (int i = 1; i <= f; i++){
        dp[i][1] = i;
    }
    //base cases initialized
    for (int i = 2; i <= f; i++){
        for (int j = 2; j <= e; j++){
            dp[i][j] = INT_MAX;
            for (int x = 1; x <= i; x++){
                dp[i][j] = min(dp[i][j], max(dp[i - 1][j - 1], dp[i - x][j]));
            }
        }
    }
    return dp[f][e];
}

int main(){
    cout << "Hey there!" << endl;
}