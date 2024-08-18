#include <bits/stdc++.h>
using namespace std;

/*
Explanation : 
*/

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
            if ((mid - 1 >= 0) && the_vector[mid - 1] == num) // Piche vala same hai means daal mein kuch kaala hai
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

int countTimes(vector<int> the_vector, int num)
{
    int first_time = firstTimeIter(the_vector, num);
    if (first_time == -1)
    {
        return 0;
    }
    else
    {
        return (lastTimeIter(the_vector, num) - first_time + 1);
    }
}

//Below code gonna take O(logn + k) time whwere k is the number of occurences of the element

// int countTimesRecur(vector<int> the_vector, int low, int high, int num)
// {
//     if (low < high)
//     {
//         return 0;
//     }
//     else
//     {
//         int mid = (low + high) / 2;
//         if (the_vector[mid] == num)
//         {
//             return (1 + countTimesRecur(the_vector, low, mid - 1, num) + countTimesRecur(the_vector, mid + 1, high, num));
//         }
//         else if (num < the_vector[mid])
//         {
//             return countTimesRecur(the_vector, low, mid - 1, num);
//         }
//         else
//         {
//             return countTimesRecur(the_vector, mid + 1, high, num);
//         }
//     }
//     return 0;
// }

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
    countTimes(my_vect, num);
}