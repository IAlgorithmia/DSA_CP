#include <bits/stdc++.h>
using namespace std;

/*
Explanation : 
*/

void CountDistinctElementsInEachWindow(vector<int> the_vector, int k){
    int n = the_vector.size();
    unordered_map<int, int> frequency;
    for (int i = 0; i < k; i++){
        if (frequency.find(the_vector[i]) == frequency.end()){
            frequency[the_vector[i]] = 1;
        }
        else{
            frequency[the_vector[i]]++;
        }
    }
    cout << frequency.size() << endl;
    for (int i = k; i < n; i++){
        frequency[the_vector[i - k]]--;
        if (frequency[the_vector[i - k]] == 0){
            frequency.erase(the_vector[i - k]);
        }
        if (frequency.find(the_vector[i]) == frequency.end()){
            frequency[the_vector[i]] = 1;
        }
        else{
            frequency[the_vector[i]]++;
        }
        cout << frequency.size() << endl;
    }
}

int main(){
    cout << "Enter the array length" << endl;
    int n;
    cin >> n;
    cout << "Enter the elements" << endl;
    int elem;
    vector<int> my_vect;
    for (int i = 0; i < n; i++)
    {
        cin >> elem;
        my_vect.push_back(elem);
    }
    cout << "Enter the value of k" << endl;
    int k;
    cin >> k;
    CountDistinctElementsInEachWindow(my_vect, k);
}