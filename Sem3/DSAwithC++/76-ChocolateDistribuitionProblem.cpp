#include <bits/stdc++.h>
using namespace std;

/*
Explanation : Each child must get at least 1 chocolate, and we want to minimize the difference between the highest and smallest number o chocolates
We sort the array and we consider each element as the minimum of the suppossed set, and find the difference by going to m - 1 indices forward, and us mein se subtract. First n - m + 1 have to be checked.
*/

int chocoDist(vector<int> &original, int children){
    sort(original.begin(), original.end()); //Bas iske karand nlogn complexity hai
    int res = INT_MAX;
    int n = original.size();
    for (int i = 0; i < n - children + 1; i++){
        res = min(res, original[i + children - 1] - original[i]);
    }
    return res;
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
    cout << "Enter the number of children : " << endl;
    int children;
    cin >> children;
    cout << "The minimum difference is : " << chocoDist(my_vect, children) << endl;
}