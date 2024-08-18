#include <bits/stdc++.h>
using namespace std;

/*
Explanation : Span includes values equal or smaller of the left
Stock Span array return karna hai, span = (index of current element) - (index of the closest greater element on left side) 
*/

vector<int> StockSpan(vector<int> stocks){
    vector<int> span;
    stack<int> prev_greats;
    for (int i = 0; i < stocks.size(); i++){
        while (!prev_greats.empty() && !(stocks[prev_greats.top()] > stocks[i])){
            prev_greats.pop();
        }
        if (prev_greats.size() == 0){
            prev_greats.push(i);
            span.push_back(i + 1);
        }
        else if (stocks[prev_greats.top()] > stocks[i]){
            span.push_back(i - prev_greats.top());
            prev_greats.push(i);
        }
    }
    return span;
}

//In a similar fashion as above, we can solve the problem of getting the closest previous greater element of the left side
//In a similar fashion as above, we can solve the problem of getting the closest next greater element of the right side, we just have to start from the right side in this problem

vector<int> PrevGreater(vector<int> stocks){
    vector<int> prev_greater;
    stack<int> prev_greats;
    for (int i = 0; i < stocks.size(); i++){
        while (!prev_greats.empty() && !(stocks[prev_greats.top()] > stocks[i])){
            prev_greats.pop();
        }
        if (prev_greats.size() == 0){
            prev_greats.push(i);
            prev_greater.push_back(-1);
        }
        else if (stocks[prev_greats.top()] > stocks[i]){
            prev_greater.push_back(stocks[prev_greats.top()]);
            prev_greats.push(i);
        }
    }
    return prev_greater;
}

vector<int> NextGreater(vector<int> stocks){
    vector<int> next_greater;
    stack<int> next_greats;
    for (int i = stocks.size() - 1; i >= 0; i--){
        while (!next_greats.empty() && !(stocks[next_greats.top()] > stocks[i])){
            next_greats.pop();
        }
        if (next_greats.size() == 0){
            next_greats.push(i);
            next_greater.push_back(-1);
        }
        else if (stocks[next_greats.top()] > stocks[i]){
            next_greater.push_back(stocks[next_greats.top()]);
            next_greats.push(i);
        }
    }
    reverse(next_greater.begin(), next_greater.end());
    return next_greater;
}

int main(){
    cout << "Enter number of stocks : " << endl;
    int n;
    cin >> n;
    vector<int> stocks;
    cout << "Enter the elements : " << endl;
    int item;
    for (int i = 0; i < n; i++){
        cin >> item;
        stocks.push_back(item);
    }
    cout << "Stock Span : " << endl;
    vector<int> answer = StockSpan(stocks);
    for (auto I : answer){
        cout << I << endl;
    }
    answer = PrevGreater(stocks);
    cout << "Prev Greater : " << endl;
    for (auto I : answer){
        cout << I << endl;
    }
    answer = NextGreater(stocks);
    cout << "Next Greater : " << endl;
    for (auto I : answer){
        cout << I << endl;
    }
}