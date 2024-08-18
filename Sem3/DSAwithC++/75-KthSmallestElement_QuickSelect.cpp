#include <bits/stdc++.h>
using namespace std;

/*
Explanation : This is called as Quick select algorithm. This runs in n square for worst time, on average and best case it is linear. Is se better bhi hai ek but that is veryu complex, kuch median karke hai hence mostly this algo is used only quckselect.
*/

int partitionLomuto(vector<int> &original, int low, int high){
    int left = low - 1;
    int pivot = original[high];
    for (int right = low; right < high; right++){
        if (original[right] < pivot){
            left++;
            swap(original[left], original[right]);
        }
    }
    left++;
    swap(original[left], original[high]);
    return (left);
}


int kthSmallest(vector<int> &original, int k){
    int low = 0;
    int high = original.size() - 1;
    int part_index;
    while (low <= high){ //When we are finding a particular element in the array, tab low <= high use kar lia karo because we need to pin point the element and hence that includes low and high being equal
        part_index = partitionLomuto(original, low, high);
        if (part_index == (k - 1)){
            return original[part_index];
        }
        else if (part_index > (k - 1)){
            high = part_index - 1;
        }
        else{
            low = part_index + 1;
        }
    }
    return -1;
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
    cout << "Enter the k for 'Kth Smallest Element' : " << endl;
    int k;
    cin >> k;
    cout << "The required number is : " << kthSmallest(my_vect, k) << endl;
}