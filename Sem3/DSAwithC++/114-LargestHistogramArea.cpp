#include <bits/stdc++.h>
using namespace std;

/*
Explanation : Like in the previous code, we can find the previous smaller element and the next smaller element
*/

//Do the largest rectangle in histogram problem and maximal square problem on leetcode

int LargestHistogramAreaSolution1(vector<int> sample_vector){
    //We calculate the closest previous and next smaller arrays, and do the below things for each element

    //IMP PART IMP PART 

    vector<int> prev_smaller;
    stack<int> prev_smalls;
    for (int i = 0; i < sample_vector.size(); i++){
        while (!prev_smalls.empty() && !(sample_vector[prev_smalls.top()] < sample_vector[i])){
            prev_smalls.pop();
        }
        if (prev_smalls.size() == 0){
            prev_smalls.push(i);
            prev_smaller.push_back(-1);
        }
        else if (sample_vector[prev_smalls.top()] < sample_vector[i]){
            prev_smaller.push_back(prev_smalls.top());
            prev_smalls.push(i);
        }
    }
    vector<int> next_smaller;
    stack<int> next_smalls;
    for (int i = sample_vector.size() - 1; i >= 0; i--){
        while (!next_smalls.empty() && !(sample_vector[next_smalls.top()] < sample_vector[i])){
            next_smalls.pop();
        }
        if (next_smalls.size() == 0){
            next_smalls.push(i);
            next_smaller.push_back(-1);
        }
        else if (sample_vector[next_smalls.top()] < sample_vector[i]){
            next_smaller.push_back(next_smalls.top());
            next_smalls.push(i);
        }
    } 
    reverse(next_smaller.begin(), next_smaller.end());
    
    //The above two give the required arrays 

    // for (int i = 0; i < sample_vector.size(); i++){
    //     cout << prev_smaller[i] << endl;
    // }
    // cout << "Heyaa" << endl;
    // for (int i = 0; i < sample_vector.size(); i++){
    //     cout << next_smaller[i] << endl;
    // }

    int res = 0;
    int curr;
    for (int i = 0; i < sample_vector.size(); i++){
        curr = sample_vector[i];
        curr += (i - prev_smaller[i] - 1) * sample_vector[i];
        curr += (next_smaller[i] - i - 1) * sample_vector[i];
        res = max(res, curr);
    }
    return res;
}

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

int main(){
    cout << "Enter number of elements : " << endl;
    int n;
    cin >> n;
    vector<int> sample_vector;
    cout << "Enter the elements : " << endl;
    int item;
    for (int i = 0; i < n; i++){
        cin >> item;
        sample_vector.push_back(item);
    }
    cout << LargestHistogramAreaSolution1(sample_vector) << endl;
    cout << LargestHistogramAreaSolution2(sample_vector) << endl;
}