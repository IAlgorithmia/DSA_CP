//Kahin bhi subarray sum aa jaaye to curr_sum and map vali approach chipkado

#include <bits/stdc++.h>
using namespace std;

/*
Although the below doesnt print all possible combinations, it tells the largest one
Say we are given an array of 0s and 1s and we are required to find the longest length of subarray with equal number of 0s and 1s, we replace all the 0s by -1s and use the below function to find the longest subarray with 0 sum. Btw such arrays are called as binary arrays.
Say we are given two binary arrays of same size, we need to find the longest common span of both the arrays which has the same sum, for this we create a new array temp with temp[i] = array1[i] - array2[i] then we apply the longest subarray with 0 sum, voila
*/

int checkLongestGivenSum (vector<int> the_vector, int given_sum)
{
    int starting_index = 0, ending_index = 0;
    unordered_map<int, int> my_map;
    int sum = the_vector[0];
    int max_length = INT_MIN; //iski jagah max_starting and max_ending leke bhi update kar sakte ho

    if (sum == given_sum)
    {
        cout << "From " << starting_index << " to " << ending_index << endl;
        max_length = max(max_length, ending_index - starting_index + 1);
    }
    my_map.insert({sum, 0});
    for (int i = 1; i < the_vector.size(); i++)
    {
        ending_index = i;
        sum += the_vector[i];
        if (sum == given_sum)
        {
            cout << "From " << 0 << " to " << ending_index << endl;
            max_length = max(max_length, ending_index - starting_index + 1);
        }
        else if (my_map.find(sum - given_sum) != my_map.end())
        {
            starting_index = my_map[sum - given_sum] + 1;
            cout << "From " << starting_index << " to " << ending_index << endl;
            max_length = max(max_length, ending_index - starting_index + 1);
        }
        else if (my_map.find(sum) == my_map.end())
        {
            //The sum is not already present, since we want the length to be the largest, we keep the lowermost index of each sum, such that difference can be maximized in the future
            my_map.insert({sum, i});
        }
    }
    return (max_length == INT_MIN ? 0 : max_length);
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
    cout << checkLongestGivenSum(my_vect, sum) << endl;
}