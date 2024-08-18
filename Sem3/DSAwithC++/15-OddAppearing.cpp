//The problem is that there is an array, each number occurs even number of times, except one. Find that
#include <bits/stdc++.h>
using namespace std;

void oddAppearing()
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
    cout << "The element that occurs odd number of times is : " << res << endl;
}

int main(){
    oddAppearing();
    return 0;
}