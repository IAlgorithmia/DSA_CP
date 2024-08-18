#include <bits/stdc++.h>
using namespace std;

/*
Explanation : We have to find an element which appears more than n / 2 times
Name of this algo is Moore's Voting
*/

int majorityElem(vector<int> the_vector)
{
    int res = NULL, count = 0; //Assuming 1st elem is the candidate
    for (int i = 1; i < the_vector.size(); i++)
    {
        if (the_vector[res] == the_vector[i])
        {
            count++;
        }
        else if (count == 0){
            res = i;
            count = 1;
        }
        else
        {
            count--;
        }
    }
    count = 0;
    for (int i = 0; i < the_vector.size(); i++)
    {
        if (the_vector[res] == the_vector[i])
        {
            count++;
        }
    }
    if (count <= (the_vector.size()/2))
    {
        return -1;
    }
    else
    {
        return the_vector[res];
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
    cout << majorityElem(my_vect);
}