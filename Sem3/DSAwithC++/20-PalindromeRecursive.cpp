#include <bits/stdc++.h>
using namespace std;

//tail recursion is preferred, it is faster and pre order and in order are tail recursive, not postorder

bool check_palindrome(string the_string, int a, int b)
{
    if (a >= b)
    {
        return true;
    }

    return ((the_string[a] == the_string[b]) && check_palindrome(the_string, a + 1, b - 1));
}

int main()
{
    cout << "Enter the string : " << endl;
    string check_me;
    cin >> check_me;
    int n = check_me.length();
    cout << check_palindrome(check_me, 0, n - 1);
}