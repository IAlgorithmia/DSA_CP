#include <bits/stdc++.h>
using namespace std;

/*
Explanation : at least one half will always be sorted in these types of arrays
Binary search m humesha sorted part m hi laga raha hu, else mai 
scope hi change kar raha hu mere array ka
*/

// Iterative
int searchSpecialIter(vector<int> the_vector, int elem)
{
    int low = 0;
    int high = the_vector.size() - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (elem == the_vector[mid]) //beech m hi mil gaya
        {
            return mid;
        }
        else if (the_vector[low] <= the_vector[mid]) //means left is sorted
        {
            if ((elem >= the_vector[low]) && (elem <= the_vector[mid])) //means left m hi hai
            {
                high = mid - 1;
            }
            else // means left to na h so we gotta change the scope
            {
                low = mid + 1;
            }
        }
        else //coming here if right is sorted
        {
            if ((elem >= the_vector[mid]) && (elem <= the_vector[high])) //means right m hi hai
            {
                low = mid + 1;
            }
            else // means right to na h so we gotta change the scope
            {
                high = mid - 1; 
            }
        }
    }
    return -1;
}

// Recursive
int searchSpecial(int low, int high, vector<int> the_vector, int elem)
{
    if (low > high)
    {
        return -1;
    }
    else
    {
        int mid = (low + high) / 2;
        if (elem == the_vector[mid])
        {
            return mid;
        }
        else if (the_vector[low] <= the_vector[mid])
        {
            if ((elem >= the_vector[low]) && (elem < the_vector[mid]))
            {
                return searchSpecial(low, mid - 1, the_vector, elem);
            }
            else
            {
                return searchSpecial(mid + 1, high, the_vector, elem);
            }
        }
        else
        {
            if ((elem > the_vector[mid]) && (elem <= the_vector[high]))
            {
                return searchSpecial(mid + 1, high, the_vector, elem);
            }
            else
            {
                return searchSpecial(low, mid - 1, the_vector, elem);
            }
        }
    }
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
    cout << "Enter the number you want to search " << endl;
    int num;
    cin >> num;
    cout << searchSpecial(0, n - 1, my_vect, num) << endl << searchSpecialIter(my_vect, num);
}