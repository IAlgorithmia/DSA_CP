#include <bits/stdc++.h>
using namespace std;

/*
Explanation : We will use the two pointer approach to find the doublet
*/

bool findPythagoreanTriplet(vector<int> the_vector)
{
    int n = the_vector.size();
    int low, high;
    int curr_sum, the_sum;
    for (int i = 0; i < n; i++)
    {
        low = 0;
        high = the_vector.size() - 1;
        the_sum = (the_vector[i] * the_vector[i]);
        while (low <= high)
        {
            curr_sum = (the_vector[low] * the_vector[low]) + (the_vector[high] * the_vector[high]);
            if (curr_sum == the_sum)
            {
                return true;
            }
            else if (curr_sum < the_sum)
            {
                low++;
            }
            else
            {
                high--;
            }
        }
    }
    return false;
}

bool findDoublet(vector<int> the_vector, int the_sum)
{
    int low = 0;
    int high = the_vector.size() - 1;
    int curr_sum;
    while (low <= high)
    {
        curr_sum = the_vector[low] + the_vector[high];

        if (curr_sum == the_sum)
        {
            return true;
        }
        else if (curr_sum < the_sum)
        {
            low++;
        }
        else
        {
            high--;
        }
    }
    return false;
}

bool findTriplet(vector<int> the_vector, int the_sum)
{
    // O(n square) solution, for each element we call findDoublet
    for (int i = 0; i < the_vector.size(); i++)
    {
        if (findDoublet(the_vector, the_sum - the_vector[i]))
        {
            return true;
        }
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
    cout << findPythagoreanTriplet(my_vect);
}