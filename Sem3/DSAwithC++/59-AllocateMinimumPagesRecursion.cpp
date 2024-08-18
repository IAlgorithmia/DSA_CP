#include <bits/stdc++.h>
using namespace std;

//This is first of all taken from starting, not in the video, vo bhi theek hai

// Below is just a utility function
int sumMe(vector<int> the_vector, int from, int to)
{
    int sum = 0;
    for (int i = from; i <= to; i++)
    {
        sum += the_vector[i];
    }
    return sum;
}

//in these types of questions where we gotta minimize the max value or maximize the minimum value we use binary search

//Recursion humesha right to left jaani chahiye, change your thinking to that
//other solution is at bottom se if you want

int pagesFromEnding(vector<int> the_vector, int end, int k)
{
    if (k == 1)
    {
        //if only 1 child left, its gotta read all the books in the scope passed to it
        return sumMe(the_vector, 0, end - 1);
    }
    if (end == 1)
    {
        //if theres only 1 book left, we gotta return it
        return the_vector[0];
    }
    int res = INT_MAX;
    for (int i = 1; i < end; i++)
    {
        //we are saying that books from i to n - 1 we are giving to the current student, and the previous ones behind i to others
        //then we calculate for current student, recursive call for others with students reduced by 1, and books index limited from 0 to i - 1
        //take max from those, and over all possible choices for the cut for current student take min of the maximums
        //then return it
        res = min(res, max(sumMe(the_vector, i, end - 1), pagesFromEnding(the_vector, i, k - 1)));
    }
    return res;
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
    cout << "Enter the number of children" << endl;
    int k;
    cin >> k;
    cout << pagesFromStarting(my_vect, 1, k) << endl;
    cout << pagesFromEnding(my_vect, 1, k) << endl;
}

/*
From Starting -
int pagesFromStarting(vector<int>& the_vector, int start, int k)
{
    //start represents is index se just peeche cut karna hai, so obvio min valid thing is start - 1
    //Ek hi book hai
    if (the_vector.size() == 1)
    {
        return the_vector[0];
    }
    //Ek hi bacha so he gotta read all
    if (k == 1)
    {
        return (sumMe(the_vector, start - 1, the_vector.size() - 1));
    }
    int res = INT_MAX; //This is just done so that we can do the below res thing without having to first store the first value of the result in it
    int j = 0;
    for (int i = start; i <= the_vector.size() - k + 1; i++) //ith index se pehle cut mara ja raha hai, ie if i = 1, then 0th alag, 1 se leke end tal alag
    {
        res = min(res, max(sumMe(the_vector, start - 1, start - 1 + j), pagesFromStarting(the_vector, i + 1, k - 1)));
        j++;
    }
    return res;
}
*/