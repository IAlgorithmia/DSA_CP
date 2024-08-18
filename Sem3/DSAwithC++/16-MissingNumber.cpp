// The problem is that there is an array of size (n) with elements from 1 to (n + 1), except one. Find the missing element of the sequence, each number occurs only once
#include <bits/stdc++.h>
using namespace std;

void MissingNumber()
{
    cout << "You will have to input such an array yourself. Specify its size : " << endl;
    int size, element;
    int res = 0;
    cin >> size;
    cout << "Enter the elements : " << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> element;
        res = res ^ element;
    }
    for (int i = 1; i <= (size + 1); i++)
    {
        res = res ^ i;
    }
    cout << "The missing element is : " << res << endl;
}

int main(){
    MissingNumber();
    return 0;
}