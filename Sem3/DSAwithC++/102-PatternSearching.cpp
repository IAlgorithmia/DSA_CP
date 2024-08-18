#include <bits/stdc++.h>
using namespace std;

/*
Explanation : Many algos to solve this, a frequent prob in CS, 
Naive O((n - m + 1) * m), O(n) when patter's chars are distinct, No Preprocessing
Rabin Karp O((n - m + 1) * m) but better on average than naive, Preprocessing pattern
KMP O(n) time and O(m) aux space
Suffix Tree O(m) - Only for static text data
*/

//Naive to humein pata h hai

void improvedNaiveForDistinct(string text, string pattern){ //this has O(n) complexity
    int n = text.size(), m = pattern.size();
    for (int i = 0; i <= (n - m); ){ //Do nothing here, hum conditionally i ko change karenge
        int j;
        for (j = 0; j < m; j++){
            if (text[i + j] != pattern[j]){
                break;
            }
        }
        if (j == m){
            cout << i << " ";
        }
        if (j == 0){
            i++;
        }
        else{
            i += j; //I am skipping the entire failed/successful match because Im not going to find another start charracter in the string up until after j, because it is not in the string to be matched
        }
    }
}

//To understand how the above only works for distinct, text = ABCCAAABCDE and pattern = AAB
//I am

//Spurious hit in RabinKarp Algo = Hash values matched but the characters didn't, sliding window ki tarah chalana hash value of the current window, 
//this is called as Rolling Hash, simply using the sum of ascii values of characters lands us in trouble, so we use a different method, 
//we use an arbitrary variable d and we canculate the hash value of each string section as follows : 
//hash value = (ASCII of 1st) * (d^2) + (ASCII of 2nd) * (d^1) + (ASCII of 3rd) * (d^0) assuming the length of the pattern is 3, so we start from d^(m - 1) and go to d^(0)
//and to implement rolling hash in this, we do
// t(i + 1) = ((t(i) - (ASCII of 1st of t(i)) * (d^(m - 1))) * d) + (ASCII of newCharacter)

void RabinKarpAlgo(string text, string pattern){
    //sometimes the values of the hashFunctions can grow very large even for small strings, so we gotta do modulo to some prime number q which should be as large as possible to avoid spurious hits
    int hashValueOfPattern = 0, hashValueOfWindow = 0, d = 5, q = 23, m = pattern.size(), n = text.size(); //Choosing an arbitrary value of d
    int h = 1;
    for (int i = 1; i <= m - 1; i++){
        h = (h * d) % q;
    }
    //we have made h = pow(d, m - 1) % q
    for (int i = 0; i < m; i++){
        hashValueOfPattern = ((hashValueOfPattern * d) + pattern[i]) % q;
        hashValueOfWindow = ((hashValueOfWindow * d) + text[i]) % q;
    }
    //the above method of computation is known as horners rule
    bool flag;
    for (int i = 0; i <= (n - m); i++){
        if (hashValueOfWindow == hashValueOfPattern){
            flag = true;
            for (int j = 0; j < m; j++){
                if (text[i + j] != pattern[j]){
                    flag = false;
                }
            }
            if (flag){
                cout << i << " ";
            }
        }
        if (i < (n - m)){
            hashValueOfWindow = (d * (hashValueOfWindow - (text[i] * h)) + text[i + m]) % q; 
        }
        if (hashValueOfWindow < 0){
            hashValueOfWindow += q;
        }
    }
}
//Its worst case occurs when text = AAAAA and pattern = AAA, it is used practically when you have multiple patterns to be searched in a text

int main(){
    cout << "Enter the text string : " << endl;
    string sample_string_1;
    getline(cin, sample_string_1);
    cout << "Enter the pattern string (distinct if you wanna check improved naive one) : " << endl;
    string sample_string_2;
    getline(cin, sample_string_2);
    cout << endl << "Improve Naive Results : " << endl;
    improvedNaiveForDistinct(sample_string_1, sample_string_2);
    cout << endl << "Rabin Karp Results : " << endl;
    RabinKarpAlgo(sample_string_1, sample_string_2);
    cout << endl;
}