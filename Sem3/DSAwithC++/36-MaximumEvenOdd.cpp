#include <bits/stdc++.h>
using namespace std;

/*
Explanation : 
Jab Tak consecutive opp type ke hain, sum karte jaao, else 1 se restart karo, use se pehle max check karlo then return it
*/

int maxEvenOdd(vector<int> the_vector)
{
    int length = 1;
    int max_length = 1;
    for (int i = 0; i < (the_vector.size() - 1); i++)
    {
        if ((the_vector[i] % 2) ^ (the_vector[i + 1] % 2))
        {
            length++;
        }
        else
        {
            max_length = max(length, max_length);
            length = 1;
        }
    }
    max_length = max(length, max_length);
    return max_length;
}

int main()
{
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
    cout << maxEvenOdd(my_vect);
}