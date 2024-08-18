#include <bits/stdc++.h>
using namespace std;

//How to do n towers with m disks

void toh(int n, char source, char auxillary, char destination)
{
    if (n == 1)
    {
        cout << "Move disc " << n << " from " << source << " to " << destination << endl;
    }
    else
    {
        toh(n - 1, source, destination, auxillary);
        cout << "Move disc " << n << " from " << source << " to " << destination << endl;
        toh(n - 1, auxillary, source, destination);
    }
}

int main(){
    cout << "Enter the number of disks you have : " << endl;
    int n;
    cin >> n;
    toh (n, 'A', 'B', 'C');
}