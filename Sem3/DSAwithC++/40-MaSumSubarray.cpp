#include <bits/stdc++.h>
using namespace std;

/*
Explanation : Size diya hua hai, we gotta find the subarray with that size of max sum
*/

int maxSumSubarray(vector<int> the_vector, int k)
{
    int n = the_vector.size();
    int sum = 0, maxsum = 0;
    for (int i = 0; i < k; i++)
    {
        sum += the_vector[i];
    }
    maxsum = sum;
    for (int i = k; i < n; i++)
    {
        sum += (the_vector[i] - the_vector[i - k]);
        maxsum = max(maxsum, sum);
    }
    return maxsum;
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
    int k;
    cout << "Enter the value of k " << endl;
    cin >> k;
    cout << maxSumSubarray(my_vect, k) << endl;
}