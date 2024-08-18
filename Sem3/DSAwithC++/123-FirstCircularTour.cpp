#include <bits/stdc++.h>
using namespace std;

/*
Explanation : 
*/

int tellStartingPump(vector<int> sample_vector_1, vector<int> sample_vector_2){
    deque<int> dq;
    int curr_petrol = 0;
    int count = 0;
    int checked_as_starting = 0;
    while ((checked_as_starting < sample_vector_1.size()) && (dq.size() < sample_vector_1.size())){
        dq.push_back(count);
        curr_petrol += sample_vector_1[count];
        curr_petrol -= sample_vector_2[count];
        while (!dq.empty() && curr_petrol < 0){
            curr_petrol -= sample_vector_1[dq.front()];
            curr_petrol += sample_vector_2[dq.front()];
            dq.pop_front();
            checked_as_starting++;
        }
        count = (count + 1) % sample_vector_1.size();
    }
    return (dq.size() == sample_vector_1.size() ? sample_vector_1[dq.front()] : -1);
}

int main(){
    int n;
    cout << "Enter the size of arrays you want : " << endl;
    cin >> n;
    cout << "Enter the elements for petrol pumps : " << endl;
    vector<int> sample_vector_1;
    int item;
    for (int i = 0; i < n; i++){
        cin >> item;
        sample_vector_1.push_back(item);
    }
    cout << "Enter the elements for distances : " << endl;
    vector<int> sample_vector_2;
    for (int i = 0; i < n; i++){
        cin >> item;
        sample_vector_2.push_back(item);
    }
    cout << tellStartingPump(sample_vector_1, sample_vector_2) << endl;
}