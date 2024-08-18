#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxScore(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        int max_val = INT_MIN;
        for (int i = n - 1; i >= 0; i--){
            for (int j = n - 1; j >= 0; j--){
                int value = 0;
                if (j + 1 < n){
                    value = max(grid[i][j + 1] - grid[i][j], grid[i][j + 1] - grid[i][j] + dp[i][j + 1]);
                }
                if (i + 1 < n){
                    value = max(grid[i + 1][j] - grid[i][j], grid[i + 1][j] - grid[i][j] + dp[i + 1][j]);
                }
                dp[i][j] = value;
                max_val = max(max_val, value);
            }
        }
        return max_val;
    }
};
/*
Explanation : 
This data structure is useful for implementing dictionaries for performing search insert delete prefix search and lexicographical ordering of words
search takes theta(word-length) in worst case and in hashing it is on average that
same for insert and delete
prefix search and lexicographical ordering is not supported in hashing, but take Theta(prefix-len + output-len) and Theta(output-len) time respectively

Trie - 

struct TrieNode{
    TrieNode *child[26]; //we consider only small case alphabets
    bool isEnd;
    TrieNode(){
        isEnd = false;
        for (int i = 0; i < 26; i++){
            child[i] = NULL;
        }
    }
}

void insert(string &key){
    TrieNode* curr = root;
    for (int i = 0; i < key.size(); i++){
        int index = key[i] - 'a';
        if (curr->child[index] == NULL){
            curr->child[index] = new TrieNode();
        }
        curr = curr->child[index];
    }
    curr->isEnd = true;
}

above is theta(n)

bool search(string &key){
    TrieNode* curr = root;
    for (int i = 0; i < key.size(); i++){
        int index = key[i] - 'a';
        if (curr->child[index] == NULL){
            return false;
        }
        curr = curr->child[index];
    }
    return curr->isEnd;
}

above is O(n)

TrieNode* delKey(TrieNode* root, string &key, int i){
    if (root == NULL){
        return NULL;
    }

    if (i == key.size()){
        root->isEnd = false;
        if (isEmpty(root) == true){
            delete(root);
            root = NULL;
        }
        return root;
    }
    int index = key[i] - 'a';
    root->child[index] = delKey(root->child[index], key, i + 1);
    if (isEmpty(root) && root->isEnd == false){ // not itself an end and no children
        delete(root);
        root = NULL;
    }
    return root;
}

bool isEmpty(TrieNode* root){
    for (int i = 0; i < 26; i++){
        if (root->child[i] != NULL){
            return false;
        }
    }
    return true;
}

Count distinct Rows in a binary matrix : 

vector<vector<bool>> mat (m, vector<int> (n));

struct TrieNode {
    TrieNode* child[2];
    TrieNode(){
        child[0] = NULL;
        child[1] = NULL;
    }
}

bool insert(TrieNode* root, int row){
    TrieNode* curr = root;
    bool flag = false;
    for (int i = 0; i < N; i++){
        int index = mat[row][i];
        if (curr->child[index] == NULL){
            TrieNode* node =  new TrieNode();
            curr->child[index] = node;
            flag = true;
        }
        curr = curr->child[index];
    }
    return flag;
}

int countDist(){
    TrieNode* root = new TrieNode();
    int res = 0;
    for (int i = 0; i < M; i++){
        if (insert(root, i) == true){
            res++;
        }
    }
    return res;
}

Complexity  = O(n)

*/

int main(){
    cout << "Hey there!" << endl;
}