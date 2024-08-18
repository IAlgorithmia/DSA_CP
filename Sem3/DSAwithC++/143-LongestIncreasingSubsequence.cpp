#include <bits/stdc++.h>
using namespace std;

/*
Explanation : 

For each element we see all the elements behind it, for all the ones smaller than the current element, see their LIS, choose the maximum one, add 1 to it, then assign it to the current LIS
For the answer, we see all the maximum LIS for all elements
If no smaller element found, current LIS becomes 1

In some problems we cant have a recursive solution then the DP one we gotta directly think of that dont be afraid of that
We gotta solve the problem in such a way that we encounter overlapping subproblems

We create an LIS vector which contains values as : at index i, the LIS that ends with array[i] element, it has to end with that
We go to the left of the element and for each smaller element we add 1, and maintain the maximum result among the values and assign the maximum to that elements position in the LIS vector
If there is no smaller then put 1

Variations of LIS : 

Minimum deletions to make an array sorted : total length - LIS



Maximum sum increasing subsequence : Out of all increasing subsequences find the one with max sum

Code : minor changes to original dp LIS code

int LISdp(vector<int> the_vector){
    vector<int> LISdp(the_vector.size() + 1);
    for (int i = 0; i < the_vector.size(); i++){
    LIS[i] = the_vector[i]; // each element is initially equal to itself
        for (int j = 0; j < i; j++){
            if (the_vector[j] < the_vector[i]){
                LISdp[i] = max(LISdp[i], LISdp[j] + the_vector[i]); //we can also add LISdp[i] since it is the same
            }
        }
    }
    int res = LISdp[0];
    for (int i = 1; i < LISdp.size(); i++){
        res = max(res, LISdp[i]);
    }
    return res;
}

Max Length Bitonic Sequence : Bitonic subsequence is first increasing then decreasing, decreasing/increasing part can be empty, that is valid too

We need to find longest increasing subsequence ending with the element and longest decreasing subsequence starting from that element, 
first we have solved, for second we just need to traverse the array in the reverse order and use LIS, in actuality we will get LDS
then in the end we have to find the maximum value of lis[i] + lds[i] - 1 in the entire array

code try : 

Further we can modify the binary search solution for DP to solve the above problem, 
try code : 

Building Bridges : 
We are given sets of two cities, no two bridges should cross each other, we need to build the maximum number of bridges
We first sort the vector of sets according to the first value in the pair
If the first value is the same then we consider the second value
Then we find LIS considering the second values

Longest Chain of Pairs : 
First value in each pair is smaller than the second, we need to find longest chain (a, b) (c, d), then a < b is already there, and b < c should be there
WE first sort the elements according to the first element
We need to change the condition to : arr[i].first < arr[j].second, then only we consider the ith element in the LIS formed by jth element

The above shows dp solution, we can also modify the binary search method

Also this is just a greedy problem, we can sort the elements according to the second element ie finish times, and then use activity selection problem 



*/

int LISdp(vector<int> the_vector){
    vector<int> LISdp(the_vector.size() + 1, 1);
    // LISdp[0] = 1 obviously and by default if we dont find smaller elemn the value has to be 1 so default 1 chosen
    for (int i = 1; i < the_vector.size(); i++){
        for (int j = 0; j < i; j++){
            if (the_vector[j] < the_vector[i]){
                LISdp[i] = max(LISdp[i], LISdp[j] + 1);
                //jis bhi pichle subsequence ko continue karke mujhe max value mil rahi hai
                //I choose that 
            }
        }
    }
    int res = LISdp[0];
    for (int i = 1; i < LISdp.size(); i++){
        res = max(res, LISdp[i]);
    }
    return res;
}

// The above solution is O(n square), the above is dp solution, the below is BST solution

//We can also solve the problem using binary search and an aux array

int ceilIdx(vector<int> the_vect, int l, int r, int x){
    while (l < r){
        int m = (l + r) / 2;
        if (the_vect[m] <= x){
            l = m + 1;
        }
        else{
            r = m;
        }
    }
    return r;
}

int LISbs(vector<int> the_vect){

    //we store the minimum possible tail value for every LIS length
    //tail[i] = minimum possible tail value for LIS length i + 1
    //whenever we encounter a greater element than the last inserted element, we append that element to the end 
    //if the element is smaller, we find the ceil of that element in the current tail array and since it is sorted we use binary search and replace the ceil with that element
    //in the end the length of the tail array is the answer

    vector<int> tail;

    tail.push_back(the_vect[0]);
    for (int i = 1; i < the_vect.size(); i++){
        if (the_vect[i] > tail[tail.size() - 1]){
            tail.push_back(the_vect[i]);
        }
        else{
            int r = ceilIdx(tail, 0, tail.size() - 1, the_vect[i]);
            tail[r] = the_vect[i];
        }
    }
    return tail.size();
}

int main(){
    cout << "Enter the number of elements in the array : " << endl;
    int n;
    cin >> n;
    cout << "Enter the elements : " << endl;
    vector<int> the_vector;
    for (int i = 0; i < n; i++){
        int elem;
        cin >> elem;
        the_vector.push_back(elem);
    }
    cout << LISdp(the_vector) << endl << LISbs(the_vector) << endl;
}