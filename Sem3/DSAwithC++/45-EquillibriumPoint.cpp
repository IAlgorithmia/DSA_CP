#include <bits/stdc++.h>
using namespace std;

/*
Explanation : An index such taht the sum of elems to left == to right
*/

//Prefix sum technique but we don't create the array, saving auxillary space
bool checkEqui(vector<int> the_vector)
{
    int n = the_vector.size();
    int total_sum, left_sum;
    total_sum = 0;
    for (int i = 0; i < n; i++)
    {
        total_sum += the_vector[i];
    }
    left_sum = 0;
    for (int i = 0; i < n; i++)
    {
        if ((total_sum - the_vector[i] - left_sum) == left_sum)
        {
            return true;
        }
        left_sum += the_vector[i];
    }
    return false;
}

//Below code creates prefix sum array and suffix sum array
// bool checkEqui(vector<int> the_vector)
// {
//     int n = the_vector.size();
//     vector<int> prefix_left, prefix_right;
//     prefix_left.push_back(the_vector[0]);
//     for (int i = 1; i < n; i++)
//     {
//         prefix_left.push_back(the_vector[i] + prefix_left[i - 1]);
//     }
//     prefix_right.push_back(the_vector[n - 1]);
//     for (int i = n - 2; i >= 0; i--)
//     {
//         prefix_right.push_back(the_vector[i] + prefix_right[(n - 2) - i]);
//     }
//     reverse(prefix_right.begin(), prefix_right.end());
//     for (int i = 1; i < n - 1; i++)
//     {
//         if (prefix_left[i - 1] == prefix_right[i + 1])
//         {
//             return true;
//         }
//     }
//     if ((prefix_right[1] == 0) || (prefix_left[n - 2] == 0))
//     {
//         return true;
//     }
//     return false;
// }

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
    cout << checkEqui(my_vect);
}