#include <bits/stdc++.h>
using namespace std;

/*
Explanation : Two indices given, return sum between them inclusive of both the indices
*/

int sumBw(vector<int> the_vector, int from, int to)
{
    vector<int> prefixSum;
    prefixSum.push_back(the_vector[0]);
    for (int i = 1; i < the_vector.size(); i++)
    {
        prefixSum.push_back(the_vector[i] + prefixSum[i - 1]);
    }
    if (from != 0)
    {
        return (prefixSum[to] - prefixSum[from - 1]);
    }
    else
    {
        return prefixSum[to];
    }
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
    int from, to;
    cout << "Enter the from and to indices " << endl;
    cin >> from >> to;
    cout << sumBw(my_vect, from, to);
}