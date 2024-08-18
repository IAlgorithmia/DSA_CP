#include <bits/stdc++.h>
using namespace std;

/*
Explanation : This partition doesnt guarantee that the pivot will be at its correct position, but Lomuto does. In performance, hoarse is much better than all LOMUTO. Also this assumes the first element as pivot.
*/

//Array low to right (including right) are less than equal to pivot, right + 1 to high are greater than equal to pivot
//Both of these partitions are unstable, but the naive partition we talked about in the prev code comment is stable, although more space required. Quick sort by itself is an unstable sorting algorithm.
int hoarePartition(vector<int> &original, int low, int high){
    int left = low - 1;
    int right = high + 1;
    int pivot = original[low];
    while (true){
        do{
            left++;
        } while (original[left] < pivot);
        do{
            right--;
        } while (original[right] > pivot);
        if (left >= right) {
        return right;
        }
        swap(original[left], original[right]);
    }
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
    int final_index = hoarePartition(my_vect, 0, n - 1, index);
    for (auto i : my_vect){
        cout << i << " ";
    }
    cout << endl;
    cout << "The point of partition is : " << final_index << endl;
}
