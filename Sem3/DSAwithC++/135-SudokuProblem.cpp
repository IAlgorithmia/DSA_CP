#include <bits/stdc++.h>
using namespace std;

/*
Explanation : Every number in every row and col should be different, every item in subgrid 2X2 should be different, for a 4X4 subgrid. For 9X9 subgrid will be for 3
Some numbers are already filled and we have to fill the zeros
*/

vector<vector<int>> grid(n, vector<int> (n));

bool isSafe(int i, int j, int k){
    for (int m = 0; m < n; m++){
        if (grid[i][m] == k || grid[m][j] == k){
            return false;
        }
    }
    int s = sqrt(n);
    int rs = i - i % s; //row start
    int cs = j - j % s; //column start
    for (int x = 0; x < s; x++){
        for (int y = 0; y < s; y++){
            if (grid[x + rs][y + cs] == k){
                return false;
            }
        }
    }
    return true;
}

bool solve(){
    int i, j;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (grid[i][j] == 0){
                break;
            }
        }
    }
    if (i == n && j == n){
        return true;
    }
    for (int k = 1; k <= n; k++){   
        if (isSafe(i, j, k)){

        }
    }
}

int main(){
    cout << "Hey there!" << endl;
}