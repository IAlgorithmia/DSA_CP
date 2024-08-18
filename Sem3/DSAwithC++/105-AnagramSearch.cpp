#include <bits/stdc++.h>
using namespace std;

/*
Explanation : Two permutations of each other are called anagrams
*/

bool areSame(unordered_map<char, int> map_1, unordered_map<char, int> map_2){
    for (auto item : map_1){
        if (item.second != map_2[item.first]){
            return false;
        }
    }
    return true;
}

bool checkAnagram(string text, string substring){
    unordered_map<char, int> map_1;
    unordered_map<char, int> map_2;
    for (int i = 0; i < substring.size(); i++){
        map_1[text[i]]++;
        map_2[substring[i]]++;
    }
    for (int i = 0; i < (text.size() - substring.size()); i++){
        if (areSame(map_1, map_2)){
            return true;
        }
        else{
            if (!(--map_1[text[i]])){
                map_1.erase(text[i]);
            }
            map_1[text[i + substring.size()]]++;
        }
    }
    return false;
}

int main(){
    cout << "Enter the text string : " << endl;
    string sample_string_1;
    getline(cin, sample_string_1);
    cout << "Enter the substring string : " << endl;
    string sample_string_2;
    getline(cin, sample_string_2);
    cout << checkAnagram(sample_string_1, sample_string_2) << endl;
}