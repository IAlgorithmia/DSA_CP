#include <bits/stdc++.h>
using namespace std;

int rainWater(vector<int> the_vector)
{
    //We precompute the right max and left max for each index
    int n = the_vector.size();
    vector<int> left_max_vect, right_max_vect;
    
    left_max_vect.push_back(the_vector[0]);
    for (int i = 1; i < n; i++)
    {
        left_max_vect.push_back(max(the_vector[i], left_max_vect[i - 1]));
    }

    right_max_vect.push_back(the_vector[n - 1]);
    for (int i = n - 2; i >= 0; i--)
    {
        right_max_vect.push_back(max(right_max_vect[n - 2 - i], the_vector[i]));
    }
    reverse(right_max_vect.begin(), right_max_vect.end());
    int volume = 0;
    int min_height;
    for (int i = 1; i < n - 1; i++)
    {
        min_height = min(left_max_vect[i], right_max_vect[i]);
        volume += (min_height - the_vector[i]);
    }
    return volume;
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
    cout << rainWater(my_vect) << endl;
}