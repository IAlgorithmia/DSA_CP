//Leetcode one at bottom

#include <bits/stdc++.h>
using namespace std;

/*
Explanation : Matrix elements are stored in Row Major order, contiguous locations, internal curly brackets are optional. Only the first dimension can be omitted ni >1D arrays.
1st Method : We can create a double pointer which points to an array of pointers, this is not cache friendly
2nd Method : We create an array of pointers, rest of the things are same as above
3rd Method : Array of Vectors
4th Method : Vector of Vectors

To rotate an array by 90 degrees in anti clockwise direction, take its transpose, then for each column, do array[r][column_number] = array[rows - r - 1][column_number] basically swap them one by one. Agar clockwise rotation hai to do the same thing for rows. Basically hum reverse kar rahe hain.
*/

void TraverseSpiral(vector<vector<int>> sampleVector){
    int rows = sampleVector.size();
    int cols = sampleVector[0].size();

    int top = 0, bottom = rows - 1, left = 0, right = cols - 1;

    while (top <= bottom && left <= right){
        for (int i = left; i <= right; i++){
            cout << sampleVector[top][i] << " ";
        }
        top++;
        if (top >= rows){
            break;
        }
        for (int i = top; i <= bottom; i++){
            cout << sampleVector[i][right] << " ";
        }
        right--;
        if (right < 0){
            break;
        }
        for (int i = right; i >= left; i--){
            cout << sampleVector[bottom][i] << " ";
        }
        bottom--;
        if (bottom < 0){
            break;
        }
        for (int i = bottom; i >= top; i--){
            cout << sampleVector[i][left] << " ";
        }
        left++;
        if (left >= cols){
            break;
        }
    }
    cout << endl;
}

int main(){
    // vector<vector <int>> sampleVector1 = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    vector<vector<int>> sampleVector1 = {{10}, {20}, {30}};
    TraverseSpiral(sampleVector1);
}

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int minRow = 0;
        int minCol = 0;
        int maxRow = n - 1;
        int maxCol = m - 1;
        int count = 0;
        vector<int> answer;
        while (true){
            for (int i = minCol; i <= maxCol; i++){
                answer.push_back(matrix[minRow][i]);
            }
            minRow++;
            if (minRow > maxRow) break;
            for (int i = minRow; i <= maxRow; i++){
                answer.push_back(matrix[i][maxCol]);
            }
            maxCol--;
            if (minCol > maxCol) break;
            for (int i = maxCol; i >= minCol; i--){
                answer.push_back(matrix[maxRow][i]);
            }
            maxRow--;
            if (minRow > maxRow) break;
            for (int i = maxRow; i >= minRow; i--){
                answer.push_back(matrix[i][minCol]);
            }
            minCol++;
            if (minCol > maxCol) break;
        }
        return answer;
    }
};