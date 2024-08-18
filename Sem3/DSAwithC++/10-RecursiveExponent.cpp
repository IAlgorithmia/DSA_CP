#include <iostream>
using namespace std;

int expo(int basenum, int exponum)
{
    if (exponum == 0)
    {
        return 1;
    }
    if (exponum == 1)
    {
        return basenum;
    }
    int temp = expo(basenum, exponum / 2);
    temp = temp * temp;
    if (exponum % 2 == 0)
    {
        return temp;
    }
    else
    {
        return temp * basenum;
    }
}

int main()
{
    cout << "Enter the base and the exponent : " << endl;
    int base, exponent;
    cin >> base >> exponent;
    int answer = expo(base, exponent);
    cout << answer;
}