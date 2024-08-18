#include <bits/stdc++.h>
using namespace std;

/*
Explanation : 
*/

int sqRoot(int num)
{
    int square;
    int low = 0;
    int high = num;
    int mid;
    int answer;
    while (low <= high)
    {
        mid = (low + high) / 2;
        square = mid * mid;
        if (square > num)
        {
            high = mid - 1;
        }
        else if (square < num)
        {
            low = mid + 1;
            answer = mid;
            //Basically we are storing the last closest value that is smaller than the number itself
        }
        else
        {
            return mid;
        }
    }
    return answer;
}

int main(){
    cout << "Enter the number " << endl;
    int num;
    cin >> num;
    cout << sqRoot(num);
}