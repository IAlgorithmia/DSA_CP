#include <bits/stdc++.h>
using namespace std;

/*
Explanation : 
*/

void printIntersections(vector<int> vect_1, vector<int> vect_2){
    int i = 0, j = 0, last_val = INT_MIN;
    while (i < vect_1.size() && j < vect_2.size()){
        if (vect_1[i] < vect_2[j]){
            i++;
        }
        else if (vect_1[i] > vect_2[j]){
            j++;
        }
        else{
            if (vect_1[i] != last_val){
            cout << vect_1[i] << endl;
            last_val = vect_1[i];
            }
            i++;
            j++;
        }
    }
}

int main(){
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
    printIntersections(my_vect_1, my_vect_2);
}