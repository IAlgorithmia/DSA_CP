#include <bits/stdc++.h>
using namespace std;

/*
Explanation : Like in the previous code, we can find the previous smaller element and the next smaller element
*/

// Main Logic for Solution 1 : For each bar, I have to find out the max area I can get considering that current bar is the smallest bar among
// the bars that I've counted

// Also If I can find the prev smaller and next smaller element for each element, then I can find the area of the rectangle,
// lets say I got the indices as x and  y, this means that I can include bars from x + 1 to y - 1, including the current bar itself
// i find out that width, which will be y - x - 1, and then multiply it with the height of the current bar
// max that value for all bars

// Logic for solution 2 :
// This is based on two observations for Monotonic Stacks : (well the first one but just writing the second one for the sake of it)
// 1. In an bottom to top increasing monotonic stack, we remove while top >= curr, so for that top
// curr is the next closest smaller element and top - 1 vala is the prev closest smaller element
// 2. In an bottom to top decreasing monotonic stack, we remove while top <= curr, so for that top
// curr is the next closest greater element and top - 1 vala is the prev closest greater element

//Hence for the opimal solution, we need not even create the prev smaller and next smaller arrays, we can just use the stack to find the values

// Do the largest rectangle in histogram problem and maximal square problem on leetcode

// End mein leetcode vala answer hai

int LargestHistogramAreaSolution1(vector<int> sample_vector)
{
    // We calculate the closest previous and next smaller arrays, and do the below things for each element
    // hence in the stack ill need to remove all the greater or equal to ones

    // IMP PART IMP PART

    vector<int> prev_smaller;
    stack<int> prev_smalls;
    for (int i = 0; i < sample_vector.size(); i++)
    {
        while (!prev_smalls.empty() && !(sample_vector[prev_smalls.top()] < sample_vector[i]))
        {
            prev_smalls.pop();
        }
        if (prev_smalls.size() == 0)
        {
            prev_smalls.push(i);
            prev_smaller.push_back(-1);
        }
        else if (sample_vector[prev_smalls.top()] < sample_vector[i])
        {
            prev_smaller.push_back(prev_smalls.top());
            prev_smalls.push(i);
        }
    }
    vector<int> next_smaller;
    stack<int> next_smalls;
    for (int i = sample_vector.size() - 1; i >= 0; i--)
    {
        while (!next_smalls.empty() && !(sample_vector[next_smalls.top()] < sample_vector[i]))
        {
            next_smalls.pop();
        }
        if (next_smalls.size() == 0)
        {
            next_smalls.push(i);
            next_smaller.push_back(sample_vector.size());
        }
        else if (sample_vector[next_smalls.top()] < sample_vector[i])
        {
            next_smaller.push_back(next_smalls.top());
            next_smalls.push(i);
        }
    }
    reverse(next_smaller.begin(), next_smaller.end());

    // The above two give the required arrays

    // for (int i = 0; i < sample_vector.size(); i++){
    //     cout << prev_smaller[i] << endl;
    // }
    // cout << "Heyaa" << endl;
    // for (int i = 0; i < sample_vector.size(); i++){
    //     cout << next_smaller[i] << endl;
    // }

    int res = 0;
    int curr;
    for (int i = 0; i < sample_vector.size(); i++)
    {
        curr = sample_vector[i];
        curr += (i - prev_smaller[i] - 1) * sample_vector[i];
        curr += (next_smaller[i] - i - 1) * sample_vector[i];
        res = max(res, curr);
    }
    return res;
}

int LargestHistogramAreaSolution2(vector<int> sample_vector)
{
    stack<int> s;
    int res = 0;
    int n = sample_vector.size();
    int tp, curr;
    for (int i = 0; i < n; i++)
    {
        while (s.empty() == false && sample_vector[s.top()] >= sample_vector[i]) // >= because so that the current element can be the closest right smaller for the top element
        {
            tp = s.top();   
            s.pop();

            // now the top element is the closest left smaller element for the current element
            // s.empty() means stack is empty, means top vale ka koi left smaller tha hi nahi, means left ke saare greater the
            // all can be counted for that particular top which was removed, and since i is the next smaller element
            // total bars will be i + 1 - 1, +1 because 0 index hai so to convert it into the number of bars,
            //-1 because us last vale bar ko to include nahi kar sakte, hence total_bars = i

            // if not empty, means koi to hai uska prev smaller, means total_bars = i - top - 1

            curr = sample_vector[tp] * (s.empty() ? i : (i - s.top() - 1));
            res = max(res, curr);
        }
        s.push(i);
    }
    //agar stack mein abhi bhi kuch bach raha hai that means that uska next smaller nahi tha koi, 
    //means uske right ke saare bars valid bars hain, so we just go into case two of the above 
    // with i as n, bas ab stack khali karna hai bas

    while (s.empty() == false)
    {
        tp = s.top();
        s.pop();
        //agar stack empty hai, means right mein koi nahi tha, left mein koi nahi tha, toh saare bars valid hain
        curr = sample_vector[tp] * (s.empty() ? n : (n - s.top() - 1));
        res = max(res, curr);
    }
    return res;
}

int main()
{
    cout << "Enter number of elements : " << endl;
    int n;
    cin >> n;
    vector<int> sample_vector;
    cout << "Enter the elements : " << endl;
    int item;
    for (int i = 0; i < n; i++)
    {
        cin >> item;
        sample_vector.push_back(item);
    }
    cout << LargestHistogramAreaSolution1(sample_vector) << endl;
    cout << LargestHistogramAreaSolution2(sample_vector) << endl;
}

class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {

        int n = heights.size();

        // creating the prev smaller array
        // hence in the stack ill need to remove all the greater or equal to ones

        vector<int> prev_smallers(n, 0);
        stack<int> s;
        s.push(0);
        prev_smallers[0] = -1; // since nothing is smaller than this

        for (int i = 1; i < n; i++)
        {

            while (s.empty() == false && heights[s.top()] >= heights[i])
                s.pop();

            if (s.empty())
            {
                // means this is the smallest element yet
                prev_smallers[i] = -1;
            }
            else
            {
                // means kuch to mila h smaller us se
                prev_smallers[i] = s.top();
            }
            s.push(i);
        }

        while (s.empty() == false)
        {
            s.pop();
        }

        vector<int> next_smallers(n, 0);
        s.push(n - 1);
        next_smallers[n - 1] = n;

        for (int i = n - 2; i >= 0; i--)
        {

            while (s.empty() == false && heights[s.top()] >= heights[i])
                s.pop();

            if (s.empty())
            {
                // means this is the smallest one from the right side
                next_smallers[i] = n;
            }
            else
            {
                next_smallers[i] = s.top();
            }

            s.push(i);
        }

        for (auto i : prev_smallers)
        {
            cout << i << " ";
        }
        cout << endl;
        for (auto j : next_smallers)
        {
            cout << j << " ";
        }
        cout << endl;

        int answer = INT_MIN;

        for (int i = 0; i < n; i++)
        {
            int left_smaller = prev_smallers[i];
            int right_smaller = next_smallers[i];
            int total_bars;
            if (left_smaller == -1 && right_smaller != n)
            {
                // means left mein koi smaller nahi hai but right mein hai
                total_bars = right_smaller + 1 - 1; // + 1 because right_smaller ek index hai, hence to convert it into the number of bars
            }
            else if (left_smaller != -1 && right_smaller == n)
            {
                // means left mein koi smaller hai but right mein nahi hai
                total_bars = n - left_smaller - 1; //-1 because left_smaller ek index hai, hence to convert it into the number of bars
            }
            else if (left_smaller == -1 && right_smaller == n)
            {
                // means na left mein koi smaller hai na right mein, that means ke pura ke pura heights vector valid hai iske liye
                total_bars = heights.size();
            }
            else
            {
                // means left mein smaller bhi hai right mein bhi
                total_bars = right_smaller - left_smaller - 1;
            }
            cout << total_bars << " ";
            answer = max(answer, total_bars * heights[i]);
        }

        return answer;
    }
};