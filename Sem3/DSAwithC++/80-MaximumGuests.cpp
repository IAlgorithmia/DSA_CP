#include <bits/stdc++.h>
using namespace std;

/*
Explanation : This problem is asking us to meet the guests not attend, we dont have to 
stary for their entire duration with them just meet them once
*/

vector<int> mergeTwoSortedArrays(vector<int> &array1 , vector<int> &array2){
    vector<int> mergedSorted;
    int i = 0, j = 0;
    while (i < array1.size() && j < array2.size()){
        if (array1[i] > array2[j]){
            mergedSorted.push_back(array2[j]);
            j++;
        }
        else{
            mergedSorted.push_back(array1[i]);
            i++;
        }
    }
    while (i < array1.size()){
        mergedSorted.push_back(array1[i]);
        i++;
    }
    while (j < array2.size()){
        mergedSorted.push_back(array2[j]);
        j++;
    }
    return mergedSorted;
}

int maxGuests(vector<int> &arrival, vector<int> &departure){
    sort(arrival.begin(), arrival.end());
    sort(departure.begin(), departure.end());
    unordered_set<int> arrival_set, departure_set;
    //either we can do this by two pointers 1 for each array or we can merge the two arrays and then iterate over the merged array
    //2nd method below
    for (int i = 0; i < arrival.size(); i++){
        arrival_set.insert(arrival[i]);
        departure_set.insert(departure[i]);
    }
    vector<int> merged_times = mergeTwoSortedArrays(arrival, departure);
    int max_guests = 0;
    int guests = 0;
    for (auto i : merged_times){
        if (arrival_set.find(i) != arrival_set.end()){
            guests++;
        }
        else{
            guests--;
        }
        max_guests = (max_guests < guests) ? guests : max_guests;
    }
    return max_guests;
}

int main(){
    vector<int> vect1, vect2;
    int n;
    cout << "Enter the size of vect1: ";
    cin >> n;
    cout << "Enter the elements of vect1: ";
    for (int i = 0; i < n; i++){
        int num;
        cin >> num;
        vect1.push_back(num);
    }
    cout << "Enter the size of vect2: ";
    cin >> n;
    cout << "Enter the elements of vect2: ";
    for (int i = 0; i < n; i++){
        int num;
        cin >> num;
        vect2.push_back(num);
    }
    cout << maxGuests(vect1, vect2) << endl;
}