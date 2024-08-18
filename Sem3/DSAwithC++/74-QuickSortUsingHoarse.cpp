 #include <bits/stdc++.h>
 using namespace std;
 
 /*
 Explanation : The difference between the two quickSorts lies in the significance of values returned by the partition functions.
 */

int hoarePartition(vector<int> &original, int low, int high){
    int left = low - 1;
    int right = high + 1;
    int pivot = original[low]; //We automatically assume the first element to be the pivot
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

void quickSortAlgo(vector<int> &original, int low, int high){
    if (low < high){
        int p = hoarePartition(original, low, high);
        //This returned value will be such that low se p tak less than equal to, p + 1 se end tak greater than equal to. Hence we just gotta sort these parts.
        quickSortAlgo(original, low, p);
        quickSortAlgo(original, p + 1, high);
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