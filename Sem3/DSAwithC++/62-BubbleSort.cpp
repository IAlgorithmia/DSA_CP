#include <bits/stdc++.h>
using namespace std;

/*
Explanation : 
*/

void bubblesort(vector<int>& the_vector)
{
    int n = the_vector.size();
    for (int i = 0; i < n - 1; i++)
    {
        bool swapped = false;
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (the_vector[j] > the_vector[j + 1])
            {
                swap(the_vector[j], the_vector[j + 1]);
                swapped = true;
            }
        }
        if (!swapped)
        {
            return;
        }
    }
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
    bubblesort(my_vect);
    for (int i = 0; i < n; i++)
    {
        cout << my_vect[i] << endl;
    }
}