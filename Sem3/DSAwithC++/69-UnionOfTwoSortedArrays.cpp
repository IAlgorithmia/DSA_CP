#include <bits/stdc++.h>
using namespace std;

/*
Explanation : In my opinion, instead of doing this complex thing in lines 
if (i > 0 && vect_1[i] == vect_1[i - 1]){
            i++;
            continue;
        }
and below also in the individual vector sections
we can just check whether the current contender is same as the last pushed element in the 
union vector, if yes then we dont push else we do, increase i, or j in both the cases
this is more general in my opinion
*/

void printSortedUnion(vector<int> vect_1, vector<int> vect_2){
    int i = 0, j = 0, k = 0;
    vector<int> sortedUnion;
    while (i < vect_1.size() && j < vect_2.size()){
        if (i > 0 && vect_1[i] == vect_1[i - 1]){
            i++;
            continue;
        }
        if (j > 0 && vect_2[j] == vect_2[j - 1]){
            j++;
            continue;
        }
        if (vect_1[i] < vect_2[j]){
            sortedUnion.push_back(vect_1[i]);
            i++;
            k++;
        }
        else if (vect_1[i] > vect_2[j]){
            sortedUnion.push_back(vect_2[j]);
            j++;
            k++;
        }
        else{
            sortedUnion.push_back(vect_2[j]);
            i++;
            j++;
            k++;
        }
    }
    while (i < vect_1.size()){
        if (vect_1[i] != vect_1[i - 1]){
            sortedUnion.push_back(vect_1[i]);
            k++;
        }
        i++;
    }
    while (j < vect_2.size()){
        if (vect_2[j] != vect_2[j - 1]){
            sortedUnion.push_back(vect_2[j]);
            k++;
        }
        j++;
    }
    for (auto i : sortedUnion){
        cout << i << endl;
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
    printSortedUnion(my_vect_1, my_vect_2);
}