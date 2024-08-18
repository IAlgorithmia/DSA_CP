#include <bits/stdc++.h>
using namespace std;

int secondLargest(vector<int> the_vector)
{
    int max = INT_MIN;
    int max_index = -1;
    int second_max = INT_MIN;
    int second_max_index = -1;
    for (int i = 0; i < the_vector.size(); i++)
    {
        if (the_vector[i] > max)
        //larger than the largest yet
        {
            second_max = max;
            second_max_index = max_index;
            max = the_vector[i];
            max_index = i;
        }
        else if ((the_vector[i] < max) && (the_vector[i] > second_max))
        {
            second_max = the_vector[i];
            second_max_index = i;
        }
    }
    return second_max_index;
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
    cout << secondLargest(my_vect);
}