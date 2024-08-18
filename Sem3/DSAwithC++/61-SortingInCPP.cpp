#include <bits/stdc++.h>
using namespace std;

/*
Explanation : sort function of the STL, uses data types that allow random access such as array, deque, and vector

For arrays =
sort(arr, arr + n) - Ascending
sort(arr, arr + n, greater<int>) - Descending

For vectors = 
sort(v.begin(), v.end()) -Ascending
sort(v.begin(), v.end(), greater<int>) -Descending

Custom Sorting = 
struct Point{
    int x, y;
}
bool mySorter(Point a, Point b)
{
    return a.x < b.x;
    < for ascending
    > for descending    
}

int main()
{
    Point arr[] = {{1, 2}, {5, 10}, {20, 9}};
    sort(arr, arr + n, mySorter); - Returns ascending wrt x ie first element in the point data
}

Stability of Sorting Algo : 
If two elements have the same comparable value, then they should apper int he order they appeared in the original array
Bubble, Insertion, Merge Sorts are stable -BIM BIM BIM BIM BIM BIM
Selection, Quick and Heapsort are unstable
*/

int main(){
    cout << "Hey there!" << endl;
}