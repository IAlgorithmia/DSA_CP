#include <bits/stdc++.h>
using namespace std;

/**
 * Removes duplicates from a sorted vector and returns the new size.
 * 
 * This function assumes that the input vector is sorted. It iterates through the vector,
 * keeping track of the last non-duplicate element's index. If it finds a non-duplicate element,
 * it increments the index and assigns the new element to that index.
 * 
 * @param the_vector The input vector to remove duplicates from.
 * @return The new size of the vector after removing duplicates.
 * 
 * Example:
 * Input: [1, 1, 2, 2, 3, 3, 4, 5, 5]
 * Output: [1, 2, 3, 4, 5]
 * New size: 5
 */
int removeDup(vector<int>& the_vector) 
{
    int n = the_vector.size();
    int res = 0;
    the_vector[res] = the_vector[0]; // for understanding, because 1st element humesha rahega result mein
    for (int i = 1; i < n; i++)
    {
        if (the_vector[i] != the_vector[res]) // res is the index of last non duplicate element
        {
            res++;
            the_vector[res] = the_vector[i]; // res in the index where ther next non dulicate element will be stored
        }
    }
    return res + 1; 
}

// /**
//  * Removes duplicates from an unsorted vector and returns the new size.
//  * 
//  * This function uses an unordered set to keep track of unique elements.
//  * It iterates through the vector, inserting elements into the set and counting the number of originals.
//  * Then, it assigns the elements from the set back to the vector.
//  * 
//  * @param the_vector The input vector to remove duplicates from.
//  * @return The new size of the vector after removing duplicates.
//  * 
//  * Example:
//  * Input: [5, 2, 8, 2, 1, 9, 5, 3]
//  * Output: [5, 2, 8, 1, 9, 3]
//  * New size: 6
// */
// int removeDup(vector<int>& the_vector) 
// {
//     unordered_set<int> my_set;
//     int originals = 0;
//     for (int i = 0; i < the_vector.size(); i++)
//     {
//         if (my_set.find(the_vector[i]) == my_set.end())
//         {
//             my_set.insert(the_vector[i]);
//             originals++;
//         }
//     }
//     unordered_set<int>::iterator it = my_set.begin();
//     for (int i = 0; i < originals; i++)
//     {
//         the_vector[i] = *it;
//         it++;
//     }
//     // We could also do the_vector.assign(my_set.begin(), my_set.end());
//     return originals;
// }

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
    int ans = removeDup(my_vect);
    cout << "New size is : " << ans << endl;
    for (int i = 0; i < ans; i++)
    {
        cout << my_vect[i] << endl;
    }
}