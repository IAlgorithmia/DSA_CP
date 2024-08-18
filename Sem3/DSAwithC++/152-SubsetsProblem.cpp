#include <bits/stdc++.h>
using namespace std;

/*
Explanation : Count of subsets whose sum is equal to given sum
*/

int countSubsets(vector<int> the_vect, int sum, int n){
    if (n == 0){
        return (sum == 0) ? 1 : 0;
    }
    return countSubsets(the_vect, sum - the_vect[n - 1], n - 1) + countSubsets(the_vect, sum, n - 1)
}

int dpSolution(vector<int> the_vect, int sum){
    int n = the_vect.size();
    vector<vector<int>> memo(sum + 1, vector<int> (n + 1));
    for (int i = 0; i <= n; i++){
        memo[0][i] = 1; //ways for forming 0 sum with i elements = 1, not taking anything
    }
    for (int i = 1; i <= sum; i++){
        memo[i][0] = 0; //what non zero sum can you form using 0 elements
    }
    for (int i = 1; i <= sum; i++){
        for (int j = 1; j <= n; j++){
            if (the_vect[j - 1] > i){
                memo[i][j] = memo[i][j - 1];
            }
            else{
                memo[i][j] = memo[i - the_vect[j - 1]][j - 1] + memo[i][j - 1]; 
            }
        }
    }
    return memo[sum][n];
}

int main(){
    cout << "Hey there!" << endl;
}