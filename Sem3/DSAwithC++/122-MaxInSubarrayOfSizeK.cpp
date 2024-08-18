#include <bits/stdc++.h>
using namespace std;

/*
Explanation : The complexity of the below code O(n) even though it may not seem like
*/

void printMaxInKs(vector<int> sample_vector, int k){
    deque<int> dq;
    for (int i = 0; i < k; i++){
        while (!dq.empty() && sample_vector[i] >= sample_vector[dq.back()]){
            dq.pop_back();
        }
        dq.push_back(i);
    }
    //Processed the first k above, the above method ensures that the array is in strictly descending order
    for (int i = k; i < sample_vector.size(); i++){
        cout << sample_vector[dq.front()] << endl;
        while (!dq.empty() && dq.front() <= (i - k)){
            dq.pop_front();
        }
        while (!dq.empty() && sample_vector[i] >= sample_vector[dq.back()]){
            dq.pop_back();
        }
        dq.push_back(i);
    }
    cout << sample_vector[dq.front()] << endl;
}

int main(){
    int n;
    cout << "Enter the size of the array you want : " << endl;
    cin >> n;
    int k;
    cout << "Enter the value of k : " << endl;
    cin >> k;
    cout << "Enter the elements : " << endl;
    vector<int> sample_vector;
    int item;
    for (int i = 0; i < n; i++){
        cin >> item;
        sample_vector.push_back(item);
    }
    printMaxInKs(sample_vector, k);
}