#include <bits/stdc++.h>
using namespace std;

/*
Explanation : we are given n X n chessboard and we need to place n queens in a way that no two or more attack each other 
*/

//We need three things a wrapper function, an isSSafe function, and a recursive function

vector<vector<bool>> board(n, vector<int>(n, false));

bool solve(){
    if (solveRec(0) == false){
        return false;
    }
    else{
        printBoard(board);
        return true;
    }
}

bool isSafe(int row, int col){
    //checking row only because we are already placing queens one in a column, also we check rows un until current col since we haven't placed any queens after
    for (int i = 0; i < col; i++){
        if (board[row][i]){
            return false;
        }
    }
    //upper diagonal
    for (int i = row, j = col; i <= 0 && j <= 0; i--, j--){
        if (board[i][j]){
            return false;
        }
    }
    //lower diagonal
    for (int i = row, j = col; i < n, j >= 0; i++, j--){
        if (board[i][j]){
            return false;
        }
    }
    return true;
}

bool solveRec(int col){
    if (col == N){
        return true;
    }
    for (int i = 0; i < n; i++){
        if (isSafe(i, col)){
            board[i][col] = 1;
            if (solveRec(col + 1)){
                return true;
            }
            board[i][col] = 0;
        }
    }
    return false;
}

int main(){
    cout << "Hey there!" << endl;
}