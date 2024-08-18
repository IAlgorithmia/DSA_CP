#include <bits/stdc++.h>
using namespace std;

void powersetgen(const string &the_string, string curr_string, int index)
{
    if (index == the_string.size())
    {
        cout << curr_string << endl;
        return;
    }
   powersetgen(the_string, curr_string, index + 1);
   powersetgen(the_string, curr_string + the_string[index], index + 1);
}

int main(){
    cout << "Enter the special string : " << endl;
    string the_string;
    cin >> the_string;
    powersetgen(the_string, "", 0);
}