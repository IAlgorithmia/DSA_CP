#include <bits/stdc++.h>
using namespace std;

/*
Explanation : We are given L and R arrays, specifying starting end ending of the ranges
We gotta find maximum occuring element, given that the max 0 < L[i], R[i] < 1000
We mark the starting indices with +1, ending places with -1, then prefix sum, then index with maximum is the answer
*/

int maxOccuring(vector<int> starting, vector<int> ending)
{
    vector<int> indices(1000, 0);
    int n = starting.size();
    for (int i = 0; i < n; i++)
    {
        indices[starting[i]]++;
        indices[ending[i] + 1]--;
    }
    int max_index = INT_MIN;
    for (int i = 1; i < indices.size(); i++)
    {
        indices[i] = indices[i] + indices[i - 1];
        max_index = max(max_index, indices[i]);
    }
    cout << endl;
    return max_index;
}

int main(){
    cout << "Enter the array length" << endl;
    int n;
    cin >> n;
    cout << "Enter the elements for starting array" << endl;
    int elem;
    vector<int> beginning;
    for (int i = 0; i < n; i++)
    {
        cin >> elem;
        beginning.push_back(elem);
    }
    vector<int> ending;
    cout << "Enter the elements for ending array" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> elem;
        ending.push_back(elem);
    }
    cout << maxOccuring(beginning, ending);
}