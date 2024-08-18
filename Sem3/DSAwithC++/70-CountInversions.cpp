#include <bits/stdc++.h>
using namespace std;

/*
Explanation : Time complexity is same as merge sort, aux space is n
*/

int mergeFunctionCustom(vector<int> &theVect, int low, int mid, int high){
    vector<int> left_part, right_part;
    int count = 0;
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
            count += (left_part.size() - i);
            //This line is the magic here, agar right mein koi aisa mil raha hai jo abhi vale element in the left se chota hai, then obviously it will be lesser than all the elements yet to come in the left part, to abhi se add kar dia since right vala element to chala jayega ab. GENIUS.
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
    return count;
}

int countInversions(vector<int> &the_vect, int low, int high){
    int res = 0;
    if (low < high){
        int mid = (low + high) / 2;
        res += countInversions(the_vect, low, mid);
        res += countInversions(the_vect, mid + 1, high);
        res += mergeFunctionCustom(the_vect, low, mid, high);
    }
    return res;
}

int main(){
    cout << "Enter the array length : " << endl;
    int n;
    cin >> n;
    cout << "Enter the elements : " << endl;
    int elem;
    vector<int> my_vect;
    for (int i = 0; i < n; i++)
    {
        cin >> elem;
        my_vect.push_back(elem);
    }
    cout << countInversions(my_vect, 0, n - 1) << endl;
}