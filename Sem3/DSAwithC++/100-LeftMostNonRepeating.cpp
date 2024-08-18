#include <bits/stdc++.h>
using namespace std;

/*
Explanation : we gotta return the index of the leftmost non repeating thing, vaise to we can do both the problems in O(n) time with n + n traversals, but the dudes crazy ass fk
*/

int leftMostRepeating(string sample){
    vector<int> visited(256, -1);
    int res = INT_MAX;
    for (int i = 0; i < sample.size(); i++){
        if (visited[sample[i]] == -1){
            visited[sample[i]] = i;
        }
        else{
            res = min(res, visited[sample[i]]);
        }
    }
    return (res == INT_MAX) ? -1 : res;
}

//better algo

int leftMostRepeating(string sample){
    vector<bool> visited(26, false);
    int res = -1;
    for (int i = sample.size() - 1; i >= 0; i--){
        if (visited[sample[i] - 'a']){
            res = i;
        }
        else{
            visited[sample[i] - 'a'] = true;
        }
    }
    return res;
}

int leftMostNonRepeating(string sample){
    vector<int> visited(256, -1);
    for (int i = 0; i < sample.size(); i++){
        if (visited[sample[i] - 'a'] == -1){
            visited[sample[i] - 'a'] = i;
        }
        else{
            visited[sample[i] - 'a'] = -2;
        }
    }
    //idhar bas yahi cheez hai ke if we use two options ie 0 and 1, and an element appears 3 times, we do 0 to 1, then 1 to 0, then we dont know whether it has already appeared or not, thats why we needed three variables
    int res = INT_MAX;
    for (int i = 0; i < 26; i++){
        if (visited[i] >= 0) res = min(res, visited[i]);
    }
    return (res == INT_MAX ? -1 : res);
}

int main(){
    cout << "Enter the first string : " << endl;
    string sample_string;
    cin >> sample_string;
    cout << leftMostRepeating(sample_string) << endl << leftMostNonRepeating(sample_string) << endl;
}