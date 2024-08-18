#include <bits/stdc++.h>
using namespace std;


//IMPORTANT
//IF ELEMENT IS NOT FOUND IN BINARY SEARCH, FINALLY LOW IS AT THE JUST ABOVE OF THE NUMBER
//AND HIGH IS AT THE JUST BELOW OF THE NUMBER
/*
Explanation : Given array must be sorted
*/

int firstTimeIter(vector<int> the_vector, int num)
{
    int low = 0;
    int high = the_vector.size() - 1;
    int mid;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (the_vector[mid] == num)
        {
            if ((mid - 1 >= low) && the_vector[mid - 1] == num) // Piche vala same hai means daal mein kuch kaala hai
            {
                high = mid - 1;
            }
            else
            {
                return mid;
            }
        }
        else if (num > the_vector[mid])
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}

int firstTimeRecur(vector<int> the_vector, int low, int high, int num)
{
    if (low > high)
    {
        return -1;
    }
    else
    {
        int mid = (low + high) / 2;
        if (the_vector[mid] == num)
        {
            int temp = firstTimeRecur(the_vector, low, mid - 1, num);
            if (temp == -1)
            {
                return mid;
            }
            else
            {
                return temp;
            }
        }
        else if (the_vector[mid] > num)
        {
            return firstTimeRecur(the_vector, low, mid - 1, num);
        }
        else
        {
            return firstTimeRecur(the_vector, mid + 1, high, num);
        }
    }
}

int lastTimeIter(vector<int> the_vector, int num)
{
    int low = 0;
    int high = the_vector.size() - 1;
    int mid;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (the_vector[mid] == num)
        {
            if ((mid + 1 <= high) && the_vector[mid + 1] == num) // Piche vala same hai means daal mein kuch kaala hai
            {
                low = mid + 1;
            }
            else
            {
                return mid;
            }
        }
        else if (num > the_vector[mid])
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}

int lastTimeRecur(vector<int> the_vector, int low, int high, int num)
{
    if (low > high)
    {
        return -1;
    }
    else
    {
        int mid = (low + high) / 2;
        if (the_vector[mid] == num)
        {
            int temp = lastTimeRecur(the_vector, mid + 1, high, num);
            if (temp == -1)
            {
                return mid;
            }
            else
            {
                return temp;
            }
        }
        else if (the_vector[mid] > num)
        {
            return lastTimeRecur(the_vector, low, mid - 1, num);
        }
        else
        {
            return lastTimeRecur(the_vector, mid + 1, high, num);
        }
    }
}

int main(){
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
    cout << "First time : " << endl;
    cout << firstTimeRecur(my_vect, 0, n - 1, num) << endl << firstTimeIter(my_vect, num) << endl;
    cout << "Last time : " << endl;
    cout << lastTimeRecur(my_vect, 0, n - 1, num) << endl << lastTimeIter(my_vect, num) << endl;
}
