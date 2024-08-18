#include <bits/stdc++.h>
using namespace std;

/*
Explanation : Linear time algo for cases when inputs are in small range, for n elements in the range 0 to k - 1 (not useful when k is not linear in terms of n, n square etc not good, only linear), takes O(n + k) time, it is not a comparision based algo, it never compares two elements,
It is a stable algo, used as a subroutine in radix sort
*/

//Lets say we are given elements between a min value and a max value, their difference being k, we can always do shifting of origin type thing where 0 lands on min and k - 1 lands on max

void CountingSort(vector<int> &specialVector, int k){
    //I know elements are from 0 to k - 1
    int n = specialVector.size();
    vector<int> frequency(k, 0);
    for (auto i : specialVector){
        frequency[i]++;
    }
    for (int i = 1; i < k; i++){
        frequency[i] = frequency[i - 1] + frequency[i];
    }
    //The above thing will help us in knowing the index of where to put that element, that basically becomes ke ith index holds the number of elements that will be filled in the new array after all the occurrences of element i have been added
    vector<int> newVector(n, 0);
    for (int i = n - 1; i >= 0; i--){
        newVector[frequency[specialVector[i]] - 1] = specialVector[i];
        frequency[specialVector[i]]--;
    }
    for (int i = 0; i < n; i++){
        specialVector[i] = newVector[i];
    }
}

int main(){
    int n, k;
    cout << "Enter the length of the array, as well as the value of k : " << endl;
    cin >> n >> k;
    cout << "Enter the elements : " << endl;
    int elem;
    vector<int> specialVector;
    for (int i = 0; i < n; i++){
        cin >> elem;
        specialVector.push_back(elem);
    }
    CountingSort(specialVector, k);
    cout << "The final array is : " << endl;
    for (auto i : specialVector){
        cout << i << " ";
    }
    cout << endl;
}