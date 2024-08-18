#include <bits/stdc++.h>
using namespace std;

/**
 * Rearranges the elements of the input vector such that all zeros are moved to the end of the vector.
 * The relative order of non-zero elements is preserved.
 *
 * Time complexity: O(n), where n is the size of the input vector.
 * Space complexity: O(1), since we only use a single extra variable to keep track of the count of non-zero elements.
 *
 * Example:
 * Input: [0, 1, 0, 3, 12]
 * Output: [1, 3, 12, 0, 0]
 */
void zerosAtEnd(vector<int>& the_vector)
{
    //count keeps track of the first 0 encountered from the left
    //when a non zero is encountered that leftmost 0 is replaced with the found non zero
    //hence maintaining the order
    int count = 0;
    for (int i = 0; i < the_vector.size(); i++)
    {
        if (the_vector[i] != 0)
        {
            swap(the_vector[count], the_vector[i]);
            count++;
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
    zerosAtEnd(my_vect);
    cout << "The final vector is : " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << my_vect[i] << endl;
    }
    return 0;
}