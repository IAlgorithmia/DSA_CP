#include <bits/stdc++.h>
using namespace std;

/*
Explanation : we need to convert s1 to s2, we are allowed three operations : 
insert, delete and replace
We need to find min number of operations

Beginning from last characters simplifies the recursive solution 
*/

int eDRecur(string &s1, string &s2, int m, int n){

    if (m == 0){
        return n; //first string empty means we need to insert all chars of second string hence n operations
    }
    if (n == 0){
        return m;
    }
    if (s1[m - 1] == s2[n - 1]){
        return eDRecur(s1, s2, m - 1, n - 1);
    }
    else{
        return 1 + min(eDRecur(s1, s2, m, n - 1), min(eDRecur(s1, s2, m - 1, n), eDRecur(s1, s2, m - 1, n - 1)));
    }
    //first we try insert, we insert the last element of s2 at s1, then since the last are same, we just call for m - 1, n - 1, for those strings, but since we added and subtracted one char from s1, then same m, and for s2 n - 1, then deletion then replacement
}

int eDIter(string &s1, string &s2, int m, int n){
    
    vector<vector<int>> memo(m + 1, vector<int> (n + 1, 0));
    for (int i = 0; i <= n; i++){
        memo[0][i] = i;
        //since when m is 0 then we return n
    }
    for (int i = 0; i <= m; i++){
        memo[i][0] = i;
        //since when n is 0 then we return m
    }
    for (int i = 1; i <= m; i++){
        for (int j = 1; j <= n; j++){
            if (s1[i - 1] == s2[j - 1]){
                memo[i][j] = memo[i - 1][j - 1];
            }
            else{
                memo[i][j] = 1 + min(memo[i - 1][j], min(memo[i - 1][j - 1], memo[i][j - 1]));
            }
        }
    }
    return memo[m][n];

}


int main(){
    cout << "Enter the two strings : " << endl;
    string s1, s2;
    cin >> s1 >> s2;
    cout << eDIter(s1, s2, s1.size(), s2.size()) << endl << eDRecur(s1, s2, s1.size(), s2.size()) << endl;
}