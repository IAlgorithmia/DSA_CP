#include <bits/stdc++.h>
using namespace std;

/*
Explanation : we are given an unlimited supply of coins in array, and a value. We need to reach the value using minimum number of coins
*/

int minCoins(int value, vector<int> &coins){
    if (value == 0){
        return 0;
    }
    int res = INT_MAX;
    int sub_res;
    for (int i = 0; i < coins.size(); i++){
        if ((value - coins[i]) >= 0){
            sub_res = minCoins(value - coins[i], coins);
            if (sub_res != INT_MAX){
                res = min(res, sub_res + 1); //adding 1 because we have made a cut here itself
            }
        }
    }
    return res;
}

//Above is recursive solution, this returns INT_MAX when no feasible solution

//Below is dp solution tabulation

int minCoinsDP(int value, vector<int> &coins){
    vector<int> memo(value + 1, INT_MAX);
    memo[0] = 0;
    for (int i = 1; i <= value; i++){
        int res = INT_MAX;
        for (int j = 0; j < coins.size(); j++){
            if (i >= coins[j]){
                res = min(res, memo[i - coins[j]]);
            }
        }
        if (res != INT_MAX){
            memo[i] = 1 + res;
        }
        //in some cases we may get no solution
    }
    return memo[value];
}

int main(){
    cout << "Enter the number of elements in array : " << endl;
    int n;
    cin >> n;
    vector<int> the_vect;
    cout << "Enter the elements : " << endl;
    for (int i = 0; i < n; i++){
        int elem;
        cin >> elem;
        the_vect.push_back(elem);
    }
    cout << "Enter the value : " << endl;
    int value;
    cin >> value;
    cout << minCoins(value, the_vect) << endl << minCoinsDP(value, the_vect) << endl;
}