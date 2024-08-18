#include <bits/stdc++.h>
using namespace std;

/*
Explanation : 
*/

int lengthOfLongestSubstring(string s) {
    int start = 0, end = 0, len = INT_MIN;
    unordered_set<char> distinctChars;
    while (end < (s.size())){
        if (distinctChars.find(s[end]) == distinctChars.end()){
            distinctChars.insert(s[end]);   
            end++;
        }
        else{
            len = max(len, (end - start));
            distinctChars.erase(s[start]);
            start++;
        }
    }
    len = max(len, (end - start));
    return len == INT_MIN ? 0 : len;
}

//above is using the unordered_map
//below is gfg method

int longestDistinct(string str) {
    int n = str.length(), res = 0;
    vector<int> prev(256, -1); // Initialize vector to store last occurrence of each character
    int i = 0; // Initialize starting index of current substring

    for (int j = 0; j < n; j++) {
        // Update starting index of current substring if character str[j] was seen before
        i = max(i, prev[str[j]] + 1);
        
        // Calculate length of current substring
        int maxEnd = j - i + 1;
        
        // Update result with maximum length found so far
        res = max(res, maxEnd);
        
        // Update last occurrence of character str[j]
        prev[str[j]] = j;
    }

    // Return the length of the longest substring without repeating characters
    return res;
}


int main(){
    cout << "Enter the string with only uppercase characters : " << endl;
    string sample_string;
    getline(cin, sample_string);
    cout << longestSubstringWithDistinct(sample_string) << endl;
}