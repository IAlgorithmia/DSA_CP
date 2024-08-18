#include <bits/stdc++.h>
using namespace std;

/*
Explanation : 
KANDANE'S ALGORITHM
For each element, we basically need the maximum sum among all the possible sums of 
subarrays that end at that element, for every element we find that, then the maximum among
those is the answer
Ek new array of same size lelo, first element to copy hi karo directly from the original array
Vo first element is the maximum sum of all possible sub arrays that can be taken which end at that element
i - 1 th se i pe jaate hue we have two options, ith ko include karo us subarray mein or not
that depends on whether ith akela is greater than the eventual sum that we will get
after adding ith element to the previous subarray hence continuing it, 
thus the max vala part. Ta-da!
Now instead of creating a new array purane mein hi update kardo values as you go forward
*/

int maxSumSubarray(vector<int> the_vector)
{
    int maxSum = the_vector[0];
    for (int i = 1; i < the_vector.size(); i++)
    {
        the_vector[i] = max(the_vector[i], the_vector[i] + the_vector[i - 1]);
        maxSum = max(maxSum, the_vector[i]);
    }
    return maxSum;

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
    cout << maxSumSubarray(my_vect);
}