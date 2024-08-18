#include <bits/stdc++.h>
using namespace std;

int main()
{
    int total_milestones;
    cin >> total_milestones;
    int milestone_number, minimum_number, final_product = 1;
    cin >> milestone_number;
    minimum_number = milestone_number;
    final_product *= milestone_number;
    for (int i = 1; i < total_milestones; i++)
    {
        cin >> milestone_number;
        if (milestone_number < minimum_number)
        {
            minimum_number = milestone_number;
        }
        final_product *= milestone_number;
    }
    cout << ((final_product / minimum_number) * (minimum_number + 1));
    return 0;
}