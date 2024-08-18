#include <bits/stdc++.h>
using namespace std;

/*
Explanation : 
Idea for recursive solution is that if the last characters are matching, then we return 1 + lcs(m - 1, n - 1)
else we call for max of m - 1, n and m, n - 1, ie, reduce the string size by 1 for both the strings and take the max
base case is when size becomes 0 we return 0

memoization is done on m X n matrix

tabulation uses the same logic but initially fills the table 

Variations of LCS :

Diff Utility - Difference utility, difference between files like git
Minimum INsertions and deletions to convert s1, m to s2, n then we need to do m - l deletions and n - l insertions

class Solution {
public:
    int minDistance(string word1, string word2) {
        string longer_string = word1.size() >= word2.size() ? word1 : word2;
        string shorter_string = word1.size() < word2.size() ? word1 : word2;
        int size1 = longer_string.size();
        int size2 = shorter_string.size();
        cout << longer_string << endl << shorter_string << endl;
        vector<vector<int>> dp(size1 + 1, vector<int> (size2 + 1, 0));
        for (int i = 1; i <= size1; i++){
            for (int j = 1; j <= size2; j++){
                if (longer_string[i - 1] == shorter_string[j - 1]){ //since i and j are lengths not indices
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else{
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        int max_len = dp[size1][size2];
        return (size1 + size2 - 2 * max_len);
    }
};

Finding out LCS : 

Backtracking to Build the LCS:
Starting from dp[m][n], we trace back through the table.
If characters match, they are part of the LCS, and we move diagonally.
If they don't match, we move in the direction of the larger value, either up or left.
Reversing the LCS:
The constructed LCS is in reverse order due to the backtracking process, so we reverse it before returning.

class Solution {
public:
    string shortestCommonSuperSequence(string str1, string str2) {

        string longer_string = (str1.size() >= str2.size()) ? str1 : str2;
        string shorter_string = (str1.size() < str2.size()) ? str1 : str2;

        int longer_size = longer_string.size();
        int shorter_size = shorter_string.size();

        vector<vector<int>> dp(longer_size + 1, vector<int>(shorter_size + 1, 0));

        for (int i = 1; i <= longer_size; i++){
            for (int j = 1; j <= shorter_size; j++){
                if (longer_string[i - 1] == shorter_string[j - 1]){
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else{
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        string LCSString = "";

        int i = longer_size, j = shorter_size;

        while (i > 0 && j > 0){
            if (longer_string[i - 1] == shorter_string[j - 1]){
                LCSString = longer_string[i - 1] + LCSString;
                i--;
                j--;
            }
            else{
                if (dp[i - 1][j] > dp[i][j - 1]){
                    LCSString = longer_string[i - 1] + LCSString;
                    i--;
                }
                else{
                    LCSString = shorter_string[j - 1] + LCSString;
                    j--;
                }
            }
        }
    }
};

Shortest Common SuperSequence - Construct the shortest string such that it contains both s1 and s2 as subsequences, we find l, then insert the remainings in order

Compute the LCS: As we've already done, compute the LCS of the two strings.
Construct the SCS String:
Use the LCS to guide the interleaving of word1 and word2.
Traverse through both strings, and whenever characters match the current LCS character, append the LCS character.
For non-LCS characters, append them as they appear in word1 or word2.

class Solution {
public:
    string shortestCommonSuperSequence(string str1, string str2) {
        int m = str1.size(), n = str2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        // Build the dp table for LCS
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (str1[i - 1] == str2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        // Construct the SCS from the LCS dp table
        string scs;
        int i = m, j = n;

        while (i > 0 && j > 0) {
            if (str1[i - 1] == str2[j - 1]) {
                scs.push_back(str1[i - 1]);
                --i;
                --j;
            } else if (dp[i - 1][j] > dp[i][j - 1]) {
                scs.push_back(str1[i - 1]);
                --i;
            } else {
                scs.push_back(str2[j - 1]);
                --j;
            }
        }

        while (i > 0) {
            scs.push_back(str1[i - 1]);
            --i;
        }
        while (j > 0) {
            scs.push_back(str2[j - 1]);
            --j;
        }

        reverse(scs.begin(), scs.end());
        return scs;
    }
};


Longest Palindromic Subsequence - we are given a string s1, we reverse it into s2, we find lcs 

class Solution {
public:
    int longestPalindromeSubseq(string s) {

        string original_string = s;
        
        reverse(s.begin(), s.end());
        string reversed_string = s;

        int len = s.size();

        vector<vector<int>> dp(len + 1, vector<int> (len + 1, 0));

        for (int i = 1; i <= len; i++){
            for (int j = 1; j <= len; j++){
                if (original_string[i - 1] == reversed_string[j - 1]){
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else{
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        
        return dp[len][len];
    }
};

Longest Repeating Subsequence - we are given a string s1, we create s2 = s1, we find lcs with a difference in code, when last two characters match we do 1 + thing, here we do that only if last two characters match and their indices in their respective strings are not the same

int LCSTabu(string &s1, string &s2, int m, int n){
    
    vector<vector<int>> memo(m + 1, vector<int> (n + 1, 0));

    for (int i = 1; i <= m; i++){
        for (int j = 1; j <= n; j++){
            if (s1[i - 1] == s2[j - 1] && i != j){ //i != j is the only difference
                memo[i][j] = 1 + memo[i - 1][j - 1];
            }
            else{
                memo[i][j] = max(memo[i - 1][j], memo[i][j - 1]);
            }
        }
    }
    
    return memo[m][n];
}

Printing LCS - In our memo matrix, we start from right most and bottom most cell, if the characters are matching we append the character at the beginning, then go to [i - 1][j - 1] (next cell on upper diagonal) then do the same. If characters are not matching we go to max of just above or just left, and we dont print the character. Done above though

Space Optimized version of DP - we use 2 X m or 2 X n matrix instead of larger one, we update the values, we just needed the previous row.

*/

//Memoization

vector<vector<int>> memo(500, vector<int>(500, -1)); //considering max str length 499

int LCSMemo(string &s1, string &s2, int m, int n){
    if (memo[m][n] != -1){
        return memo[m][n];
    }
    if (m == 0 || n == 0){
        memo[m][n] = 0;
    }
    else{
        if (s1[m - 1] == s2[n - 1]){
            memo[m][n] = 1 + LCSMemo(s1, s2, m - 1, n - 1);
        }
        else{
            memo[m][n] = max(LCSMemo(s1, s2, m, n - 1), LCSMemo(s1, s2, m - 1, n));
        }
    }
    return memo[m][n];
}

int LCSTabu(string &s1, string &s2, int m, int n){
    vector<vector<int>> memo(m + 1, vector<int> (n + 1, 0));
    
    //since when size is 0 of any substring, the lcs has to be 0
    //we fill 0 in the first row and first column, 0, 0 to 0, n and 0, 0 to m, 0
    //We took m + 1 and n + 1 size because we wanted the result as LCS of substrings of length m and n which are the actual strings, so + 1

    //0 already there

    //Now we fill the rest of the table

    for (int i = 1; i <= m; i++){
        for (int j = 1; j <= n; j++){
            if (s1[i - 1] == s2[j - 1] && i != j){ //i != j is the only difference
                memo[i][j] = 1 + memo[i - 1][j - 1];
            }
            else{
                memo[i][j] = max(memo[i - 1][j], memo[i][j - 1]);
            }
        }
    }
    return memo[m][n];

    /*
    When you are at memo[i][j], it corresponds to the comparison of the first i characters of s1 and the first j characters of s2.
    Therefore, the i-th character in the context of memo is actually the (i-1) index character in the context of s1.
    Similarly, the j-th character in the context of memo is the (j-1) index character in the context of s2.

    dp[i][j] represents the LCS 0 to i - 1 index of s1 and 0 to j - 1 index of s2
    Think in terms of sizes of strings, not the indices
    */

}

//Time complexity of both the solutions is O(m * n)


int main(){
    cout << "Enter two strings : " << endl;
    string s1, s2;
    cin >> s1 >> s2;
    cout << LCSMemo(s1, s2, s1.size(), s2.size()) << endl << LCSTabu(s1, s2, s1.size(), s2.size()) << endl;
}