#include <bits/stdc++.h>
using namespace std;

void printFrequency(vector<int> the_vector)
{
    //We are given the array is sorted
    int n = the_vector.size(), i = 1, occurences = 0;
    cout << the_vector[0] << " ";
    occurences++;
    while (i < n)
    {
        if (the_vector[i] != the_vector[i - 1])
        {
            //new element encountered means ab purana vala nahi ayega dubara
            //hence we print the occurrences of this element
            cout << occurences << endl;
            occurences = 1;
            cout << the_vector[i] << " ";
        }
        else
        {
            occurences++;
        }
        i++;
    }
    //couldve done this with a for loop too
    cout << occurences << endl;
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
    printFrequency(my_vect);
}