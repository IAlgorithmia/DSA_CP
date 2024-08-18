#include <bits/stdc++.h>
using namespace std;

/*
Explanation : To check if two intervals overlap or not, we can either check whether the larger of the start values lies in the other range OR whether the samller of the end values lies in the other range or not

Approach 1 and 2 are both similar

Approach 1 : Sort the pairs in increasing order of first element
The key idea is that if all previous interals have been merged into non overlapping intervals, the nect interval will only have to be checked and merged with the interval just before it, not others behind that

Approach 2 : Sort the pairs in decreasing order of last element
*/

bool overlapping(vector<int> interval_1, vector<int> interval_2){
    if (interval_1[0] >= interval_2[0]){
        if (interval_1[0] <= interval_2[1]){
            return true;
        }
        else{
            return false;
        }
    }
    else{
        if (interval_2[0] <= interval_1[1]){
            return true;
        }
        else{
            return false;
        }
    }
}

void mergeOverLapping(vector<vector<int>> &intervalsList){
    sort(intervalsList.begin(), intervalsList.end(), [](const auto &a, const auto &b){
        return a[0] < b[0];
    });
    int n = intervalsList.size();
    for (int i = 1; i < intervalsList.size(); i++){
        
        if (overlapping(intervalsList[i], intervalsList[i - 1])){
            int lower = min(intervalsList[i][0], intervalsList[i - 1][0]);
            int higher = max(intervalsList[i][1], intervalsList[i - 1][1]);
            intervalsList.erase(intervalsList.begin() + i - 1); //we remove the previous one and update the current one
            intervalsList[i] = {lower, higher};
        }
    }
    cout << "After merging : " << endl;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < 2; j++){
            cout << intervalsList[i][j] << " ";
        }
        cout << endl;
    }
}

//the above solution is O(n square)

//efficient implementation below : this requires us to limit the array and effectively change the elements

void mr

int main(){
    cout << "Enter how many pairs you want to add : " << endl;
    int n;
    cin >> n;
    cout << "Enter the elements : " << endl;
    int elem;
    vector<vector<int>> my_vect;
    vector<int> temp;
    for (int i = 0; i < n; i++){
        temp.clear();
        for (int j = 0; j < 2; j++){
            cin >> elem;
            temp.push_back(elem);
        }
        my_vect.push_back(temp);
    }
    cout << "Before merging : " << endl;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < 2; j++){
            cout << my_vect[i][j] << " ";
        }
        cout << endl;
    }
    mergeOverLapping(my_vect);
    cout << "After merging : " << endl;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < 2; j++){
            cout << my_vect[i][j] << " ";
        }
        cout << endl;
    }
}