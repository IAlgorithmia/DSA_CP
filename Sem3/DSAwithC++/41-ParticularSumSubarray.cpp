#include <bits/stdc++.h>
using namespace std;

/*
Explanation : We gotta check if there is a subarray with the given sum of a length k.
*/

bool checkSubArraySum(vector<int> the_vector, int k, int the_sum)
{
    int n = the_vector.size();
    int sum = 0;
    for (int i = 0; i < k; i++)
    {
        sum += the_vector[i];
    }
    if (sum == the_sum)
    {
        return true;
    }
    for (int i = k; i < n; i++)
    {
        sum += (the_vector[i] - the_vector[i - k]);
        if (sum == the_sum)
        {
            return true;
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
    int k, req_sum;
    cout << "Enter the value of k and required sum " << endl;
    cin >> k >> req_sum;
    cout << checkSubArraySum(my_vect, k, req_sum) << endl;
}