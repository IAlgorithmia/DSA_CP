#include <bits/stdc++.h>
using namespace std;

/*
Explanation : 
Unrelated to below content : 
If we want to implement getMin operation in stack, we can create an auxilarry stack and whenever the push function is called we check if the pushed value is smaller than the top of the stack, if yes then push the new value, we dont pop the previous value. For each time we push a min element say same min 2 baar push hogya each time we need to push that value into the minimum vala stack, so the condition would be new_value <= minStack.top(). Also for each time that min element is popped we gotta check if that popped element is minStack.top() If yes then pop from min stack too. This solution is O(1) time and O(n) auxilarry space

O(1) time and space approach : 

For positives only : 

stack<int> s;
int min;

void push(int x){
    if (s.isEmpty()){
        min = t;
        s.push(x);
    }
    else if (x <= min){
        s.push(x - min);
        min = x;
    }
    else{
        s.push(x);
    }
}

int peek(){
    t = s.peek();
    return (t <= 0) ? min : t;
}

int pop(){
    t = s.pop();
    if (t <= 0){
        res = min;
        min = min - t;
        return res;
    }
    else{
        return t;
    }
}

For both +ve and -ve : 

stack<int> s;
int min;

void push(int x){
    if (s.isEmpty()){
        min = t;
        s.push(x);
    }
    else if (x <= min){
        s.push(2*x - min);
        min = x;
    }
    else{
        s.push(x);
    }
}

int peek(){
    t = s.peek();
    return (t <= min) ? min : t;
}

int pop(){
    t = s.pop();
    if (t <= min){
        res = min;
        min = 2*min - t;
        return res;
    }
    else{
        return t;
    }
}

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
