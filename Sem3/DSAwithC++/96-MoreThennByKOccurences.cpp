#include <bits/stdc++.h>
using namespace std;

/*
Explanation : This can be done very easily, using hashing, we discuss the case when n is very large and k is very small. Then storing all the elements in hashmap isnt optimal here we discuss a different approach.
*/

//This is an extention of fkin boyer moyer algo in majority element, here we have a more generalized form, there it was n / 2, here we have n / k
//To Prove : The total number of elements in our final answer will be <= k - 1 
//Proof : say we have k elements then k elements have occurrences more than n / k times, then k*(n/ k + 1) <= n (obvio), which is false hence proved
//Here too, by some fkin magic, we get the candidates through some fkin algo, then we just check for those if they actually re occurring that many times

void findOccurrences(vector<int> the_vector, int k){
    unordered_map<int, int> candidates; //of max size k - 1
    int n = the_vector.size();
    for (int i = 0; i < n; i++){
        if (candidates.find(the_vector[i]) != candidates.end()){
            candidates[the_vector[i]]++;
        }
        else if (candidates.size() < (k - 1)){
            candidates.insert({the_vector[i], 1});
        }
        else{
            for (auto x : candidates){
                candidates[x.first]--;
                if (x.second == 0){
                    candidates.erase(x.first);
                }
            }
        }
    }
    //Checking done
    for (auto z : candidates){
        int count = 0;
        for (auto x : the_vector){
            if (z.first == x){
                count ++;
            }
        }
        if (count > (n / k)){
            cout << z.first << endl;
        }
    }
}
int main(){
    cout << "Enter the array length" << endl;
    int n;
    cin >> n;
    cout << "Enter the elements" << endl;
    int elem;
    vector<int> my_vect;
    for (int i = 0; i < n; i++)
    {
        cin >> elem;
        my_vect.push_back(elem);
    }
    cout << "Enter the value of k" << endl;
    int k;
    cin >> k;
    findOccurrences(my_vect, k);
}