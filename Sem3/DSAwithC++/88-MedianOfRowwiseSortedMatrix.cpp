#include <bits/stdc++.h>
using namespace std;

/*
Explanation : We use a new function here called upper_bound
vector<int> v = {10, 20, 30, 40, 50};
    cout << (upper_bound(v.begin(), v.end(), 35) - v.begin()) << endl;
    the above gives 3, it returns an iterator pointing to the next larger element, value chahiye to dereference it directly, index chahiye to subtract v.begin()
    lower_bound() gives equal to or greater than element, upper_bound() gives greater than element

The time complexity of the solution is O(log(max - min) * rows * log(cols))

Is type ka kara hua hai humne pehle, first min and max nikalenge from the first and last columns since the matrix is rowsie sorted, then midpos nikalenge, then mid means min and max ka middle nikalenge, and so on ...
recall minimize the number of maximum books allocated to a student wala question
But I think this one is answer space pe binary search

This is KIND OF binary search on a 2D matrix
*/

int MedianOfMatrix(vector<vector<int>> sampleVector){
    int rows = sampleVector.size();
    int cols = sampleVector[0].size();
    int min = INT_MAX;
    int max = INT_MIN;
    for (int i = 0; i < rows; i++){
        min = (sampleVector[i][0] < min) ? sampleVector[i][0] : min;
        max = (sampleVector[i][cols - 1] > max) ? sampleVector[i][cols - 1] : max; 
    }

    int midPosNeeded = ((rows * cols) + 1) / 2; 
    //this is mid pos, not mid index, uske liye + 1 na karte, hum position ke sath deal kar rahe hain since upperbound gives us + 1 index which is actually the position of req element if it were there
    //forget about needing the medians position, midPosNeeded is just he number of elements that must be smaller than or equal to the median, we match that 
    //to all possible medians, and then we get the median

    while (min < max){//min < max and not equal to because when min == max, we have found the median
        int mid = (min + max) / 2;
        int midPos = 0;
        for (int i = 0; i < rows; i++){
            midPos += (upper_bound(sampleVector[i].begin(), sampleVector[i].end(), mid) - sampleVector[i].begin());
        }
        if (midPos < midPosNeeded){
            //now we need to increase the value of mid
            min = mid + 1;
        }
        else{
            //if equal or less than we need to still go to the left side, since
            // we will get our answer when min == max
            //and we will find the median element in the left side since right m to ho hi nahi sakta 
            //this is because mid might not be a real element in the matrix
            max = mid;
        }
    }
    return min;
}

int main(){
    vector<vector<int>> sampleVector = {{5, 10, 20, 30, 40}, {1, 2, 3, 4, 6}, {11, 13, 15, 17, 19}};
    cout << MedianOfMatrix(sampleVector) << endl;
}