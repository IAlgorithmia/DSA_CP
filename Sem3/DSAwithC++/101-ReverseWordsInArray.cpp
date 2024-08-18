#include <bits/stdc++.h>
using namespace std;

/*
Explanation : We actually gotta reverse the order of the strings having spaces between them
*/

void reverseStringByIndices(string &sample, int low, int high){
    while (low < high){
        swap(sample[low], sample[high]);
        high--;
        low++;
    }
}

string reverseWords(string &sample){
    int start = 0;
    for (int i = 0; i < sample.size(); i++){
        if (sample[i] == ' '){
            reverseStringByIndices(sample, start, i - 1);
            //we can do reverse(sample.begin() + start, sample.begin() + i); as well after checking
            start = i + 1;
        }
    }
    reverseStringByIndices(sample, start, sample.size() - 1);
    reverse(sample.begin(), sample.end());
    return sample;
}

int main(){
    cout << "Enter the first string : " << endl;
    string sample_string;
    getline(cin, sample_string);
    cout << reverseWords(sample_string) << endl;
}