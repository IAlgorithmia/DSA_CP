#include <bits/stdc++.h>
using namespace std;

/*
Explanation : Binary Heaps main application is implementation of heapsort and priority queue - a queue with items having a priority, the priority of default queue can be thought of as first come first serve

Min Heap - Lowest Value Highest Priority
Max Heap - Highest Value Highest Priority

Binary Heap is a complete binary tree !!! VERY IMPORTANT !!!

From an array : 
left = 2i + 1
right = 2i + 2
parent = floor((i - 1) / 2)

Most often we represent binary heaps as arrays with proper parent child relation

Advantages : 
1. Items at contiguous locations
2. Cache friendly since locality of reference is there
3. Complete BT so height is minimum possible
4. Space saved

MinHeap : Complete binary tree with each node's value being smaller than all its descendants

Our own class : 

class minHeap{
    vector<int> the_vect;
    int size;
    int capacity;
    minHeap(int c){
        the_vect = vector<int> a_vect(c);
        size = 0;
        capacity = c;
    }
    int left(int i) return [(i + 1)/2];
    int right(int i) return [(i + 2)/2];
    int parent(int i) return [(i - 1)/2];

    void insert(int x){
        if (capacity == size) return;
        size++;
        the_vector.push_back(x);
        int i = size - 1;
        while (i != 0 && the_vector[parent(i)] > the_vector[i]){
            swap(the_vector[parent(i)], the_vector[i]);
            i = parent(i);
        }
    }

    Heapify is used as a subroutine in Build Heap and Extract Minimum

    void minHeapify(int i){
        int lt = left(i);
        int rt = right(i);
        int smaller = i;
        if (lt < size && the_vect[lt] < the_vect[smaller]){
            smaller = lt;
        }
        if (rt < size && the_vect[rt] < the_vect[smaller]){
            smaller = rt;
        }
        if (smaller != i){
            swap(the_vect[i], the_vect[smaller]);
            minHeapify(smaller);
        }
    }
    //The above takes o(logn) time, recursive takes O(logn) recursive space too it can be turned into iterative solution obviously which takes O(1) extra space

    Extract Min : 

    int extractMin(){
        if (size == 0){
            return INT_MAX;
        }
        if (size == 1){
            size--;
            return the_vect[0];
        }
        swap(the_vect[0], the_vect[size - 1]);
        size--;
        minHeapify(0);
        return the_vect[size];
    }

    its time complexity is also minHeapify

    Decrease Key - A key is decreased and a new value is given 

    void decreaseKey(int i, int x){
        the_vect[i] = x;
        while (i != 0 && the_vect[parent(i)] < the_vect[i]){
            swap(the_vect[parent(i)], the_vect[i]);
        }
    }

    Delete Key : We become teej here, we swap the key required to be deleted with -inf, then call extract min :)
    The overall time complexity becomes O(logn)
    Build Heap function just calls the heapify function with indices from the bottommost rightmost internal node's index all the way to 0
    so from ((size - 1) this is the last element - 1 minus 1 for parent) / 2

    Time complexity of build heap : 
    Maximum number of nodes at a height h : Upper bounded by n / 2^(h + 1)
    It may seem like the complexity is O(nlogn) but actually it is O(n)

    Heapsort works like this : find the maximum in the array, replace it with the last element, now for finding out the max we use first build heap just once initially then heapify repeatedly since max will be at the first index then then we swap, hence from n square we go to nlogn
    Increasing order => Max Heap
    Decreasing order => Min Heap
    Step 1 : Build MaxHeap
    Step 2 : Repeatedly Swap the root with the last node, reduce the heap size by 1 and call heapify

    Code : 

    Priority Queue in CPP :
    priority_queue<int> pq; => MaxHeap - DEFAULT
    priority_queue<int, vector<int>, greater<int>> pq; => MinHeap

    Ye gandi se cheez nahi karni to sare elements -ve karke inser karo and then top print mat karo instead -top print karo

    int arr[] = {10, 5, 12};
    priority_queue<int> pq(arr, arr + 3); //Creating a pq from an array, same method for vector this method is of O(n) time complexity

    If pairs added then the first element ke according hoga

    Say we have a data type with a height attribute and we want to insert according to that
    then

    struct myCmp{
        bool operator() (Person const &p1, Person const &p2){
            return p1.ht < p2.ht; //Decreasing order of height
        }
    }

    priority_queue<Person, vector<Person>, myCmp> pq; //When custom required

    Dijkstraw, Prim, Huffman, Heapsort - Applications of pq

    CPP mein decrease key nahi hai

    Sort a K sorted array : The element which is to come at index i is present between i - k to i + k indices
    We will maintain a min heap of k elements starting from 0 to k indices that will tell us which element to insert starting from index 0

    void sortK(vector<int> the_vect, int k, int n){
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 0; i <= k; i++){
            pq.push(the_vect[i]);
        }
        int index = 0;
        for (int i = k + 1; i < the_vect.size(); i++){
            the_vect[index] = pq.top();
            pq.pop();
            pq.push(the_vect[i]);
        }
        while(pq.empty() == false){
            the_vect[index++] = pq.top();
            pq.pop();
        }
    }

    Time complexity is O(nlogk) otherwise it would be O(nlogn)

    Purchasing Maximum Items : We are given a cost array and a maximum cost, we will build a heap using the array, until the max cost is greater than the top we will continue. We will see the top of the queue if it is smaller than cost, we will remove it and update the max cost and do res++. The moment we find the top being more than the cost, we return the result res;
    Time complexity is O(res * logn)

    K largest element : Max Heap se kara directly to we will get n + klogn time complexity
    For better : 
    We build a minHeap for first k elements
    Then we go to k + 1 th element, if the root is smaller than that element then we remove the root, and add that element else we just ignore and move on
    After traversing the whole array we print the final minHeap.
    At any point, the minHeap has the k largest elements upto that index

    Complexity is O(k + (n - k)*logk)

    K Closest elements : 

    Naive : We traverse the whole array k times, first the first closest then second closest and so on, we mark the chosen element using a boolean array as something so that we dont reconsider that in future iterations.
    
    We create a max heap, insert the first k element with their indices into the maxHeap, then traverse for the k + 1th to last element, if difference is smaller then we remove the top of the maxHeap

    void findKClosest(int k, int x){
        priority_queue<pair<int, int>> pq;

        for (int i = 0; i < k; i++){
            pq.push({abs(the_vect[i] - x), i})
        }

        for (int i = k; i < n; i++){
            if (pq.top.second > abs(the_vect[i] - x)){
                pq.pop();
                pq.push({abs(the_vect[i] - x), i});
            }
        }

        //in the end well be left with the min k 

        for (auto i : pq){
            print i.first and i.second
        }
    }

    Time complexity is O(nlogk)

    Merge K sorted arrays : 

    Super Naive : Put all in one vector and sort it
    Naive : Put first into result then repeatedly apply merge function from merge sort for merging the result array and the next in line

    Efficient Method has O(nklogk) time complexity

    We create a new type of object : Value, Index of the vector from which it is taken in the outer vector, Index of this element in the vector from which is is taken
    We create a minHeap based on the value, insert into it the first element of each vector in proper format, extract min, then from that same vector from which it belonged we push the next element, and so on until the endgame

    struct Triplet{
        int val, aPos, vPos;
        Triplet(int val, int aPos, int vPos){
            val = val;
            aPos = aPos;
            vPos = vPos;
        }
    }
    struct myCmp{
        bool operator()(Triplet const &t1, Triplet const &t2){
            return t1.val > t2.val;
        }
    }
    vector<int> mergeArr(vector<vector<int>> &arr){
        vector<int> res;
        priority_queue<int, Triplet, myCmp> pq;
        for (int i = 0; i < arr.size(); i++){
            Triplet t(arr[i][0], i, 0);
            pq.push(t);
        }
        while (pq.empty() == false){
            Triplet curr = pq.top();
            pq.pop();
            res.push(curr.val);
            int ap = curr.aPos;
            int vp = curr.vPos;
            if ((vp + 1) < arr[ap].size()){
                Triplet p(arr[ap][vp + 1], ap, vp + 1);
                pq.push(p);
            }
        }
        return res;
    }

    Median of a Stream : Popular interview question

    Naive : We maintain a sorted vector and give conditional median based on size of vector

    Better : We maintain an augmented BST, extra element being how many elements are smaller than this (we did this before) then based on size we find appropriate elements and give result

    Best : We maintain two containers, first having smaller half of the elements, second having larger half of the elements. If we have seen odd number of elements so far then median is the largest of the first container, else its the average of the largest from 1st and smallest from 2nd container
    
    We choose maxHeap for 1st container since we want the largest, minHeap for 2nd container, overall time complexity = O(nlogn)
    Whenever we have odd elements, we keep the extra element in the first container, this is the method

    void printMedians(vector<int> the_vect, int n){
        priority_queue<int> s; //smaller
        priority_queue<int, vector<int>, greater<int>> g; //greater

        s.push(the_vect[0]);
        cout << the_vect[0] << endl;

        for (int i = 0; i < n; i++){
            int x = the_vect[i];
            if (s.size() > g.size()){
                if (x < s.top()){
                    g.push(s.top());
                    s.pop();
                    s.push(x);
                }
                else{
                    g.push(x);
                }
                cout << (s.top() + g.top()) / 2.0 << endl;
            }
            else{
                if (x <= s.top()){
                    s.push(x);
                }
                else{
                    g.push(x);
                    s.push(g.top()); //if x is smaller than g.top() then it will automatically belong to 1st container nevertheless
                    g.pop();
                }
                cout << s.top() << endl;
            }
        }
    }


*/

int main(){
    cout << "Hey there!" << endl;
}