#include <bits/stdc++.h>
using namespace std;

/*
Explanation : I thought that array ko double karke original vala kaam kar jayega, but it doesn't work like that
First of all the name of this algorithm is Kadane's Algorithm (36th one) 
Next considering only the max circular subarray sum, we can find that by finding out the 
min sum of the subarray that is not circular then subtracting that from the total
In the end, normal and circular mein se jo max hoga use dekh lenge
If the normal sum comes out to be negative, this ieams all the elements are negative, 
minimum subaraay sum karunga to saare elements hi aa jayenge sum mein, hence
total - total = 0 milega for circular subarray sum, which is senseless
For thta case, we just return the normal subarray max sum
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

int maxCircularSum(vector<int> the_vector)
{
    //This is modified Kandane
    int sum = INT_MAX;
    int minSum = the_vector[0];
    int total_sum = the_vector[0];
    int normal_sum = maxSumSubarray(the_vector);
    for (int i = 1; i < the_vector.size(); i++)
    {
        total_sum += the_vector[i];
        the_vector[i] = min(the_vector[i], the_vector[i] + the_vector[i - 1]);
        minSum = min(minSum, the_vector[i]);
    }
    if (normal_sum < 0)
    {
        return normal_sum;
    }
    return max(normal_sum, (total_sum - minSum));
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
    cout << maxCircularSum(my_vect);
}