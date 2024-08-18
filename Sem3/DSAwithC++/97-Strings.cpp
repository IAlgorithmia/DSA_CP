#include <bits/stdc++.h>
using namespace std;

/*
Explanation : strings have small set of characters, in contrast to arrays. ASCII has 128 characters (C/C++) and UTF-16 has ASCII and other languages too. Char is 1 byte
If we do char x = 'a', then cout << (int)x << we get 97

Defining strings : 

C style : 
char str[] = "gfg" //or equivalently {'g', 'f', 'g', '/0'}, using double quotes automatically adds the /0, size of str will be 4 here, if we dont put the /0 in the {} method, then we shall get some kind of unwanted behaviour
Here if we do str[6] then give only 3, then first 3 will be filled and others will be assigned /0, size 

Functions : 
strlen(str), strcmp(s1, s2) gives +ve val is first greater, 0 if equal, -ve if lesser, strcpy(s1, s2)

char str[5]
str = "gfg"
the above will generate since str is an address designed to point to a character array, but assignment of "gfg" is also returning an address, and we cant assign one address to another address, we instead do, strcpy(str, "gfg")

C++ style : 
string str;
str = "meow" is okay here
we use c_str to convert cpp string to c string

String is a class in CPP

Functions : 
str.substr(1, 3)
str.find("eek") returns index of first occurrence, whe not found it returns special type string::npos
cin >> str karte hue if we write vaibhav sharma, we only get vaibhav in the storage since space aagya beach mein, to prevent that we use getline(cin, str, 'a'), third parameter is optional, if encountered will stop there, by default its the newline character

Traversal : 

string str = "blablabla"
Method 1
for (int i = 0; i < str.size(); i++){
    cout << str[i];
}
Method 2
for (char x : str){
    cout << x;
}

reverse(v.begin(), v.end()) works for both vectors and strings

string s = "heu"
string v = s

this method creates a deep copy for the new string, this works for both strings and vectors
== overloads the string class

Z Algorithm : 

https://www.youtube.com/watch?v=CpZh4eF8QBw&t=803s

https://personal.utdallas.edu/~besp/demo/John2010/z-algorithm.htm

https://www.geeksforgeeks.org/z-algorithm-linear-time-pattern-searching-algorithm/

*/

//Below we solve a simple problem showcasing the conversion from char to int effortlessly

void printFreqOfChars(string s){
    vector<int> char_freq(26, 0);
    for (int i = 0; i < s.size(); i++){
        char_freq[s[i] - 'a']++; //This is the trick
    }
    for (int i = 0; i < 26; i++){
        if (char_freq[i] != 0) cout << (char)('a' + i) << " appears " << char_freq[i] << " times." << endl;
    }
}

int main(){
    cout << "Enter a string : " << endl;
    string sample_string;
    cin >> sample_string;
    printFreqOfChars(sample_string);
}