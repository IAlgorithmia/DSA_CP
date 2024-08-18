#include <bits/stdc++.h>
using namespace std;

/*
Explanation : An algorithm is said to be In place if it does not use any auxillary space O(1) aux space comp. Best used for short arrays - Python uses Timsort and Introsort
*/

void insertionSort(vector<int> &the_vector)
{
    int n = the_vector.size();
    for (int i = 1; i < n; i++){
        int j = i - 1;
        int key = the_vector[i];
        while (j >= 0 && the_vector[j] > key){
            the_vector[j + 1] = the_vector[j];
            j--;
        }
        the_vector[j + 1] = key;
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
    insertionSort(my_vect);
    for (int i = 0; i < n; i++)
    {
        cout << my_vect[i] << endl;
    }
}