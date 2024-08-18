#include <bits/stdc++.h>
using namespace std;

/*
Explanation : Given an array and an integer n, find whether the array can be divided into n subarrays of equal sum
*/
bool checkDivision(vector<int> the_vector, int k)
{
    int total_sum = 0;
    int n = the_vector.size();
    for (int i = 0; i < n; i++)
    {
        total_sum += the_vector[i];
    }
    if (total_sum % k != 0)
    {
        return false;
    }
    int sum_yet = 0;
    int sum_each = total_sum / k;
    int times = 0;
    for (int i = 0; i < n; i++)
    {
        sum_yet += the_vector[i];
        if (sum_yet == sum_each)
        {
            times++;
            sum_yet = 0;
        }
    }
    return (times == k);
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
    cout << "Enter the number of parts " << endl;
    int k;
    cin >> k;
    cout << checkDivision(my_vect, k);
}