#include <bits/stdc++.h>
using namespace std;

/*
Explanation : 

Sort the activities according to their finish time
Initialize the solution as the first activity
For the remaining activities : 
    If the current activity overlaps with the last picked activity of the solution, then ignore it
    else add it to the solution

*/

bool myCmp(pair<int, int> a, pair<int, int> b){
    return a.second < b.second;
    //for comp operator just remember that less than stands for ascending/increasing order
}

int maxActivities(vector<pair <int, int>> activities){
    sort(activities.begin(), activities.end(), myCmp);
    int first = activities[0].first;
    int second = activities[0].second;
    int res = 1;
    for (int i = 1; i < activities.size(); i++){
        if (activities[i].first >= second){
            res++;
            first = activities[i].first;
            second = activities[i].second;
            cout << first << " : " << second << endl;
        }
    }
    return res;
}

int main(){
    cout << "Enter the number of pairs you want : " << endl;
    int n;
    cin >> n;
    vector<pair<int, int>> activities(n);
    cout << "Enter 2*n numbers to be considered as pairs :" << endl;
    int elem;
    for (int i = 0; i < 2*n; i++){
        cin >> elem;
        if (i % 2 == 0){
            activities[i/2].first = elem;
        }
        else{
            activities[i/2].second = elem;
        }
    }
    cout << maxActivities(activities) << endl;
}