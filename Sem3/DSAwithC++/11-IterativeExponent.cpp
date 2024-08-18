#include <iostream>
using namespace std;

//every number can be represented as a sum of powers of 2, and we can 
//traverse all the bits of a number in logn time

//jaise 3^10 hai, 10 = 1010 in bits, start from right,
// 3^1, 3^2, 3^4, 3^8 se multiply correspondingly 
//you get 3^10, this is the idea

int expo(int basenum, int exponum)
{
    int result = 1;
    while (exponum > 0)
    {
        if (exponum % 2 != 0) //can also write exponum $ 1, this means remainder is 1 ie bit is 1
        {
            result = result * basenum;
        }
        exponum = exponum / 2; //can also write exponum >> 1
        basenum = basenum * basenum;
    }
    return result;
}

//agar remainder 1 aa raha hai exponent ka when divided by 2, multiplication krdo, Keep dividing the exponent by 2, keep multiplying baseunm with itself

int main()
{
    cout << "Enter the base and the exponent : " << endl;
    int base, exponent;
    cin >> base >> exponent;
    int answer = expo(base, exponent);
    cout << answer;
}