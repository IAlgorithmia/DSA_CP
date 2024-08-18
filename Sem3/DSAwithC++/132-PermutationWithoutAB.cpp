#include <bits/stdc++.h>
using namespace std;

/*
Explanation : strings mein find function bhi hota hai, str.find("AB") == string::npos returned if not found
print karte time ye bhi check kar sakte hain, but backtracking is more optimal
*/

bool isSafe(string str, int l, int i, int r){

    if (l >= 1 && str[l - 1] == 'A' && str[i] == 'B'){
        return false;
    }

    // This condition is explicitly required for
    // cases when last two characters are "BA". We
    // do not want them to swapped and become "AB"
    // were it not the last, it woulve been checked before but now in our coed its just gonna get printed, so we check that here
    if (r == l + 1 && str[i] == 'A' && str[l] == 'B' || r == l + 1 && l == i && str[r] == 'B' && str[l] == 'A'){
        return false;
    }
    return true;

}

void permute(string str, int l, int r){
    if (l == r){
        cout << str << endl;
        return;
    }
    for (int i = l; i <= r; i++){
        if (isSafe(str, l, i, r)){
            swap(str[i], str[l]);
            permute(str, l + 1, r);
            swap(str[i], str[l]);
        }
    }
}

int main(){
    cout << "Hey there!" << endl;
    permute("ABC", 0, 2);
}