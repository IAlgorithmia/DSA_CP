#include <bits/stdc++.h>
using namespace std;

int josephus(int n, int k)
{
    if (n == 1)
    {
        return 0;
    }
    else
    {
        return ((josephus(n - 1, k) + k) % n);
    }
}

int my_jos(int n, int k)
{
    if (n == 1)
    {
        return 1;
    }
    else
    {
        return (josephus(n, k) + 1);
    }
}

int main(){
    cout << "Enter n and k : ";
    int n, k;
    cin >> n >> k;
    cout << josephus(n, k) << endl;
    cout << my_jos(n, k) << endl; //this is for josephus if the indices start from 1 instead of 0
}