#include <bits/stdc++.h>
using namespace std;

/*
Explanation : 
*/

void printNBonacci(int n, int m)
{
    vector<int> warehouse(n - 1, 0);
    warehouse.push_back(1);
    if (m <= n)
    {
        for (int i = 0; i < m; i++)
        {
            cout << warehouse[i] << " ";
        }
    }
    else
    {
        int sum = 0;
        for (int k : warehouse)
        {
            sum += k;
            cout << k << " ";
        }
        for (int q = n; q < m; q++)
        {
            warehouse.push_back(sum);
            cout << sum << " ";
            sum += warehouse[q] - warehouse[q - n];
        }
    }
}

int main(){
    int n, m;
    cout << "Enter the values of n and m" << endl;
    cin >> n >> m;
    printNBonacci(n, m);
}