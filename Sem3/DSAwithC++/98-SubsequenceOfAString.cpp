#include <bits/stdc++.h>
using namespace std;

/*
Explanation : Substring means continuous characters, whereas subsequence means just occurring in the same order in the main string
*/

/*
bool checkSubsequence(const string &parent_string, const string &child_string, int n, int m){
    //n and m will initially be passed as lengths of the strings, so we start comparing from the back
    if (m == 0){
        return true;
    }
    //m agar 0 hogya you need not go ahead, thats why checking before n == 0 
    if (n == 0){
        return false;
    }
    //means m 0 hua nahi but n zero hogya
    if (parent_string[n - 1] == child_string[m - 1]){
        return checkSubsequence(parent_string, child_string, n - 1, m - 1);
    }
    else{
        return checkSubsequence(parent_string, child_string, n - 1, m);
    }
}
*/

bool checkSubsequence(string parent_string, string child_string){
    int j = 0;
    if (child_string.size() > parent_string.size()){
        return 0;
    }
    for (int i = 0; (i < parent_string.size()) && (j < child_string.size()); i++){
        if (parent_string[i] == child_string[j]){
            j++;
        }
    }
    return (j == child_string.size());
}

int main(){
    cout << "Enter the parent string : " << endl;
    string sample_string1;
    cin >> sample_string1;
    cout << "Enter the child string : " << endl;
    string sample_string2;
    cin >> sample_string2;
    cout << checkSubsequence(sample_string1, sample_string2) << endl;
}