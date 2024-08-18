#include <bits/stdc++.h>
using namespace std;

/*
Explanation : It is not a comparision based algo, it sorts in linear time even larger values of k. It is stable. Better than counting sort
First in linear time we find the max digits, then make each's same, we're gonna require max digits number of passes
Time complexity is O(d*(n + b)) where b is the base, 10 as b increases d decreases. 
Aux Space = O(n + b)
*/

//Modified counting sort
//The only modification is that instead of directly using the element
//as the index we are doing (elem / divider) % 10 to get our desired digit's index

void CountingSort(vector<int> &specialVector, int k, int place){
    //I know elements are from 0 to k - 1
    int divider = pow(10, place);
    int n = specialVector.size();
    vector<int> frequency(k, 0);
    for (auto i : specialVector){
        frequency[((i / divider) % 10)]++;
    }
    for (int i = 1; i < k; i++){
        frequency[i] = frequency[i - 1] + frequency[i];
    }
    //The above thing will help us in knowing the index of where to put that element, that basically becomes ke ith index holds the number of elements that will be filled in the new array after all the occurrences of element i have been added
    vector<int> newVector(n, 0);
    for (int i = n - 1; i >= 0; i--){
        newVector[frequency[(specialVector[i] / divider) % 10] - 1] = specialVector[i];
        frequency[(specialVector[i] / divider) % 10]--;
    }
    for (int i = 0; i < n; i++){
        specialVector[i] = newVector[i];
    }
}

void RadixSort(vector<int> &specialVector){
    int n = specialVector.size();
    int maxDigits = INT_MIN;
    for (auto i : specialVector){
        maxDigits = (log10(i) > maxDigits) ? log10(i) : maxDigits;
    }
    maxDigits = floor(maxDigits) + 1; //actually meaningful variable now
    for (int i = 0; i < maxDigits; i++){
        CountingSort(specialVector, 10, i);
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
    RadixSort(specialVector);
    cout << "The final array is : " << endl;
    for (auto i : specialVector){
        cout << i << " ";
    }
    cout << endl;
}