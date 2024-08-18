#include <bits/stdc++.h>
using namespace std;

/*
Explanation : Useful when the size of array is fixed and a large number os queries : 

Range Query : O(log n) typically, like getSum
Update Query : O(log n) typically

Preprocessing : O(n) time and aux space

For getSum we can do it simply, in O(n) time by just summing
We can use prefix sum to get in O(1) but then prefix sum has to be changed wholly when an element is updated, making update O(n)

Segment Trees are similar to Heap data structure, represented by an array, but the difference is that segment trees need not be complete binary trees, but to use the relations of left right and parent, we introduce some dummy nodes that are never going to be accessed in the array

Let n be the size of the vector
if n is a power of 2, then 2*n - 1 total space needed
else, 2x - 1 where x is the smallest power of 2 greater than n

if n is 5 then x is 8
if n is 17 then x is 32

For a safe side we can always make an array of size 4n

Constructing Segment Tree

int tree[4n];
constructST(0, n - 1, 0); //initial call

tree ke sath humesha si aayega uske andar square brackets mein

int constructST(ss, se, si){
// segment start = 0 initially
// segment end = n - 1 initially
// segment index = 0 to n - 1 sum should be at 0 index in the final tree initially, so 0
    if (ss == se){
        tree[si] = arr[ss];
        return arr[ss];
    }
    int mid = (ss + se) / 2;
    tree[si] = constructST(ss, mid, 2*si + 1) + constructST(mid + 1, se, 2*si + 2);
    //recursive calls for left and right subtree
    return tree[si];
}

Overall time complex : O(n)

Range Query in Segment Tree

getSumRec(qs, qe, ss, se, si){
// qs and qe are inputs
// ss (0 initially) and se (n - 1 initially) and si (initially 0) are of current node

    if (se < qs || ss > qe){
        return 0;
    }
 class SGT {
public : 
    vector<int> tree;

    SGT(int n){
        tree.resize(4 * n + 1);
    }

    int construct(int ss, int se, int si, vector<int> &arr){
        if (ss == se){
            tree[si] = arr[ss];
            return tree[si];
        }
        int mid = (ss + se) / 2;
        tree[si] = construct(ss, mid, 2 * si + 1, arr) + construct(mid + 1, se, 2 * si + 2, arr);
        return tree[si];
    }

    int getSum(int qs, int qe, int ss, int se, int si){
        if (qs > se || qe < ss){
            return 0;
        }
        else if (qs >= ss && qe <= se){
            return tree[si];
        }
        int mid = (ss + se) / 2;
        return (getSum(qs, qe, ss, mid, 2 * si + 1) + getSum(qs, qe, mid + 1, se, 2 * si + 2));
    }

    void update(int ss, int se, int i, int si, int diff){
        if (i > se || i < ss){
            return;
        }
        tree[si] += diff;
        if (se > ss){
            int mid = (ss + se) / 2;
            update(ss, mid, i, 2 * si + 1, diff);
            update(mid + 1, se, i, 2 * si + 2, diff);
        }
    }
};

/*
void update(int ss, int se, int i, int si, int diff) {
        if (i < ss || i > se) {
            return;
        }
        tree[si] += diff;
        if (ss != se) {
            int mid = (ss + se) / 2;
            update(ss, mid, i, 2 * si + 1, diff);
            update(mid + 1, se, i, 2 * si + 2, diff);
        }
    }
*/

class Solution {
public:
    vector<int> countOfPeaks(vector<int>& nums, vector<vector<int>>& queries) {
        // Range query / Update query == Segment Tree is all you need always remember

        int n = nums.size();
        vector<int> peak(n, 0);

        for (int i = 1; i < n - 1; i++){
            if (nums[i] > nums[i - 1] && nums[i] > nums[i + 1]){
                peak[i] = 1;
            }
        }

        SGT st(n);
        st.construct(0, n - 1, 0, peak);

        vector<int> ans;

        for (int i = 0; i < queries.size(); i++){
            int type = queries[i][0];

            if (type == 1){
                int left = queries[i][1];
                int right = queries[i][2];

                if (left == right){
                    ans.push_back(0);
                    continue;
                }

                int counted_extra = 0; 
                //since we dont want left and right to be inclusive 
                // but in SGt they are

                if (peak[left] == 1) counted_extra++;
                if (peak[right] == 1) counted_extra++;

                int res = st.getSum(left, right, 0, n - 1, 0);
                ans.push_back(res - counted_extra);
            }
            else{
                int index = queries[i][1];
                int value = queries[i][2];

                nums[index] = value;

                //now that index value is changed, the peak-ability of index, index + 1 and index - 1 has to be checked


                //checking index
                if (index - 1 >= 0 && index + 1 < n){
                    if (nums[index] > nums[index - 1] && nums[index] > nums[index + 1]){
                        int diff = peak[index];
                        peak[index] = 1;
                        diff = peak[index] - diff; //final - initial = diff
                        if (diff){
                            st.update(0, n - 1, index, 0, diff);
                        }
                    }
                    else{
                        int diff = peak[index];
                        peak[index] = 0;
                        diff = peak[index] - diff; //final - initial = diff
                        if (diff){
                            st.update(0, n - 1, index, 0, diff);
                        }
                    }
                }

                //checking index - 1
                if (index - 2 >= 0 && index < n){
                    if (nums[index - 1] > nums[index - 2] && nums[index - 1] > nums[index]){
                        int diff = peak[index - 1];
                        peak[index - 1] = 1;
                        diff = peak[index - 1] - diff; //final - initial = diff
                        if (diff){
                            st.update(0, n - 1, index - 1, 0, diff);
                        }
                    }
                    else{
                        int diff = peak[index - 1];
                        peak[index - 1] = 0;
                        diff = peak[index - 1] - diff; //final - initial = diff
                        if (diff){
                            st.update(0, n - 1, index - 1, 0, diff);
                        }
                    }
                }

                if (index >= 0 && index + 2 < n){
                    if (nums[index + 1] > nums[index] && nums[index + 1] > nums[index + 2]){
                        int diff = peak[index + 1];
                        peak[index + 1] = 1;
                        diff = peak[index + 1] - diff; //final - initial = diff
                        if (diff){
                            st.update(0, n - 1, index + 1, 0, diff);
                        }
                    }
                    else{
                        int diff = peak[index + 1];
 class SGT {
public : 
    vector<int> tree;

    SGT(int n){
        tree.resize(4 * n + 1);
    }

    int construct(int ss, int se, int si, vector<int> &arr){
        if (ss == se){
            tree[si] = arr[ss];
            return tree[si];
        }
        int mid = (ss + se) / 2;
        tree[si] = construct(ss, mid, 2 * si + 1, arr) + construct(mid + 1, se, 2 * si + 2, arr);
        return tree[si];
    }

    int getSum(int qs, int qe, int ss, int se, int si){
        if (qs > se || qe < ss){
            return 0;
        }
        else if (qs >= ss && qe <= se){
            return tree[si];
        }
        int mid = (ss + se) / 2;
        return (getSum(qs, qe, ss, mid, 2 * si + 1) + getSum(qs, qe, mid + 1, se, 2 * si + 2));
    }

    void update(int ss, int se, int i, int si, int diff){
        if (i > se || i < ss){
            return;
        }
        tree[si] += diff;
        if (se > ss){
            int mid = (ss + se) / 2;
            update(ss, mid, i, 2 * si + 1, diff);
            update(mid + 1, se, i, 2 * si + 2, diff);
        }
    }
};

/*
void update(int ss, int se, int i, int si, int diff) {
        if (i < ss || i > se) {
            return;
        }
        tree[si] += diff;
        if (ss != se) {
            int mid = (ss + se) / 2;
            update(ss, mid, i, 2 * si + 1, diff);
            update(mid + 1, se, i, 2 * si + 2, diff);
        }
    }
*/

class Solution {
public:
    vector<int> countOfPeaks(vector<int>& nums, vector<vector<int>>& queries) {
        // Range query / Update query == Segment Tree is all you need always remember

        int n = nums.size();
        vector<int> peak(n, 0);

        for (int i = 1; i < n - 1; i++){
            if (nums[i] > nums[i - 1] && nums[i] > nums[i + 1]){
                peak[i] = 1;
            }
        }

        SGT st(n);
        st.construct(0, n - 1, 0, peak);

        vector<int> ans;

        for (int i = 0; i < queries.size(); i++){
            int type = queries[i][0];

            if (type == 1){
                int left = queries[i][1];
                int right = queries[i][2];

                if (left == right){
                    ans.push_back(0);
                    continue;
                }

                int counted_extra = 0; 
                //since we dont want left and right to be inclusive 
                // but in SGt they are

                if (peak[left] == 1) counted_extra++;
                if (peak[right] == 1) counted_extra++;

                int res = st.getSum(left, right, 0, n - 1, 0);
                ans.push_back(res - counted_extra);
            }
            else{
                int index = queries[i][1];
                int value = queries[i][2];

                nums[index] = value;

                //now that index value is changed, the peak-ability of index, index + 1 and index - 1 has to be checked


                //checking index
                if (index - 1 >= 0 && index + 1 < n){
                    if (nums[index] > nums[index - 1] && nums[index] > nums[index + 1]){
                        int diff = peak[index];
                        peak[index] = 1;
                        diff = peak[index] - diff; //final - initial = diff
                        if (diff){
                            st.update(0, n - 1, index, 0, diff);
                        }
                    }
                    else{
                        int diff = peak[index];
                        peak[index] = 0;
                        diff = peak[index] - diff; //final - initial = diff
                        if (diff){
                            st.update(0, n - 1, index, 0, diff);
                        }
                    }
                }

                //checking index - 1
                if (index - 2 >= 0 && index < n){
                    if (nums[index - 1] > nums[index - 2] && nums[index - 1] > nums[index]){
                        int diff = peak[index - 1];
                        peak[index - 1] = 1;
                        diff = peak[index - 1] - diff; //final - initial = diff
                        if (diff){
                            st.update(0, n - 1, index - 1, 0, diff);
                        }
                    }
                    else{
                        int diff = peak[index - 1];
                        peak[index - 1] = 0;
                        diff = peak[index - 1] - diff; //final - initial = diff
                        if (diff){
                            st.update(0, n - 1, index - 1, 0, diff);
                        }
                    }
                }

                if (index >= 0 && index + 2 < n){
                    if (nums[index + 1] > nums[index] && nums[index + 1] > nums[index + 2]){
                        int diff = peak[index + 1];
                        peak[index + 1] = 1;
                        diff = peak[index + 1] - diff; //final - initial = diff
                        if (diff){
                            st.update(0, n - 1, index + 1, 0, diff);
                        }
                    }
                    else{
                        int diff = peak[index + 1];
                        peak[index + 1] = 0;
                        diff = peak[index + 1] - diff; //final - initial = diff
                        if (diff){
                            st.update(0, n - 1, index + 1, 0, diff);
                        }
                    }
                }
            }
        }

        return ans;
    }
};                       peak[index + 1] = 0;
                        diff = peak[index + 1] - diff; //final - initial = diff
                        if (diff){
                            st.update(0, n - 1, index + 1, 0, diff);
                        }
                    }
                }
            }
        }

        return ans;
    }
};   //completely bahar of required range
    if (qs <= ss && qe >= se){
        return tree[si];
    }
    //completely inside of required range

    //beech ka maamla hai so we make calls
    int mid = (ss + se) / 2;
    return getSum(qs, qe, ss, mid, 2*i + 1) + getSum(qs, qe, mid + 1, se, 2*i + 2);
}

Update Query : 

int diff_val = new_val - arr[i]

void updateRec(ss, se, i, si, diff){
    if (i < ss || i > se) return;
    //range m hi na h

    tree[si] += diff;
    //range m h to ise to update kr dia

    //check subtrees hain? agar hain to unhe bhi update karo
    if (se > ss){
        int mid = (ss + se) / 2;
        updateRec(ss, mid, i, 2*i + 1, diff);
         updateRec(mid + 1, se, i, 2*i + 2, diff);
    }
}

Time Compx of both of the above O(log n)

Binary Indexed Trees : Fenwick Trees

used when array is of fixed size available and we have two type of queries : 
Prefix operation : XOR, m, Product, OR - O(logn)
Update a value : 

It is actually array but is based on tree, it may have two or more children

preprocessing : O(nlogn) and O(n) space

we can also perform some range functions using the prefix values
rangeSum(i, j) = prefix(j) - prefix(i - 1)
Segment Tree requires 4n space but BIT requires only n space

We use the idea that every number can be represented as sum of powers of two
So we create our BIT such that it already has those values, like for 13, sum of values from indices 0 to 7 (2^3), 8 to 11 (2^4), 12 to 13 (2^1)
So the 1st 2nd 4th and 8th values of the BIT array are going to be sums from index 0 to 0, 0 to 1, 0 to 3, 0 to 7
For 3rd, we have 1 place so 1 we need, so index 2 to 2 sum
Basically for the remaining nodes we have to do the same thing as we did while filling 1 2 4 and 8

bc video dekh lo, i aint doing the coding part :(

*/

int main(){
    cout << "Hey there!" << endl;
}