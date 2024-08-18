#include <bits/stdc++.h>
using namespace std;

/*
Explanation : We gotta check if theres a subarray with sum 0
*/

bool checkSumZero (vector<int> the_vector)
{
    int starting_index = 0, ending_index = 0;
    unordered_map<int, int> my_map;
    int sum = the_vector[0];

    if (sum == 0)
    {
        cout << "From " << starting_index << " to " << ending_index << endl;
        return true;
    }
    my_map.insert({sum, 0});
    for (int i = 1; i < the_vector.size(); i++)
    {
        ending_index = i;
        sum += the_vector[i];
        if (sum == 0)
        {
            cout << "From " << 0 << " to " << ending_index << endl;
            return true;
        }
        else if (my_map.find(sum) != my_map.end()) //if say we are given to find subArray with a particular sum, instead of finding 'sum' here, we shall find 'sum - given_sum' in the HashSet, rest is the same, so SubArray with given sum aise bhi ho sakta hai, along with 42 method, upar sum == 0 ki jagah sum == given_sum ban jayegi condition
        {
            starting_index = my_map[sum] + 1;
            cout << "From " << starting_index << " to " << ending_index << endl;
            return true;
        }
        else
        {
            my_map.insert({sum, i});
        }
    }
    return false;
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
    cout << checkSumZero(my_vect);
}