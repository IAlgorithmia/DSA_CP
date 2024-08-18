#include <bits/stdc++.h>
using namespace std;

/*
Explanation : This works only for non negatives
*/

//This can also be done using a better method via hashing, see in 49

bool checkSubArraySum(vector<int> the_vector, int the_sum)
{
    int n = the_vector.size();
    int sum = the_vector[0];
    int start = 0;
    for (int end = 1; end < n; end++)
    {
        while (sum > the_sum && start < end - 1) //end - 1 and not end because khali nahi karenge sum, think about the first iteration
        {
            sum -= the_vector[start];
            start++;
        }
        if (sum == the_sum)
        {
            return true;
        }
        sum += the_vector[end];
    }
    return false;
}

int main()
{
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
    int req_sum;
    cout << "Enter the value of required sum " << endl;
    cin >> req_sum;
    cout << checkSubArraySum(my_vect, req_sum) << endl;
}