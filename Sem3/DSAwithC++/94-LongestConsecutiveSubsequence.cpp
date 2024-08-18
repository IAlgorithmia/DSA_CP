#include <bits/stdc++.h>
using namespace std;

/*
Explanation : We have two methods for this, 1 by sorting then seeing the stuff O(nlogn) another by 
*/

int checkLongestConsecutive1(vector<int> the_vector){
    int n = the_vector.size();
    sort(the_vector.begin(), the_vector.end());
    int res = 1, curr = 1;
    for (int i = 1; i < n; i++){
        if (the_vector[i - 1] == the_vector[i] - 1){
            curr++;
        }
        else{
            res = max(res, curr);
            curr = 1;
        }
    }
    res = max(res, curr);
    return res;
}

int checkLongestConsecutive2(vector<int> the_vector){
    int n = the_vector.size();
    int res = 1, curr, item;
    unordered_set<int> nums;
    for (int i = 0; i < n; i++){
        nums.insert(the_vector[i]);
    }
    for (auto x : nums){
        curr = 1;
        item = x;
        while (nums.find(item + 1) != nums.end()){
            curr++;
            item++;
        }
        res = max(res, curr);
    }
    return res;
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
    cout << checkLongestConsecutive1(my_vect) << endl;
    cout << checkLongestConsecutive2(my_vect) << endl;
}