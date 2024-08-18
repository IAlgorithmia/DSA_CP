#include <bits/stdc++.h>
using namespace std;

void lookup_table_counter(int number)
{
    //Initialization
    int table[256];
    table[0] = 0;
    for (int i = 1; i < 256; i++)
    {
        table[i] = (i & 1) + table[i / 2];
        //table[i] represents the number of set bits in i now
        //first expression is for the last bit of i and the second expression is for the number of sets bits in i >> 1, hence the total number of set bits in i
    }
    // 0xff = 1111 1111 hexadecimal representation of 8 set bits 
    //we divide our number into 4 parts of 8 bits each and then find the number of set bits in each part and add them to get the total number of set bits in the number
    int result = 0;
    result = result + table[number & 0xff];

    number >>= 8;

    result = result + table[number & 0xff];

    number >>= 8;

    result = result + table[number & 0xff];

    number >>= 8;

    result = result + table[number & 0xff];

    cout << "(LookUpTable) The number of set bits in the given number is : " << result << endl;
}

void brian_kernighan_algorithm_counter(int number)
{
    int result = 0;
    while (number > 0)
    {
        number = (number & (number - 1)); //we are just removing the last set bit here and counting the number of times we are doing this
        result++;
    }
    cout << "(BKA) The number of set bits in the given number is : " << result << endl;
}

int main()
{
    cout << "Enter the number in which you want to find out the number of set bits : ";
    int number;
    cin >> number;
    brian_kernighan_algorithm_counter(number);
    lookup_table_counter(number);
}