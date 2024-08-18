#include <bits/stdc++.h>
using namespace std;

void TwoOddAppearing()
{
    cout << "You will have to input such an array yourself. Specify its size : " << endl;
    int size, element;
    int res = 0; // xors can be initialized with zero since after the first xor operation
    //all the places having 1 will be 1 too in to final result, since 0 ^ 1 = 1
    cin >> size;
    int array[size];
    cout << "Enter the elements : " << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> element;
        res = res ^ element;
        array[i] = element;
    }
    int res1 = 0, res2 = 0;
    res = (res) & ~(res - 1); //this is retrieval of right most set bit
    for (int i = 0; i < size; i++)
    {
        if (array[i] & res)
        {
            res1 = res1 ^ array[i];
        }
        else
        {
            res2 = res2 ^ array[i];
        }
    }
    cout << "The 1st odd appearing element is : " << res1 << endl;
    cout << "The 2nd odd appearing element is : " << res2 << endl;
}

int main()
{
    TwoOddAppearing();
    return 0;
}