#include <bits/stdc++.h>
using namespace std;

/*
Explanation :
*/

bool feasible(vector<int> the_vector, int num, int k)
{
    // Feasibility will be checked by finding out the minimum number of students required to read the book such that non goes above num, the solution is feasible if this minimum number of less than or equal to k
    int min_students = 1;
    int curr_sum = 0;
    for (int i = 0; i < the_vector.size(); i++)
    {
        if ((curr_sum + the_vector[i]) > num)
        {
            //abhi tak ki books padh li 1st student ne, aur nahi padh sakta
            //second student start kardo ab
            min_students++;
            curr_sum = the_vector[i];
        }
        else
        {
            curr_sum += the_vector[i];
        }
    }
    return (min_students <= k);
}

int minPages(vector<int> the_vector, int k)
{
    int max_elem = INT_MIN;
    int sum_of_elem = 0;
    for (int i = 0; i < the_vector.size(); i++)
    {
        sum_of_elem += the_vector[i];
        max_elem = max(the_vector[i], max_elem);
    }
    //low and high are not what the student can get lowest and highest, they are the lowest and highest possible answers, since we are finding the minimum number of pages a student can read, so the lowest possible answer is the maximum element in the array, and the highest possible answer is the sum of all elements in the array
    //ya aise samajh lo ki agar itne student hote ki sabko ek ek bhi de paau to mera answer ya hota and agarsirf ek hi student h to kitne de sakta hu
    //irrespective of k we have out best and worst case and ispe binary search lagayenge
    int low = max_elem;
    int high = sum_of_elem;
    int lowest = INT_MAX;
    int mid;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (feasible(the_vector, mid, k))
        {
            lowest = min(lowest, mid);
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return lowest;
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
    cout << "Enter the number of children" << endl;
    int k;
    cin >> k;
    cout << minPages(my_vect, k) << endl;
}