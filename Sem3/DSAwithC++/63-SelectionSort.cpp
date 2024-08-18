#include <bits/stdc++.h>
using namespace std;

/*
Explanation : This sorting method does less memory writes compared to other sorting algos, BUT cycle sort is the optimal algo for least memory writes. It is a basic idea for heapsort, and its it=s not stable, In place sorting method
*/

void selectionsort(vector<int>& the_vector)
{
    int n = the_vector.size();
    int min_ind;
    for (int i = 0; i < n - 1; i++)
    {
        min_ind = i;
        for (int j = i + 1; j < n; j++)
        {
            if (the_vector[j] < the_vector[min_ind])
            {
                min_ind = j;
            }
        }
        swap(the_vector[min_ind], the_vector[i]);
    }
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
    selectionsort(my_vect);
    for (int i = 0; i < n; i++)
    {
        cout << my_vect[i] << endl;
    }
}