#include <bits/stdc++.h>
using namespace std;

/**
 * Finds the maximum difference between two elements in the array such that the second element is greater than the first.
 * 
 * This function takes a vector of integers as input and returns the maximum difference between two elements in the array.
 * The difference is calculated as arr[j] - arr[i] where j > i.
 * 
 * Example:
 * Input: [2, 3, 10, 6, 4, 8, 1]
 * Output: 8 (because 10 - 2 = 8 is the maximum difference)
 * 
 * @param the_vector A vector of integers
 * @return The maximum difference between two elements in the array
 */
int maxDiff(vector<int> the_vector)
{
    int n = the_vector.size();
    int min = the_vector[0];
    int diff = INT_MIN;
    for (int i = 1; i < n; i++)
    {
        if ((the_vector[i] - min) > diff)
        {
            diff = (the_vector[i] - min);
        }
        if (the_vector[i] < min)
        {
            min = the_vector[i];
        }
    }
    return diff;
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
    cout << "Maximum difference: " << maxDiff(my_vect) << endl;
    return 0;
}