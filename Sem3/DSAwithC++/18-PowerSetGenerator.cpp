#include <bits/stdc++.h>
using namespace std;

//ITERATVE SOLUTION
// void PowerSetGenerator(string that_string)
// {
//     int length = that_string.length();
//     int subsets_number = pow(2, length);
//     for (int counter = 0; counter < subsets_number; counter++)
//     {
//         for (int j = 0; j < length; j++)
//         {
//             if ((counter & (1 << j)) != 0)
//             {
//                 cout << that_string[j]; 
//             }
//         }
//         cout << endl;
//     }
// }

// RECURSIVE SOLUTION
void PowerSetGenerator(string str, int index, string curr)
{
    if (index == str.size())
    {
        cout << curr << endl;
        return;
    }
    PowerSetGenerator(str, index + 1, curr + str[index]);
    PowerSetGenerator(str, index + 1, curr);
}

int main(){
    string the_string;
    cout << "Enter the string you want to generate power set of : ";
    cin >> the_string;
    PowerSetGenerator(the_string, 0, ""); //For recursive
    // PowerSetGenerator(the_string); //For iterative
}