#include <bits/stdc++.h>
using namespace std;

/*
Explanation :

1st SOlution : uses O(n) space

If we want to implement getMin operation in stack, we can create an
auxilarry stack and whenever the push function is called we check if the pushed value is
smaller than the top of the stack, if yes then push the new value, we
dont pop the previous value. For each time we push a min element say same min 2 baar push hogya
each time we need to push that value into the minimum vala stack, so the condition would
be new_value <= minStack.top(). Also for each time that min element is popped we gotta check
if that popped element is minStack.top() If yes then pop from min stack too. This solution is
O(1) time and O(n) auxilarry space

Normal stack vaise hi chalate raho, aux stack mein push only tab karo jab 
you find an element <= the top of the stack

O(1) time and space approach :

2nd SOlution : uses O(1) space  

stack<int> s;
int min;

void push(int x){
    if (s.isEmpty()){
        min = t;
        s.push(x);
    }
    else if (x <= min){
        s.push(x - min);
        min = x;
    }
    else{
        s.push(x);
    }
}

int peek(){
    t = s.peek();
    return (t <= 0) ? min : t;
}

int pop(){
    t = s.pop();
    if (t <= 0){
        res = min;
        min = min - t;
        return res;
    }
    else{
        return t;
    }
}

For both +ve and -ve :

stack<int> s;
int min;

void push(int x){
    if (s.isEmpty()){
        min = t;
        s.push(x);
    }
    else if (x <= min){
        s.push(2*x - min);
        min = x;
    }
    else{
        s.push(x);
    }
}

int peek(){
    t = s.peek();
    return (t <= min) ? min : t;
}

int pop(){
    t = s.pop();
    if (t <= min){
        res = min;
        min = 2*min - t;
        return res;
    }
    else{
        return t;
    }
}

OR

Completely different approach

class MinStack {
public:
    vector<pair<int, int>> the_vect;
    int top_val = -1;
    int min_val = INT_MAX;

    MinStack() {}

    void push(int val) {
        min_val = (top_val == -1) ? val : min(min_val, val);
        top_val++;
        if (top_val == the_vect.size()) {
            the_vect.push_back({val, min_val});
        } else {
            the_vect[top_val] = {val, min_val};
        }
    }

    void pop() {
        if (top_val != -1) {
            top_val--;
            // Update min_val only if the stack is not empty
            if (top_val != -1) {
                min_val = the_vect[top_val].second;
            } else {
                min_val = INT_MAX;
            }
        }
    }

    int top() {
        if (top_val != -1) {
            return the_vect[top_val].first;
        }
        return 0;
    }

    int getMin() {
        if (top_val != -1) {
            return the_vect[top_val].second;
        }
        return 0;
    }
};

*/

int main(){
    cout << "Hey there!" << endl;
}