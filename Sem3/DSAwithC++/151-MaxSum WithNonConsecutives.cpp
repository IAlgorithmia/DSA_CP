#include <bits/stdc++.h>
using namespace std;

/*
Explanation : Max sum that cna be obtained by considering elements which are non consecutive
*/

int recur(vector<int> the_vect){
    
    int n = the_vect.size();

    if (n == 1){
        return the_vect[0];
    }
    if (n == 2){
        return max(the_vect[0], the_vect[1]);
    }
    return max(recur(the_vect, n - 1), recur(the_vect, n - 2) + the_vect[n]);
}

int maxDp(vector<int> the_vect){

    int n = the_vect.size();

    vector<int> dp(n + 1);

    if (n == 1){
        return arr[0];
    }

    dp[1] = arr[0];
    dp[2] = max(arr[0], arr[1]);

    for (int i = 3; i <= n; i++){
        dp[i] = max(dp[i - 1], dp[i - 2] + the_vect[i - 1]);
    }

    return dp[n];
}

int optimized(vector<int> the_vect){

    int n = the_vect.size();

    if (n == 1){
        return the_vect[0];
    }

    int prev_prev = arr[0];
    int prev = max(arr[0], arr[1]);

    int res = prev; //final answer to be maintained

    for (int i = 3; i <= n; i++){
        res = max(prev, prev_prev + the_vect[i]);
        prev_prev = prev;
        prev = res;
    }

    return res;

}

int main(){
    cout << "Hey there!" << endl;
}