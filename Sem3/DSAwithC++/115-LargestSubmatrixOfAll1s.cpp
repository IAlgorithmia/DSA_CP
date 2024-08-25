#include <bits/stdc++.h>
using namespace std;

/*
Explanation : 

*/

int LargestHistogramAreaSolution2(vector<int> sample_vector){
    stack<int> s;
    int res = 0;
    int n = sample_vector.size();
    int tp, curr;
    for (int i = 0; i < n; i++){
        while (s.empty() == false && sample_vector[s.top()] >= sample_vector[i]){
            tp = s.empty() ? tp : s.top();
            s.pop();
            curr = sample_vector[tp] * (s.empty() ? i : (i - s.top() - 1));
            res = max(res, curr);
        }
        s.push(i);
    }
    while (s.empty() == false){
        tp = s.empty() ? tp : s.top();
        s.pop();
        curr = sample_vector[tp] * (s.empty() ? n : (n - s.top() - 1));
        res = max(res, curr);
    }
    return res;
}

int LargestRectangleWithAll1s(vector<vector<int>> sample_matrix){
    vector<int> heights(sample_matrix[0].size(), 0);
    int largestArea = INT_MIN;
    for (int i = 0; i < sample_matrix.size(); i++){
        for (int j = 0; j < sample_matrix[0].size(); j++){
            heights[j] = (sample_matrix[i][j]) ? (heights[j] + sample_matrix[i][j]) : 0;
        }
        largestArea = max(LargestHistogramAreaSolution2(heights), largestArea);
    }
    return largestArea;
}

int main(){
    cout << "Enter number of rows : " << endl;
    int rows;
    cin >> rows;
    cout << "Enter number of cols : " << endl;
    int cols;
    cin >> cols;
    vector<vector<int>> sample_matrix(rows, vector<int>(cols));
    cout << "Enter the elements : " << endl;
    int item;
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            cin >> item;
            sample_matrix[i][j] = item;
        }
    }
    cout << "Final answer is : " << LargestRectangleWithAll1s(sample_matrix) << endl;
}
