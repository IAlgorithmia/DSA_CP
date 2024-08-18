#include <iostream>
using namespace std;

int primeFactors(int number)
{

    while (number % 2 == 0)
    {
        cout << 2 << endl;
        number = number / 2;
    }
    while (number % 3 == 0)
    {
        cout << 3 << endl;
        number = number / 3;
    }
    for (int i = 5; i * i <= number; i = i + 6)
    {
        while (number % i == 0)
        {
            cout << i << endl;
            number = number / i;
        }
        while (number % (i + 2) == 0)
        {
            cout << (i + 2) << endl;
            number = number / (i + 2);
        }
    }
    if (number > 3)
    {
        cout << number << endl;
    }
    // This last part is done because if number obtained after 
    //THIS STEP is prime, no prime factors will be found for it
    // hence we need to print it as it is too. 
    //This is not n > 1, because 2 and 3
    //  prime factors have already been removed frmo the number. 
    // Any remaining number can have a prime number greater than 3 in it.
}

int main()
{
    cout << "Enter the number whose prime factors you want to find : " << endl;
    int number;
    cin >> number;
    primeFactors(number);
}