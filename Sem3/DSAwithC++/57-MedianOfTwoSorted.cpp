#include <bits/stdc++.h>
using namespace std;

/*
Explanation : Time complexity of this is logn
I want to achieve a situation in which all the elements in the left half are smaller than all the elements in the right half
If the total number of elements is odd the extra one from the suppossed equal halves will be in the left one
*/

double theMedian(vector<int> array1, vector<int> array2)
{
    // Assuming array_1 is the shorter one
    int n1 = array1.size(), n2 = array2.size(), begin = 0, end = n1;
    while (begin <= end)
    {
        int mid1 = (begin + end) / 2;
        int mid2 = ((n1 + n2 + 1) / 2) - mid1;

        // mid2 is computed such that left total and right total number of elements are the same
        //  mid1 is the starting of the right array of array 1
        //  mid2 is the starting of the right array of array 2

        int min1 = (mid1 == n1) ? (INT_MAX) : array1[mid1]; //min elem at right side of a1
        //aage chalke mujhe dekhna h ke max2 is se bada to nahi h
        //now if mid1 = n1, its illogical ill add the whole array, so I need the case to pass, so I need to make min1 param parmatma jis se max2 bada ho hi na sake 
        int min2 = (mid2 == n2) ? (INT_MAX) : array2[mid2]; //min elem at right side of a2
        //aage chalke mujhe dekhna h ke max1 is se bada to nahi h
        //now if mid2 = n2, its illogical ill add the whole array, so I need the case to pass, so I need to make min2 param parmatma jis se max1 bada ho hi na sake 
        int max1 = (mid1 == 0) ? (INT_MIN) : array1[mid1 - 1]; //max elem at right side of a1\
        //aage chalke mujhe dekhna h ke min2 is se chota to nahi h
        //now if mid1 = 0, mid1 - 1 index is illogical ill add the whole array, so I need the case to pass, so I need to make max1 fall guy jis se min2 chota ho hi na sake 
        int max2 = (mid2 == 0) ? (INT_MIN) : array2[mid2 - 1]; //max elem at right side of a2
        //aage chalke mujhe dekhna h ke min1 is se chota to nahi h
        //now if mid2 = 0, mid2 - 1 index is illogical ill add the whole array, so I need the case to pass, so I need to make max1 fall guy jis se min1 chota ho hi na sake 

        if ((max1 <= min2) && (max2 <= min1))
        {
            if ((n1 + n2) % 2 == 0)
            {
                return (double)((max(max1, max2) + min(min1, min2)) / 2.0);
            }
            else
            {
                return (double)(max(max1, max2));
            }
        }
        else if (max1 > min2)
        {
            //so we gotta increase max1 and decrease min2, means increase mid2 and decrease mid1, so we reduce end
            end = mid1 - 1;
        }
        else
        {
            //means max2 is greater than min1, means we gotta reduce max2 and increase min1, means we gotta increase mid1 and decrease mid2
            begin = mid1 + 1;
        }
    }
}

int main()
{
    cout << "Enter the array 1 length" << endl;
    int n1;
    cin >> n1;
    cout << "Enter the elements for array 1" << endl;
    int elem1;
    vector<int> my_vect_1;
    for (int i = 0; i < n1; i++)
    {
        cin >> elem1;
        my_vect_1.push_back(elem1);
    }
    cout << "Enter the array 2 length" << endl;
    int n2;
    cin >> n2;
    cout << "Enter the elements for array 2" << endl;
    int elem2;
    vector<int> my_vect_2;
    for (int i = 0; i < n2; i++)
    {
        cin >> elem2;
        my_vect_2.push_back(elem2);
    }
}