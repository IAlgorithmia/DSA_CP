#include <bits/stdc++.h>
using namespace std;

// Either we can call the left rotate by 1 function a total of D times, time complexity becomes O(n*d)
// Next the obvious modification of left rotate, resulting in O(n) time complexity and O(d) sapce complexity
// Best one below

void leftRotateByD(vector<int> &the_vector, int d)
{
    //we want first d elements end mein chale jaayein and first d ke aage vale 
    //starting mein aa jaayein
    int n = the_vector.size();
    reverse(the_vector.begin(), the_vector.begin() + d); //reverse the first d elements
    reverse(the_vector.begin() + d, the_vector.end()); //reverse the remaining 
    reverse(the_vector.begin(), the_vector.end()); //reverse the entire
}

void rightRotateByD(vector<int> &the_vector, int d){
    //last ke d starting mein aa jaayein
    //baaki aage chale jaayein
    reverse(the_vector.end() - d, the_vector.end()); //reverse the last d elements
    reverse(the_vector.begin(), the_vector.end() - d);//reverse the before value
    reverse(the_vector.begin(), the_vector.end());//reverse the array
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
    int D;
    cout << "Enter the value of D : ";
    cin >> D;
    D = D % n;
    // leftRotateByD(my_vect, D);
    rightRotateByD(my_vect, D);
    for (int i = 0; i < n; i++)
    {
        cout << my_vect[i] << endl;
    }
}