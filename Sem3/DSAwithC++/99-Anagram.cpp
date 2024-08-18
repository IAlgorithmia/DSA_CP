#include <bits/stdc++.h>
using namespace std;

/*
Explanation : Although this can be done using hashmaps also, we do it the classical way
*/

bool checkAnagram(string sample1, string sample2){
    vector<int> charFreq(26, 0);
    if (sample1.size() != sample2.size()){
        return false;
    }
    for (int i = 0; i < sample1.size(); i++){
        charFreq[sample1[i] - 'a']++;
        charFreq[sample2[i] - 'a']--; //Assuming both are lowercase
    }
    for (int i = 0; i < 26; i++){
        if (charFreq[i] != 0){
            return false;
        }
    }
    return true;
}

int main(){
    cout << "Enter the first string : " << endl;
    string sample_string1;
    cin >> sample_string1;
    cout << "Enter the second string : " << endl;
    string sample_string2;
    cin >> sample_string2;
    cout << checkSubsequence(sample_string1, sample_string2) << endl;
}