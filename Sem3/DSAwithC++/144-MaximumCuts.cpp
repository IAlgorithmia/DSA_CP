#include <bits/stdc++.h>
using namespace std;

/*
Explanation : Given n a b c we want to make max cuts in n such that length of each cut should be a b or c
*/

int maxCuts(int n, int a, int b, int c){
    if (n == 0){
        return 0; //putting 1 here
    }
    if (n < 0){
        return -1; //and putting 0 here results in 1 + the actual answer. Vahan humein res + 1 chahiye to maintain the one more curt logic, hence we change the values here
    }
    int res;
    res = max(maxCuts(n - a, a, b, c), max(maxCuts(n - b, a, b, c), maxCuts(n - c, a, b, c)));
    
    //simply returning res will always result in 1 if there is a way, -1 when there isn't. What we want is the number of cuts that have been applied
    if (res >= 0){
        //means we found a way
        return res + 1; //add one more cut since res = n - value ke kitne ho rahe ahin, and abhi abhi ek kara bhi h
    }
    else{
        return res; //else 0 hi jaane do
    }
}

//above is reclusive, 3 to the power n, below is dp 

int maxCutsDp(int n, int a, int b, int c){
    vector<int> dp(n + 1, -1);
    dp[0] = 0; //since the number of ways to make cuts when sum is 0 is 0
    for (int i = 1; i <= n; i++){
        if ((i - a) >= 0){ //i is the sum here for which we are processing
            dp[i] = max(dp[i], dp[i - a]);
        }
        if ((i - b) >= 0){
            dp[i] = max(dp[i], dp[i - b]);
        }
        if ((i - c) >= 0){
            dp[i] = max(dp[i], dp[i - c]);
        }
        if (dp[i] != -1){ //means koi na koi tareeka nikla h, now we need to make one more cut
            dp[i]++;
        }
    }
    return dp[n];
}

int main(){
    cout << "Enter n, a, b, and c : " << endl;
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    cout << maxCuts(n, a, b, c) << endl << maxCutsDp(n, a, b, c) << endl;
}