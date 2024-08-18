#include <bits/stdc++.h>
using namespace std;

//ROTATE A MATRIX BY 90 DEGREES CLOCKWISE : 
// TRANSPOSE THE MATRIX THEN REVERSE INDIVIDUAL ROWS

//ROTATE A MATRIX BY 90 DEGREES ANTI CLOCKWISE : 
// TRANSPOSE THE MATRIX THEN REVERSE INDIVIDUAL COLUMNS

/*
Explanation : We start from the top right, if the element is the same, we return the indices right away, if our req number is smaller, we move left, else we move down. We can actually use the bottom left corner also, and change the method accordingly.
*/

void SearchInMatrix(vector<vector<int>> sampleVector, int item){
    int rows = sampleVector.size();
    int cols = sampleVector[0].size();
    int i = 0, j = cols - 1; //beginning from top left

    while ((i < rows) && (j >= 0)){ //since i can only be increased and j can only be decreased
        if (item == sampleVector[i][j]){
            cout << "Element found at " << i << " " << j << endl;
            return;
        }
        else if (item > sampleVector[i][j]){
            i++;
        }
        else{
            //btw we can do binary search here as a further optimization
            j--;
        }
    }
    cout << "Element not found!" << endl;
}

int main(){
    vector<vector<int>> sampleVector = {{10, 20, 30, 40}, {15, 25, 35, 45}, {27, 29, 37, 48}, {32, 33, 39, 50}};
    SearchInMatrix(sampleVector, 25);
}