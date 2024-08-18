#include <bits/stdc++.h>
using namespace std;

/*
Explanation : Even in this problem Given an array of integers A and an integer B.

Find the total number of subarrays having bitwise XOR of all elements equals to B.

This is because say abhi tak ke elements ka xor mere pass h, agar mai us cheez ka or kisi purane vale se kardu to mujhe beech ke subarray ka xor mil jayega 
and if that xor is equal to B then we have found a subarray. Same cheez hi h dude
*/

int maxLength(vector<int> A, int B){
    int curr_xor = 0;
    unordered_map<int, int> xor_ind;
    int count = 0;
    for (int i = 0; i < A.size(); i++){
        curr_xor = curr_xor ^ A[i];
        if (curr_xor == B){
            cout << "1 Current index : " << i << endl;
            count++;
        }
        if (xor_ind.find(B ^ curr_xor) != xor_ind.end()){
            cout << "2 Current index : " << i << endl;
            count += xor_ind[B ^ curr_xor];
        }
        xor_ind[curr_xor]++;
    }
    return count;
}

int main(){
    cout << "Enter n and elements and B : " << endl;
    int n;
    cin >> n;
    vector<int> A(n);
    for(int i = 0; i < n; i++){
        cin >> A[i];
    }
    int B;
    cin >> B;
    cout << maxLength(A, B) << endl;
    return 0;
}