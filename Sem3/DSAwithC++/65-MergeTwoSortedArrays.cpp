#include <bits/stdc++.h>
using namespace std;

/*
Explanation : Divide and Conquer, Stable, nlogn, O(1) auxillary space, Well suited for external sorting, For linkedLists, in general, quicksort outperforms it
*/

vector<int> mergeTwoSortedArrays(vector<int> &array1 , vector<int> &array2){
    vector<int> mergedSorted;
    int i = 0, j = 0;
    while (i < array1.size() && j < array2.size()){
        if (array1[i] > array2[j]){
            mergedSorted.push_back(array2[j]);
            j++;
        }
        else{
            mergedSorted.push_back(array1[i]);
            i++;
        }
    }
    while (i < array1.size()){
        mergedSorted.push_back(array1[i]);
        i++;
    }
    while (j < array2.size()){
        mergedSorted.push_back(array2[j]);
        j++;
    }
    return mergedSorted;
}

int main()
{
    cout << "Enter the array 1 length" << endl;
    int n;
    cin >> n;
    cout << "Enter the elements" << endl;
    int elem;
    vector<int> my_vect_1;
    for (int i = 0; i < n; i++)
    {
        cin >> elem;
        my_vect_1.push_back(elem);
    }
    cout << "Enter the array 2 length" << endl;
    cin >> n;
    cout << "Enter the elements" << endl;
    vector<int> my_vect_2;
    for (int i = 0; i < n; i++)
    {
        cin >> elem;
        my_vect_2.push_back(elem);
    }
    vector<int> result;
    cout << "Resulting vector is  : " << endl;
    result = mergeTwoSortedArrays(my_vect_1, my_vect_2);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << endl;
    }
}