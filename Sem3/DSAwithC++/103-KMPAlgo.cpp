#include <bits/stdc++.h>
using namespace std;

/*
Explanation : LPS array means Longest Proper Prefix Suffix array. Preprocessing of pattern is done. 
KMP preprocesses the redundancies in the algo occurring due to repetetion of characters
*/

int LPSForSubstring(string sample_string){
    int len = sample_string.size();
    for (int i = len - 1; i > 0; i--){
        bool flag = true;
        for (int j = 0; j < i; j++){
            if (sample_string[j] != sample_string[len - i + j]){
                flag = false;
                break;
            }
        }
        if (flag == true){
            return len;
        }
    }
    return 0;
}

vector<int> makeLPSNaive(string sample_string){
    vector<int> answer;
    for (int i = 0; i < sample_string.size(); i++){
        answer.push_back(LPSForSubstring(sample_string.substr(0, i + 1)));
    }
    return answer;
    //we begin by consider the first element only, then the first two then first three and so on
}

//Below we have just deduced al algo see the vid for its derivation

vector<int> returnLPS(string sample_string){
    int len = 0, i = 1;
    vector<int> LPS;
    //LPS represents the longest proper prefix which is also a suffix for the string having first 'index' characters from the starting
    LPS.push_back(0);
    while (i < sample_string.size()){
        if (sample_string[i] == sample_string[len]){
            len++;
            LPS.push_back(len);
            i++;
        }
        else{
            if (len == 0){
                LPS.push_back(len);
                i++;
            }
            else{
                len = LPS[len - 1];
            }
        }
    }
    return LPS;
}

void KMPAlgo(string text, string pattern){
    int m = text.size();
    int n = pattern.size();
    vector<int> LPS = returnLPS(pattern);
    int i = 0, j = 0;
    while (i < n){
        if (pattern[j] == text[i]){
            i++;
            j++;
        }
        if (j == m){
            cout << (i - j) << endl;
            j = LPS[m - 1];
        }
        else if ((i < n) && (pattern[j] != text[i])){
            if (j == 0){
                i++;
            }
            else{
                j = LPS[j - 1];
            }
        }
    }
}

//Time complexity of the above is O(n)

int main(){
    cout << "Enter the text string : " << endl;
    string sample_string_1;
    getline(cin, sample_string_1);
    cout << "Enter the pattern string : " << endl;
    string sample_string_2;
    getline(cin, sample_string_2);
    cout << "The LPS array for pattern is : " << endl;
    vector<int> answer = returnLPS(sample_string_2);
    for (auto i : answer){
        cout << i << endl;
    }
    // cout << "KMP Output : " << endl;
    // KMPAlgo(sample_string_1, sample_string_2);
    // cout << endl;
}