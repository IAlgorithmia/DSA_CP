#include <bits/stdc++.h>
using namespace std;

/*
Explanation : We are given an array where element tells how far jumps you can make from that element

For reaching the last index n - 1, we check from which cells can we reach here, we take their minimum values ie the jumps required to reach those cells and add 1 to it 
*/

int func(vector<int> &jumps, int index){
    if (index == 0){
        return 0;
    }
    int res = INT_MAX;
    for (int i = 0; i < index; i++){
        if ((i + jumps[i]) >= index){
            //in some cases we there may not be any solution, func will return INT_MAX
            int sub_res = func(jumps, i);
            if (sub_res != INT_MAX){
                res = min(res, sub_res + 1);
            }
        }
    }
    return res;
}

int funcDP(vector<int> &jumps){
    vector<int> memo(jumps.size(), INT_MAX); //in this case we need not make + 1 dp array
    memo[0] = 0;

    for (int i = 1; i <= jumps.size(); i++){
        for (int j = 0; j < i; j++){
            if ((j + jumps[j]) >= i){
                //in some cases we there may not be any solution, func will return INT_MAX
                if (memo[j] != INT_MAX){
                    memo[i] = min(memo[i], memo[j] + 1);
                }
            }
        }
    }
    return memo[jumps.size() - 1];
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
    cout << func(the_vect, n - 1) << endl << funcDP(the_vect) << endl;
}