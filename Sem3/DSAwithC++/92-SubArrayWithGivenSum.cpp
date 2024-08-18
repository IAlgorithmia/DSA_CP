#include <bits/stdc++.h>
using namespace std;

/*
Explanation : We gotta check if theres a subarray with sum 0
*/

bool checkGivenSum (vector<int> the_vector, int given_sum)
{
    int starting_index = 0, ending_index = 0;
    unordered_map<int, int> my_map;
    int sum = the_vector[0];

    if (sum == given_sum)
    {
        cout << "From " << starting_index << " to " << ending_index << endl;
        return true;
    }
    my_map.insert({sum, 0});
    for (int i = 1; i < the_vector.size(); i++)
    {
        ending_index = i;
        sum += the_vector[i];
        if (sum == given_sum)
        {
            cout << "From " << 0 << " to " << ending_index << endl;
            return true;
        }
        else if (my_map.find(sum - given_sum) != my_map.end())
        {
            starting_index = my_map[sum - given_sum] + 1;
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
    cout << "Enter the required sum" << endl;
    int sum;
    cin >> sum;
    cout << checkGivenSum(my_vect, sum) << endl;
}