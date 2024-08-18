#include <bits/stdc++.h>
using namespace std;

/*
Explanation : If there is an independent array, there will always be a peak element in it
Kahin se bhi start karo, greater element ki taraf peak hoga if you're not already standing at a peak
*/

/*
Recursive
if (low > high)
{
    return -1;
}
else
{
    if (mid > mid - 1 vala and mid > mid + 1 vala given both are available, diffcases)
    {

    }
    else
    {
        int left = (left part ke sah same)
        int right = (right part same)
        jonsa -1 na hua return that, else koi bhi ek return kardo
    }
}
*/

int findPeak(vector<int> the_vector)
{
    int low = 0;
    int high = the_vector.size() - 1;
    int mid;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (((mid == 0) || (the_vector[mid - 1] <= the_vector[mid])) && ((mid == the_vector.size() - 1) || (the_vector[mid + 1] <= the_vector[mid])))
        {
            return mid;
        }
        else if ((mid > 0) && (the_vector[mid - 1] >= the_vector[mid]))
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return -1; //will never reach here
}

int main(){
    cout << "Hey there!" << endl;
}