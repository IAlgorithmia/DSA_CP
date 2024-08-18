#include <bits/stdc++.h>
using namespace std;

/*
Explanation : Works best for uniform distribution of number in a given range. We divide the range in a number of buckets, number of buckets is determined by space vs time trade off. Then we sort individual buckets, then we join buckets. We can use any standard. We first linearly divide the elements into different buckets, then linearly (hopefully, when number of elements is less, we use insertion sort) sort them, then linearly join them. 
If k is almost equal to n, we get overall time complexity O(n). In worst case O(n square) or O(n log n)
COCKTAIL SORT traverses from both the sides, it is an optimized version of bubble sort, they only swap adjacent elements.
When number of elements is less, we can either use selection sort or insertion sort.
When extra memory is less, we use SHELL SORT is 
We also have TinSort and Intro Sort
HeapSort cant be used for linked List, best for that is merge sort
Stable Sort is also there
*/

void BucketSort(vector<int> &specialVector, int numberOfBuckets){
    int maxVal = INT_MIN;
    int n = specialVector.size();
    for (auto i : specialVector){
        maxVal = (i > maxVal) ? i : maxVal;
    }
    maxVal++; //we do this because else max ke liye number of buckets index hi will come but since were gonna have 1 lesser index, we do this
    vector<vector<int>> buckets(numberOfBuckets);
    for (int i = 0; i < n; i++){
        buckets[specialVector[i] * numberOfBuckets / maxVal].push_back(specialVector[i]);
    }
    for (int i = 0; i < numberOfBuckets; i++){
        sort(buckets[i].begin(), buckets[i].end());
    }
    int index = 0;
    for (auto i : buckets){
        for (auto j : i){
            specialVector[index++] = j;
            cout << j << " ";
        }
        cout << endl;
    }
}

int main(){
    int n, k;
    cout << "Enter the length of the array : " << endl;
    cin >> n;
    cout << "Enter the elements : " << endl;
    int elem;
    vector<int> specialVector;
    for (int i = 0; i < n; i++){
        cin >> elem;
        specialVector.push_back(elem);
    }
    BucketSort(specialVector, 4);
    cout << "The final array is : " << endl;
    for (auto i : specialVector){
        cout << i << " ";
    }
    cout << endl;
}