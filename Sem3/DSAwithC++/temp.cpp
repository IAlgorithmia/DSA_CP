#include <bits/stdc++.h>
using namespace std;

bool func(string &str, unordered_set<char> s, int index, int prev_start){

    if (prev_start >= str.size() || index >= str.size()){
        return false;
    }

    if (index == str.size() && prev_start != 0){
        return true;
    }
    else{
        return false;
    }
    
    string sub = str.substr(prev_start, index - prev_start + 1);
    // make the cut
    bool possible = false;
    if (s.find(sub[sub.size() - 1]) == s.end()){
        //I can make the cut here
        //choose to make the cut
        s.insert(sub[0]);
        possible = possible || func(str, s, index + 1, index + 1);
        s.erase(sub[0]);
    }
    //dont make the cut
    possible = possible || func(str, s, index + 1, prev_start);
    return possible;
}

int main() {

    int t;
    cin >> t;
    while (t--){
        string str;
        cin >> str;
        unordered_set<char> s;
        bool res = func(str, s, 0, 0);
        if (res){
            cout << "Yes" << endl;
        }
        else{
            cout << "No" << endl;
        }
    }
    
}