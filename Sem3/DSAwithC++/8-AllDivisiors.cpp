#include <iostream>
using namespace std;

void printDivisors(int number)
{
    int last_val;
    for (int i = 1; i * i <= number; i++)
    {
        if (number % i == 0)
        {
            cout << i << endl;
            last_val = i;
        }
    }
    for (int i = last_val; i >= 1; i--)
    {
        if (number % i == 0)
        {
            if (number / i != last_val)
            {
                cout << number / i << endl;
            }
            else
            {
                ;
            }
        }
    }
}

int main()
{
    cout << "Enter the number whose divisors you wish to know : " << endl;
    int number;
    cin >> number;
    printDivisors(number);
}

// Idea - If I traverse from 1 to square root of n, I will find one and only one divisor from each pair