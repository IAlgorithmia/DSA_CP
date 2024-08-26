#include <bits/stdc++.h>
using namespace std;

/*
Explanation : The complexity of the below code O(n) even though it may not seem like

We will maintain a strictly decreasing order in the dq, and that too, in order in which they appear in the array

The front will give us the max element for that window

For moving onto the next window :
0. We will store the indices to clearly remove the elements which have gone out of the window
1. If the front index, has gone out of the window, If the dq is full, we delete the front, then try do the below
2. Delete all elements from the end which are smaller than or equal to current element, start comparing from the end,

We will perform three things
*/

void printMaxInKs(vector<int> sample_vector, int k)
{
    deque<int> dq;
    for (int i = 0; i < k; i++)
    {
        while (!dq.empty() && sample_vector[i] >= sample_vector[dq.back()])
        {
            dq.pop_back();
        }
        dq.push_back(i);
    }
    for (int i = k; i < sample_vector.size(); i++)
    {
        cout << sample_vector[dq.front()] << endl;
        if (!dq.empty() && dq.front() <= (i - k))
        {
            dq.pop_front();
        }
        while (!dq.empty() && sample_vector[i] >= sample_vector[dq.back()])
        {
            dq.pop_back();
        }
        dq.push_back(i);
    }
    // last mein ye hoga ke aakhri window process ho chuki hoyegi, but since we cant go any further in terms of i
    // we cant proceed in the looop, hence printing outside it
    cout << sample_vector[dq.front()] << endl;
}

int main()
{
    int n;
    cout << "Enter the size of the array you want : " << endl;
    cin >> n;
    int k;
    cout << "Enter the value of k : " << endl;
    cin >> k;
    cout << "Enter the elements : " << endl;
    vector<int> sample_vector;
    int item;
    for (int i = 0; i < n; i++)
    {
        cin >> item;
        sample_vector.push_back(item);
    }
    printMaxInKs(sample_vector, k);
}