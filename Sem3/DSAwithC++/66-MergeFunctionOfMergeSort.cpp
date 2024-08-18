#include <bits/stdc++.h>
using namespace std;

/*
Explanation : 
*/

void mergeThatPart(vector<int> &theVect, int low, int mid, int high){
    vector<int> left_part, right_part;
    for (int i = low; i <= mid; i++){
        left_part.push_back(theVect[i]);
    }
    for (int i = mid + 1; i <= high; i++){
        right_part.push_back(theVect[i]);
    }
    int i = 0, j = 0, k = 0;
    while (i < left_part.size() && j < right_part.size()){
        if (left_part[i] > right_part[j]){
            theVect[low + k] = (right_part[j]);
            j++;
            k++;
        }
        else{
            theVect[low + k] = (left_part[i]);
            i++;
            k++;
        }
    }
    while (i < left_part.size()){
        theVect[low + k] = (left_part[i]);
        i++;
        k++;
    }
    while (j < right_part.size()){
        theVect[low + k] = (right_part[j]);
        j++;
        k++;
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
    cout << "Enter the low, mid and high for the array : ";
    int low, mid, high;
    cin >> low >> mid >> high;
    mergeThatPart(my_vect, low, mid, high);
    for (int i = 0; i < n; i++)
    {
        cout << my_vect[i] << endl;
    }
}