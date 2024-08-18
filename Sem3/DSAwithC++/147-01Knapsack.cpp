#include <bits/stdc++.h>
using namespace std;

/*
Explanation : we already know
HUMESHA RECURSION END SE START KARO 
*/

int func(vector<int> &weights, vector<int> &values, int rem_weight, int index){
    
    if ((rem_weight == 0) || (index == -1)){
        return 0;
    }
    int res = func(weights, values, rem_weight, index - 1); //not including
    if (weights[index] <= rem_weight){
        res = max(res, values[index] + func(weights, values, rem_weight - weights[index], index - 1));
    }
    return res;
}

//the above has time complexity O(2^n), and the below has O(w X n), so if w is very very large as compared to n then recursive solution comes out better

int funcDP(vector<int> &weights, vector<int> &values, int capacity, int size){
    //when confused whether to make mXn or nXm koi bhi banado bc dekhi jegi
    vector<vector<int>> memo(index + 1, vector<int> (capacity + 1, 0));
    // dp[i][j] represents the maximum value we can obtain for knapsack capacity j and using the first i items 
    // obvio first row ad column will be completely 0 
    for (int i = 1; i <= index; i++){
        for (int j = 1; j <= capacity; j++){
            if (weights[i - 1] > j){
                memo[i][j] = memo[i - 1][j];
            }
            else{
                memo[i][j] = max(memo[i - 1][j], values[i - 1] + memo[i - 1][j - weights[i - 1]]);
            }
        }
    }
    return memo[index][capacity];
}

int main(){
    cout << "Enter the number of items : " << endl;
    int n;
    cin >> n;
    vector<int> the_vect_weights;
    cout << "Enter the weight elements : " << endl;
    for (int i = 0; i < n; i++){
        int elem;
        cin >> elem;
        the_vect_weights.push_back(elem);
    }
    vector<int> the_vect_values;
    cout << "Enter the value elements : " << endl;
    for (int i = 0; i < n; i++){
        int elem;
        cin >> elem;
        the_vect_values.push_back(elem);
    }
    cout << "Enter the knapsack capacity : " << endl;
    int capacity;
    cin >> capacity;
    cout << func(the_vect_weights, the_vect_values, capacity, n - 1) << endl << funcDP(the_vect_weights, the_vect_values, capacity, n) << endl;
}