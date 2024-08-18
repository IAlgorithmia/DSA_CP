#include <bits/stdc++.h>
using namespace std;

/*
Explanation : To check rotation just double the original string, and search the second string in it, if found then is there, else no
*/

bool areRotations(string sample_string_1, string sample_string_2){
    if (sample_string_1.size() != sample_string_2.size()){
        return false;
    }
    else{
        return ((sample_string_1 + sample_string_1).find(sample_string_2) == string::npos ? false : true);
        //find is the standard library function which returns index of the first occurrence of the substring else it returns string::npos, string::npos means end of string
    }
}

int main(){
    cout << "Enter the first string : " << endl;
    string sample_string_1;
    getline(cin, sample_string_1);
    cout << "Enter the second string : " << endl;
    string sample_string_2;
    getline(cin, sample_string_2);
    cout << areRotations(sample_string_1, sample_string_2) << endl;
}