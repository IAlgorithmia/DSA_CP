#include <bits/stdc++.h>
using namespace std;

/*
Info about quick sort : 

Explanation : Divide and Conquer, 
In merge sort the division is only half of division, merge process is complex
Here The partition process is complex - 
Worst case - O(n^2) still considered faster than merge sort, 
In place partition , Cache friendly, Tail Recursive (recall that these are the functions which call the recursive function as a last thing, these types of functions can be re written in iterative ways. In merge function, we were callng the merge funcrion at the end. Many compilers apply this optimization automatically in quicksort.)
Quick Sort can be implemented using the past 3 learnt algorithms, first will be the stable one. The other two will be non stable. 
CPP has sort and stable sort functions 
Stability chahiye to merge sort, else quick sort

Best Case occurs when the partition function keeps dividing the array into two equal halves (lomuto - when the selected pivot happenes to be at the exact middle of the entire array)
Worst Case occures when the partition function keeps dividing the array into two part having lengths of 1 and (high - low + 1) - 1 (lomuto - greatest or smallest element is picked). When the array is already sorted in increasing or decreasing order (for lomuto and hoarse)
Basically the picked pivot consistently is the smallest or the largest element in the array.
To prevent this, we pick any random index in the given range, swap it with first (hoarse) or last (lomuto) then do the same thing. 

Quick sort requires call stack for recursion call stack. If we define inplace as not copying the original array, then qiocksort is inplace, if we define as something that takes extra space, then quicksort is not inplace. since it requires space for recrsive calls

Auxillary Space - 
Worst case : O(n) (when divided into 1 and n - 1)
Best Case : O(logn) (when divided into two equal halves)

Tail Call elimination for quick sort algo! : 

void qsort(int arr[], int low, int high){
    begin : 
    if (low < high){
        int p = partition(arr, low, high);
        qsort(arr, low, p);
        low = p + 1;
        goto begin;
    }
}

This is the same as quick sort!
*/

int lomutoPartition(vector<int> &original, int low, int high){
    //Think in terms of subarray, the use of low and high will be more eased into flo rather than usage of 0 and vector.size() - 1
    int pivot = original[high]; //We automatically take the last element as the pivot
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

void quickSortAlgo(vector<int> &original, int low, int high){
    if (low < high){//To ensure > 1 elements
        int partition_index = lomutoPartition(original, low, high);
        //In lomuto partition, we are returned the index such that low to partition_index tak less than equal to, and partition_index se high tak greater than equal to, and partition_index pe vo khud. So we need to go from low to p - 1 and p + 1 to high sicne that is already at its correvct position. So we just gotta sort those two more parts then we done.
        quickSortAlgo(original, low, partition_index - 1);
        quickSortAlgo(original, partition_index + 1, high);
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
    quickSortAlgo(my_vect, 0, n - 1);
    cout << "After sorting the vector the answer is : ";
    for (auto u : my_vect){
        cout << u << " ";
    }
    cout << endl;
}