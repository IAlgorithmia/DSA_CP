#include <bits/stdc++.h>
using namespace std;

/*
Explanation : The Key idea is that for an array with minimum element 1, if we use fast and slow pointer method, we will always encounter a cycle, hence we write a similar code for the array with minimum element 0. Other conditions in video
For an array with minimum element 1 :

int slow = array[0], fast = array[0];
do
{
    slow = arr[slow];
    fast = arr[arr[fast]];
} while (slow != fast)
//Now slow and fast are at the index m + x
slow = array[0];
while (slow != fast)
{
    slow = array[slow];
    fast = array[fast];
}
//Now slow and fast are at index m
return slow;
*/

int returnRepeating(vector<int> the_vector)
{
    //starting each from the first index
    //since the min element is 0 we may get stuck ina n infinite loop, 
    // hence whenever we use array values we add 1 to them to 
    // make it so that the min element is actually 1
    int slow = the_vector[0] + 1, fast = the_vector[0] + 1;
    do
    {
        slow = the_vector[slow] + 1;
        fast = the_vector[the_vector[fast] + 1] + 1;
    } while (slow != fast);
    // Now slow and fast are at the index m + x
    slow = the_vector[0] + 1;
    while (slow != fast)
    {
        slow = the_vector[slow] + 1;
        fast = the_vector[fast] + 1;
    }
    // Now slow and fast are at index m
    // + 1 for preventing self loop
    return slow - 1;
}

int main(){
    cout << "Enter the array length" << endl;
    int n;
    cin >> n;
    cout << "Enter the elements" << endl;
    int elem;
    vector<int> my_vect;
    for (int i = 0; i < n; i++)
    {
        cin >> elem;
        my_vect.push_back(elem);
    }
    cout << returnRepeating(my_vect);
}