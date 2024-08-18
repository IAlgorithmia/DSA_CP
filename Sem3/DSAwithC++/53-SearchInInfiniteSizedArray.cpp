#include <bits/stdc++.h>
using namespace std;

/*
Explanation : Since we cant have an infiinite sized array, we will just mention the code here
*/

int binarysearch(vector<int> arr, int num, int low, int high)
{
    int mid;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (num == arr[mid])
        {
            return mid;
        }
        else if (num > arr[mid])
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}

int findInInfiniteArray(vector<int> the_vector, int num)
{
    if (the_vector[0] == num)
    {
        return 0;
    }
    else
    {
        int i = 1;
        while (the_vector[i] < num)
        {
            i = i * 2;
        }
        if (the_vector[i] == num)
        {
            return i;
        }
        else
        {
            return binarysearch(the_vector, num, (1 + (i / 2)), (i - 1));
        }
    }
}

int main(){
    cout << "Hey there!" << endl;
}