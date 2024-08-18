#include <bits/stdc++.h>
using namespace std;

/*
Explanation : rat needs to go from top left to bottom right, can only move down or right, 1 are allowed box, 0 is blocked box
*/

//We need three things a wrapper function, an isSSafe function, and a recursive function

vector<vector<bool>> maze[n][n], sol[n][n];

bool isSafe(int i, int j){
    return (i < n && j < n && maze[i][j] == 1);
}

bool solveMaze(){
    if (solveMazeRec(0, 0) == false){
        return false;
    }
    else{
        printMatrix(sol);
        return true;
    }
}

bool solveMazeRec(int i, int j){
    if (i == n - 1 || j == n - 1) {
        sol[i][j] = 1; 
        return true;
    }
    if (isSafe(i, j) == true){
        sol[i][j] = 1;
        if (solveMazeRec(i + 1, j)){
            return true;
        }
        else if (solveMazeRec(i, j + 1)){
            return true;
        }
        sol[i][j] = 0;
    }
    return false;
}

int main(){
    cout << "Hey there!" << endl;
}