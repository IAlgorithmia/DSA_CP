#include <bits/stdc++.h>
using namespace std;

/*
Explanation : We have the first move, we can collect corner coins only, and we have to find the max value we can collect, the opponent plays as smartly as you
A simpler version : How can we always win the game, we can have a situation in which we always pick even place coins and the opponent has to pock odd placed coins or vice versa. In this case we can find the greater of odd placed or even placed and make our choices accordingly
This is a greedy problem
*/

//Recursive Solution 1

int sol(vector<int> arr, int i, int j, int sum){
    if (j == i + 1){
        //only two elements left, i = starting index j = ending index
        return max(arr[i], arr[j]);
    }
    return max(sum - sol(arr, i + 1, j, sum - arr[i]), sum - sol(arr, i, j - 1, sum - arr[j])); //first one you pick i th coin so i + 1 se j bache hai, we pick jth in the second case
}

int mainSol(vector<int> arr){
    int sum = 0;
    for (int i = 0; i < arr.size(); i++){
        sum += arr[i];
    }
    return sol(arr, 0, arr.size() - 1, sum);
}

//Recursive Solution 2

int sol2(vector<int> arr, int i, int j){
    if (i + 1 == j){
        return max(arr[i], arr[j]);
    }
    return max(arr[i] + min(sol2(arr, i + 2, j), sol2(arr, i + 1, j - 1)), arr[j] + min(sol2(arr, i, j - 2), sol2(arr, i + 1, j - 1)));
}

//Dp solution
int soldp(vector<int> arr){
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for (int i = 0; i < n - 1; i++){
        dp[i][i + 1] = max(arr[i], arr[i + 1]);
    }

    //initialization for base cases

    for (int gap = 3; gap < n; gap = gap + 2){
        for (int i = 0; i + gap < n; i++){
            int j = i + gap;
            dp[i][j] = max(arr[i] + min(dp[i + 1][j - 1], dp[i + 2][j]), arr[j] + min(dp[i + 1][j - 1], dp[i][j - 2]));
        }
    }
    return dp[0][n - 1];

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
    cout << mainSol(the_vect) << endl << sol2(the_vect, 0, n - 1) << endl << soldp(the_vect) << endl;
}