#include <bits/stdc++.h>
using namespace std;

int check_sub_set_sum(int &the_set[], int index, int the_sum)
{
    //sum is the continuously added sum of each element on each level, so that in the end we don't have to check, index once if it reaches index, we will check for the sums
    if (index == 0)
    {
        return (the_sum == 0 ? 1 : 0);
    }
    return (check_sub_set_sum(the_set, index - 1, the_sum) + check_sub_set_sum(the_set, index - 1, the_sum - the_set[length - 1]));
}

int main()
{
    cout << "Enter how many elements you want, then the elements for the set, then the sum you're searching for : " << endl;
    int n, elem, the_sum;
    cin >> n;
    int my_set[n];
    for (int i = 0; i < n; i++)
    {
        cin >> elem;
        my_set[i] = elem;
    }
    cin >> the_sum;
    cout << check_sub_set_sum(my_set, n, the_sum);
}