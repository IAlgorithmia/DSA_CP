#include <bits/stdc++.h>
using namespace std;

/*
Explanation : Span includes values equal or smaller of the left
Stock Span array return karna hai, span = (index of current element) - (index of the closest greater element on left side) 
*/

//basically jab tak stack me koi element hai aur uska value current element se choti hai, tab tak pop karte raho
//agar stack khali hai toh span = index + 1 since there is no greater element on the left side
//agar stack me kuch hai toh span = index - stack.top() since stack.top() is the closest greater element on the left side

vector<int> StockSpan(vector<int> stocks){
    vector<int> span;
    stack<int> s;
    s.push(0); //processing the first element
    for (int i = 1; i < stocks.size(); i++){
        while (s.empty() == false && stocks[s.top()] <= stocks[i]){
            s.pop();
        }
        if (s.size() == 0){
            span.push_back(i + 1);
        }
        else {
            span.push_back(i - s.top());
        }
        s.push(i);
    }
    return span;
}

//In a similar fashion as above, we can solve the problem of getting the closest previous greater element of the left side
//In a similar fashion as above, we can solve the problem of getting the closest next greater element of the right side, we just have to start from the right side in this problem

vector<int> PrevGreater(vector<int> stocks){
    vector<int> prev_greater;
    stack<int> s;
    for (int i = 0; i < stocks.size(); i++){
        while (s.empty() == false && stocks[s.top()] <= stocks[i]){
            s.pop();
        }
        if (s.size() == 0){
            prev_greater.push_back(-1);
        }
        else if (stocks[s.top()] > stocks[i]){
            prev_greater.push_back(stocks[s.top()]);
        }
        s.push(i);
    }
    return prev_greater;
}

vector<int> NextGreater(vector<int> stocks){
    vector<int> next_greater;
    stack<int> s;
    for (int i = stocks.size() - 1; i >= 0; i--){
        while (s.empty() == false && stocks[s.top()] <= stocks[i]){
            s.pop();
        }
        if (s.size() == 0){
            s.push(i);
            next_greater.push_back(-1);
        }
        else if (stocks[s.top()] > stocks[i]){
            next_greater.push_back(stocks[s.top()]);
            s.push(i);
        }
    }
    reverse(next_greater.begin(), next_greater.end());
    return next_greater;
}

//basically 4 cases ban sakte hain 
//closest smaller on left side, closest smaller on right side, closest greater on left side, closest greater on right side
//each can be done in a similar fashion as above

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