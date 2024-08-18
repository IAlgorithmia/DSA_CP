
#include <bits/stdc++.h>
using namespace std;

/*
Explanation : Consecutive 1s and 0s can be flipped in 1 flip, we have to tell min number of 
flips required, refer to notebook
*/

int minFlips(vector<int> the_vector)
{
    // int divisions = 0; i dont understand this
    for (int i = 0; i < (the_vector.size() - 1); i++)
    {
        if (the_vector[i] != the_vector[i + 1])
        {
            // divisions++; i dont understand this
            if (the_vector[i + 1] != the_vector[0]) 
            //if it is equal to the first element then that means 
             // that it is to be flipped 
            {
                cout << "From " << i + 1 << " to ";
            }
            else
            {
                cout << i << endl;
            }
        }
    }
    if (the_vector[the_vector.size() - 1] != the_vector[0])
    {
        cout << the_vector.size() - 1 << endl;
    }
    //Above is only for when last element bhi 1st different group ka tha, else vala part to chalega hi nahi, hence for that
    // return min((divisions/2) + 1, (divisions + 1)/2); i dont understand this
    //for number of divisions just check the number of times the conflict occurs
    //then check if last element is same as efirst element
    // if same as first elemnt, then conflicts / 2 else (conflicts + 1) / 2
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
    cout << minFlips(my_vect) << " flips are required.";
}