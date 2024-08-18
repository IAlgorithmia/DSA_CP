#include <bits/stdc++.h>
using namespace std;

/*
Explanation : 
Calculate the ratio value / weight
Sort in decreasing
initialize res and current_cap
Do the following for each element :
    if i.weight <= capacity left:
        capacity -= i.weight
        value += i.value
    else:
        res += i.value * (capacity left/i.weight);
        return res
return res
*/

bool myCmp(pair<int, int> a, pair<int, int> b){
    double r1 = a.first / a.second;
    double r2 = b.first / b.second;
    return r1 > r2; //greater than means descending order
}

int maxValue(vector<pair<int, int>> items, int cap){
    sort(items.begin(), items.end(), myCmp);
    int res = 0;
    int curr_cap = cap;
    for (auto x : items){
        if (curr_cap >= x.second){
            res += x.first;
            curr_cap -= x.second;
        }
        else{
            res += x.first * ((double)curr_cap / x.second);
            break;
        }
    }
    return res;
}

int main(){
    cout << "Enter the number of pairs you want : " << endl;
    int n;
    cin >> n;
    vector<pair<int, int>> items(n);
    cout << "Enter 2*n numbers to be considered as value - weight pair : " << endl;
    int elem;
    for (int i = 0; i < 2*n; i++){
        cin >> elem;
        if (i % 2 == 0){
            items[i/2].first = elem;
        }
        else{
            items[i/2].second = elem;
        }
    }
    cout << "Enter the knapsack capacity : " << endl;
    int cap;
    cin >> cap;
    cout << maxValue(items, cap) << endl;
}