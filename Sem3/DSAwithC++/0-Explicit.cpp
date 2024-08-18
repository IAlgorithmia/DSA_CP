// THIS FILE IS CREATED FOR QUESTIONS NOT ON LEETCODE, VSC, CF OR CC (LIKE GFG, CN, ETC)

// Lucky Numbers 

// Lucky numbers are subset of integers. Rather than going into much theory, let us see the process of arriving at lucky numbers,
// Take the set of integers
// 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19,……
// First, delete every second number, we get following reduced set.
// 1, 3, 5, 7, 9, 11, 13, 15, 17, 19,…………
// Now, delete every third number, we get
// 1, 3, 7, 9, 13, 15, 19,….….
// Continue this process indefinitely……
// Any number that does NOT get deleted due to above process is called “lucky”.
// You are given a number N, you need to tell whether the number is lucky or not. If the number is lucky return 1 otherwise 0.

// Ans :

class Solution{
public:
    int i=2;
    bool isLucky(int n) {
        // imagine the indices to be natural numbers only, the actual left numbers are changing, you will observe that n in all cases represents the index of the number we started with, and checks for it
        if(n<i)return true;
        if(n%i==0)return false;
        n=n-n/i;
        i++;
        return isLucky(n);
    }
};

// Good String

// You are given a binary string s, (a string consisting only of 0-s and 1-s).
// You can perform two types of operations on s :
// delete one character from sThis operation costs 1 coin;
// swap any pair of characters in sThis operation is free (costs 0 coins).
// You can perform these operations any number of times and in any order.

// Let's name a string you've got after performing operations above as t
// The string t is good if for each i from 1 to |t| ti≠si (|t| is the length of the string t). 
// The empty string is always good. Note that you are comparing the resulting string t with the initial string s.

// What is the minimum total cost to make the string t good?

// Ans :

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        vector<int> zeros_indices;
        vector<int> ones_indices;
        string zeros_ones_one;
        cin >> zeros_ones_one;
        for (int j = 0; j < zeros_ones_one.size(); j++)
        {
            if (zeros_ones_one[j] == '0')
            {
                zeros_indices.push_back(j);
            }
            else
            {
                ones_indices.push_back(j);
            }
        }
        string zeros_ones_two;
        zeros_ones_two = zeros_ones_one;
        int min_size = (zeros_indices.size() > ones_indices.size()) ? ones_indices.size() : zeros_indices.size();

        for (int j = 0; j < min_size; j++)
        {
            zeros_ones_two[zeros_indices[j]] = '1';
            zeros_ones_two[ones_indices[j]] = '0';
        }
        int n = zeros_ones_one.size();
        int a = 0, b = 0, cost = 0;
        while ((a < n) && (b < n))
        {
            if (zeros_ones_two[b] == zeros_ones_one[a])
            {
                cost++;
                b++;
            }
            else
            {
                a++;
                b++;
            }
        }
        cout << cost << endl;
    }
}

// Rat in a Maze 

class Solution {
  public:
    //I shall call the function findPath for every cell that is 1 and has not been visited yet, if I find out 
    //that n - 1, n - 1 is reachable from that cell, I shall add the path to the result vector.
    vector<string> answer;
    void findPathUtil(vector<vector<int>> &mat, int i, int j, string path) {
        if (i < 0 || j < 0 || i >= mat.size() || j >= mat.size() || mat[i][j] == 0) {
            return;
            //if the cell is out of bounds or is not a valid cell, return
        }
        if (i == mat.size() - 1 && j == mat.size() - 1) {
            answer.push_back(path);
            return;
        }
        mat[i][j] = 0;
        findPathUtil(mat, i + 1, j, path + 'D');
        findPathUtil(mat, i - 1, j, path + 'U');
        findPathUtil(mat, i, j + 1, path + 'R');
        findPathUtil(mat, i, j - 1, path + 'L');
        mat[i][j] = 1;
    }
    vector<string> findPath(vector<vector<int>> &mat) {
        answer.clear();
        if (mat[0][0] == 0 || mat[mat.size() - 1][mat.size() - 1] == 0) {
            return answer;
        }
        findPathUtil(mat, 0, 0, "");
        return answer;
    }
};

// M Coloring Problem

// Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
    bool possible(int node, int m, int n, bool graph[101][101], unordered_map<int, int> &color){
        if(node == n){
            return true;
        }
        for(int i = 1; i <= m; i++){
            bool isSafe = true;
            for(int j = 0; j < n; j++){
                if(graph[node][j] && color[j] == i){
                    isSafe = false;
                    break;
                }
            }
            if(isSafe){
                color[node] = i;
                if(possible(node + 1, m, n, graph, color)){
                    return true;
                }
                color[node] = 0;
            }
        }
        return false;
    }
    bool graphColoring(bool graph[101][101], int m, int n) {
        //lets represent nodes using 0 based indexing and colors using 1 based indexing
        //lets always start from 0
        unordered_map<int, int> color;
        for(int i = 0; i < n; i++){
            color[i] = 0;
        }
        return possible(0, m, n, graph, color);
        //0 means no color assigned yet, 1 to m means color assigned
    }

//Nth root of a number is done simply using binary search and using the pow function to verify, which takes logn time

//Kth element of two sorted arrays 

class Solution {
    public long kthElement( int arr1[], int arr2[], int n, int m, int k) {
        return kthElementHelper(arr1, arr2, n, m, k, 0, 0);
        
    }
    public static int kthElementHelper(int[] arr1, int[] arr2, int m, int n, int k, int st1,
                                       int st2) {
        // In case we have reached end of array 1
        if (st1 == m) {

            return arr2[(st2 + k - 1)];
        }

        // In case we have reached end of array 2
        if (st2 == n) {

            return arr1[(st1 + k - 1)];

        }

        // Compare first elements of arrays and return
        if (k == 1) {

            return (arr1[(st1)] < arr2[(st2)]) ? arr1[(st1)] : arr2[(st2)];
        }

        int curr = k / 2;

        // Size of array 1 is less than k / 2
        if (curr - 1 >= m - st1) {
            // Last element of array 1 is not the kth element
            // We can directly return the (k - m)th
            // element in array 2
            if (arr1[(m - 1)] < arr2[(st2 + curr - 1)]) {
                return arr2[(st2 + (k - (m - st1) - 1))];
            } else {
                return kthElementHelper(arr1, arr2, m, n, k - curr, st1, st2 + curr);
            }
        }

        // Size of array 2 is less than k / 2
        if (curr - 1 >= n - st2) {
            if (arr2[(n - 1)] < arr1[(st1 + curr - 1)]) {
                return arr1[(st1 + (k - (n - st2) - 1))];
            } else {
                return kthElementHelper(arr1, arr2, m, n, k - curr, st1 + curr, st2);
            }
        } else {
            // Normal comparison, move starting index
            // of one array k / 2 to the right
            if (arr1[(curr + st1 - 1)] < arr2[(curr + st2 - 1)]) {
                return kthElementHelper(arr1, arr2, m, n, k - curr, st1 + curr, st2);
            } else {
                return kthElementHelper(arr1, arr2, m, n, k - curr, st1, st2 + curr);
            }
        }

    }


}


//Aggressive Cows

#include <bits/stdc++.h>
using namespace std;

/*
Explanation : 
*/

int main(){
    int t;
    cin >> t;
    while (t--){
        int n, c;
        cin >> n >> c;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) cin >> arr[i];
        sort(arr.begin(), arr.end());
        int low = arr[1] - arr[0];
        int high = arr[n - 1] - arr[0];
        for (int i = 1; i <= n - 2; i++) low = min(low, arr[i + 1] - arr[i]);
        int answer = INT_MIN;
        while (low <= high){
            int mid = (low + high) / 2;
            int cows = 1;
            //first cow placed at 0th position
            int last_pos = arr[0];
            for (int i = 1; i < n; i++){
                if (arr[i] - last_pos >= mid){
                    cows++;
                    last_pos = arr[i];
                }
            }
            if (cows >= c){
                answer = max(answer, mid);
                low = mid + 1;
            }
            else high = mid - 1;
        }
        cout << answer << endl;
    }
}

// Minimum Insertions at the beginning to make the string palindrome

vector<int> returnLPS(string sample_string){
    int len = 0, i = 1;
    vector<int> LPS;
    //LPS represents the longest proper prefix which is also a suffix for the string having first 'index' characters from the starting
    LPS.push_back(0);
    while (i < sample_string.size()){
        if (sample_string[i] == sample_string[len]){
            len++;
            LPS.push_back(len);
            i++;
        }
        else{
            if (len == 0){
                LPS.push_back(len);
                i++;
            }
            else{
                len = LPS[len - 1];
            }
        }
    }
    return LPS;
}
int Solution::solve(string A) {
    string new_string = A + "$";
    reverse(A.begin(), A.end());
    new_string += A;
    vector<int> the_vect = returnLPS(new_string);
    return (A.size() - the_vect[the_vect.size() - 1]);
}
