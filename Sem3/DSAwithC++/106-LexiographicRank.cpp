#include <bits/stdc++.h>
using namespace std;

/*
Explanation : The key idea is that rank of string = number of lexiographically smaller strings + 1, and vo hum nikalenge by counting the number of smaller letters that occur after the current letter and getting all the possible combinations
Now the trick here is that we want to get the factorial of remaining length that we gotta multiply the number of lesser alphabets with in O(1) time and also the number of lexiographically smaller alphabets that are on the right side of the current letter
*/

//Assuming the string doesnt have duplicate characters, and the characters are all UPPERCASE

int lexiographicRank(string sample_string){
    int rank = 0;
    int n = sample_string.size();
    for (int i = n - 1; i >= 1; i--){
        n = n * i;
    }
    //now we have n factorial
    vector<int> characters(26, 0);
    for (int i = 0; i < sample_string.size(); i++){
        characters[sample_string[i] - 'A']++;
    }
    for (int i = 1; i < 26; i++){
        characters[i] += characters[i - 1];
    }
    for (int i = 0; i < sample_string.size() - 1; i++){
        int divide_by = n / (sample_string.size() - i);
        rank += (characters[sample_string[i] - 'A'] - 1) * divide_by;
        for (int j = (sample_string[i] - 'A'); j < 26; j++){
            characters[j]--;
        }
    }
    return (rank + 1);
}

//Above has O(n) complexity

int main(){
    cout << "Enter the string with only uppercase characters : " << endl;
    string sample_string;
    getline(cin, sample_string);
    cout << lexiographicRank(sample_string) << endl;
}