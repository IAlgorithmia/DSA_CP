#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<long long> nums = {1,2,3,4,5,6};
    int k = 1;
    unordered_set<long long> my_set; 
    int start = 0;
    int end = 1;
    vector<int> cumu_sum;
    cumu_sum.push_back(nums[0]);
    sort(nums.begin(), nums.end());
    for (int i = 1; i < nums.size(); i++)
    {
        cumu_sum.push_back(nums[i] + cumu_sum[i - 1]);
    }
    vector<int> temp;
    while (start < end)
    {
        int sum_of_array;
        if (start > 0)
        {
            sum_of_array = cumu_sum[end] - cumu_sum[start - 1];
        }
        else
        {
            sum_of_array = cumu_sum[end];
        }
        if (sum_of_array == k)
        {
            my_set.insert(sum_of_array);
        }
        else if (sum_of_array < k)
        {
            end++;
        }
        else
        {
            start++;
        }
        cout << start;
    }
    int max_int = INT_MIN;
    for (auto i : my_set)
    {
        if (i > max_int)
        {
            max_int = i;
        }
    }
    return max_int;
    }