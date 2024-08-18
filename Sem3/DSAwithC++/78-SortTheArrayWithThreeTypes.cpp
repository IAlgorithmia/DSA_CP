#include <bits/stdc++.h>
using namespace std;

/*
Explanation : 
1. Sort an array of 0s, 1s and 2s
2. Three way partitioning, There may be multiple pivots and they gotta come together, all the samller ones come on the left, while greater ones go on the right. 
3. Partition around a range

We will do the 1st from above
For solving second one we will just jo hume pivot select karne ko bola h vo kar lenge and instead < pivot and greater than pivot for other cases
3rd one is also similar to 2nd one, just instead of checking if it is equal to pivot, we will check if it is in the range or not

This is solved through Dutch Nation Flag Algorithm
*/

//We will ensure that 0 to low - 1 are all < pivots, low to mid - 1 are all pivots and mid to high are all ?s, and high + 1 to n - 1 are all > pivots

void sortThreeWay(vector<int> &my_vector){
    int low = 0, curr = 0, high = my_vector.size() - 1;
    int pivot = 1;
    while (curr <= high){
        if (my_vector[curr] < pivot){
            swap(my_vector[curr], my_vector[low]);
            low++;
            curr++;
        }
        else if (my_vector[curr] == pivot){
            curr++;
            //Ye cheez multiple pivots ke liye to kaam karegi hi, if theres a range we can check whether the number is in the range or not instead of checking if it is equal to 1
        }
        else{
            swap(my_vector[curr], my_vector[high]);
            high--;
            //we dont increase mid here since the just swapped elemnt is sus
        }
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
    sortThreeWay(my_vect);
    cout << "The final array is : " << endl;
    for (auto i : my_vect){
        cout << i << " ";
    }
    cout << endl;
}