#include <bits/stdc++.h>
using namespace std;

/*
Explanation :

You have two arrays: petrol[] and dist[].
petrol[i] gives the amount of petrol at the i-th petrol pump.
dist[i] gives the distance to the next petrol pump from the i-th petrol pump.

*/

int NaiveImplementation(vector<int> petrol, vector<int> dist, int n)
{
    for (int start = 0; start < n; start++)
    {
        int curr_petrol = 0;
        int end = start;
        while (true)
        {
            curr_petrol += petrol[end] - dist[end];
            if (curr_petrol < 0)
            {
                break;
            }
            end = (end + 1) % n;
            if (end == start)
            {
                return start + 1; //+ 1 because we want to return the position of the station number, not index
            }
        }
    }
    return -1;
}

/*
The tellStartingPump function aims to determine the starting petrol pump index from which a truck can complete a
circular tour of petrol pumps. The function takes two vectors as input: petrols, which represents the
amount of petrol available at each pump, and distances, which represents the distance to the next pump.

The function initializes a deque dq to keep track of the indices of the petrol pumps being considered as starting
points. It also initializes curr_petrol to track the current amount of petrol in the truck, count
to iterate through the petrol pumps, and checked_as_starting to count how many pumps have
been checked as potential starting points.

The main loop runs while the number of checked starting points is less than the total number of
petrol pumps and the size of the deque is less than the total number of
petrol pumps. Inside the loop, the current pump index (count) is added to the deque, and the
petrol at this pump is added to curr_petrol, while the distance to the next pump is subtracted from curr_petrol.

If at any point curr_petrol becomes negative, indicating that the truck cannot reach the next
pump, the function enters a nested loop. This loop removes the
front element from the deque, effectively undoing the changes made by the first pump in the deque.
The petrol and distance values of this pump are subtracted and added back to
curr_petrol, respectively, and checked_as_starting is incremented.

The count variable is then incremented and wrapped around using the modulo operator to ensure it stays within
the bounds of the petrol pumps array. After exiting the main loop, the function checks
if the size of the deque is equal to the number of petrol pumps. If true, it means
a valid starting point has been found, and the function returns the index of the first pump in the
deque. Otherwise, it returns -1, indicating that no valid starting point exists.
*/

// Basically :
// keep adding items to end of deque until curr_petrol is >= 0,
// keep removing items from the start of deque until curr_petrol < 0

// Better implementation

int tellStartingPump(vector<int> petrols, vector<int> distances)
{
    deque<int> dq;
    int curr_petrol = 0;
    int count = 0;
    int checked_as_starting = 0;
    while ((checked_as_starting < petrols.size()) && (dq.size() < petrols.size()))
    {
        dq.push_back(count);
        curr_petrol += petrols[count];
        curr_petrol -= distances[count];
        while (!dq.empty() && curr_petrol < 0)
        {
            curr_petrol -= petrols[dq.front()];
            curr_petrol += distances[dq.front()];
            // basically undo the changes made due to the front
            dq.pop_front();
            checked_as_starting++;
        }
        count = (count + 1) % petrols.size();
    }
    return (dq.size() == petrols.size() ? petrols[dq.front()] : -1);
}

// The efficient implementation is based on the fact that
// If at any station pi, the curr_petrol becomes negative,
// the stations from p0 to pi cant be the answers, proof in Video
// So whenever we encounter such a situation, we shift the starting point TO the just next station do the travelling,
// reset the curr_petrol after saving it into prev_petrol
// in the end, whatever starting point we get, curr_petrol will represent
// the tank status from that point to the ending, and prev_petrol
// will represent tank status from 0th station to start station
// since hum jis station ko start maan rahe hain, vahan se leke
// end tak kahin bhi negative to nahi hua hoga tank status - definition & condition of start station
// so now if it can stay >= 0 when combined with the petrol req to go from 0th to start, prev_petrol
// then we can make the journey

int efficient(vector<int> petrols, vector<int> distances)
{
    int start = 0;
    int prev_petrol = 0;
    int curr_petrol = 0;
    for (int i = 0; i < petrols.size(); i++)
    {
        curr_petrol += petrols[i] - distances[i];
        if (curr_petrol < 0)
        {
            start = i + 1;
            prev_petrol += curr_petrol;
            curr_petrol = 0; // start again
        }
    }
    return ((curr_petrol + prev_petrol) >= 0 ? start + 1 : -1);
}

int main()
{
    int n;
    cout << "Enter the size of arrays you want : " << endl;
    cin >> n;
    cout << "Enter the elements for petrol pumps : " << endl;
    vector<int> petrols;
    int item;
    for (int i = 0; i < n; i++)
    {
        cin >> item;
        petrols.push_back(item);
    }
    cout << "Enter the elements for distances : " << endl;
    vector<int> distances;
    for (int i = 0; i < n; i++)
    {
        cin >> item;
        distances.push_back(item);
    }
    cout << tellStartingPump(petrols, distances) << endl;
}