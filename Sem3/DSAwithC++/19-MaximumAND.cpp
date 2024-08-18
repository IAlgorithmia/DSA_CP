#include <bits/stdc++.h>
using namespace std;


//This function takes a pattern and counts how many numbers in the array have all bits set as in the pattern.
int checkBit(int pattern, int arr[], int n)
{
    int count = 0;
    for (int i = 0; i < n; i++)
        if ((pattern & arr[i]) == pattern)
            count++;
    return count;
}

// Function for finding maximum and value pair

/*
The function initializes res to 0. This variable will store the maximum AND value found.
It iterates over the bits from the most significant bit (31st bit) to the least significant bit (0th bit).
For each bit position, it checks how many elements in the array can have this bit set along with the bits already set in res.
If at least two elements can have the current bit set (checked using checkBit), it sets this bit in res.
*/
int maxAND(int arr[], int n)
{
    int res = 0, count;

    // iterate over total of 32bits from msb to lsb
    for (int bit = 31; bit >= 0; bit--)
    {
        // find the count of element having set  msb
        count = checkBit(res | (1 << bit), arr, n);

        // if count >= 2 set particular bit in result
        if (count >= 2)
            res |= (1 << bit);
        //we are setting that bit as soon as we find >= two because 
        // even all the bits after it if set cant match this value, 
        //hence this represents the maximum, after this we llook to
        //increase this maximum value
    }

    return res;
}

int main(){
    cout << "Enter the size of the array : " << endl;
    int number;
    cin >> number;
    cout << "Enter the elements : " << endl;
    int element;
    int array[number];
    for (int i = 0; i < number; i++)
    {
        cin >> element;
        array[i] = element;
    }
    int max_val = maxAND(array, number);
    cout << "The Maximum AND value among the given elements of the array is : " << max_val << endl;
}