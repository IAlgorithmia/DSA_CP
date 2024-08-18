#include <bits/stdc++.h>
using namespace std;

void isPow2(int number)
{
    if ((number != 0) && (((number) & (number - 1)) == 0))
    {
        cout << "Yes the number is a power of 2";
    }
    else
    {
        cout << "No, the number is not a power of 2";
    }
}

int main(){
    cout << "Enter the number which you want to check : ";
    int number;
    cin >> number;
    isPow2(number);
}