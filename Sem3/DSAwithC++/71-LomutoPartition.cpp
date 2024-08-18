#include <bits/stdc++.h>
using namespace std;

/*
Explanation : 
*/

//Method - 1
//Ek solution to ye hoga ke 2 iterations karo, and ek new vector bana lo. First mein <= elements add kardo, next mein > elements add kardo. Hence the answer

//Method - 2 
//Lomuto Partition - Here we just ensure that from - to index i, we have elements that are smaller than the pivot, from i + 1 to j - 1 the elements are equal or greater. But in this the pivot must be the last element. So if some other pivot is given then we just update the array and swap the last element with the index of the pivot 
//Observe that this is just the partition and doesnt say that the partitioned parts will be sorted

int lomutoPartition(vector<int> &original, int low, int high, int pivot_index){
    swap(original[pivot_index], original[high]);
    int pivot = original[high];
    int left = low - 1;
    for (int right = low; right <= high - 1; right++){
        if (original[right] < pivot){
            left++;
            swap(original[left], original[right]);
        }
    }
    left++;
    swap(original[left], original[high]);
    return left;
    //left pe ab pivot hai, so from low to left we got elements less than equal to pivot, from left + 1 to high, elements are greater than pivot.
}

int main(){
    cout << "Enter the array length : " << endl;
    int n;
    cin >> n;
    cout << "Enter the elements : " << endl;
    int elem;
    vector<int> my_vect;
    for (int i = 0; i < n; i++){
        cin >> elem;
        my_vect.push_back(elem);
    }
    int index;
    cout << "Enter the index to partition wrt : " << endl;
    cin >> index;
    cout << "The new vector is : " << endl;
    int final_index = lomutoPartition(my_vect, 0, n - 1, index);
    for (auto i : my_vect){
        cout << i << " ";
    }
    cout << endl;
    cout << "The point of partition is : " << final_index << endl;
}