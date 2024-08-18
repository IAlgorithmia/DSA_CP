//Idk why we didnt take minheap here
//buildMinHeap and buildMaxHeap are O(n) tasks
//Heapify itself is O(logn) task

#include <bits/stdc++.h>
using namespace std;

// The Compare struct uses return a.second > b.second;, which means that if a.second is greater than b.second, a will have a lower priority than b. This ensures that the smallest second element is on top of the min-heap.
//see the example below for creating a custom comparator for heaps
// class Solution {
// public:
//     struct Compare {
//         bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
//             // Compare based on the second element of the pair
//             return a.second > b.second;
//         }
//     };
//     // The Compare struct uses return a.second > b.second;, which means that if a.second is greater than b.second, a will have a lower priority than b. This ensures that the smallest second element is on top of the min-heap.
//     static bool comparator(const vector<int> &a, const vector<int> &b){
//         if (a[0] == b[0]){
//             return a[1] < b[1];
//         }
//         return a[0] < b[0];
//     }
    
//     int maxEvents(vector<vector<int>>& events) {
//         //for each day I have to see which events I can currently attend, start <= curr and end >= curr and then do the one
//         //which has the earliest deadline
//         int start = 0, end = 0, day = 1;
//         int n = events.size();
//         sort(events.begin(), events.end(), comparator);
//         int max_day = events[n-1][1];
//         priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> minHeap, temp;
//         int cost = 0;
//         while (!minHeap.empty() || day <= max_day){
//             while (end < n && events[end][0] == day){
//                 minHeap.push({events[end][0], events[end][1]});
//                 end++;
//             }
//             while (!minHeap.empty() && minHeap.top().second < day){
//                 minHeap.pop();
//             }
//             if (!minHeap.empty()){
//                 minHeap.pop();
//                 cost++;
//             }
//             day++;
//         }
//         return cost;
//     }
// };


/*
Explanation : Similar to selection sort, but instead of searching the min element linearly it uses maxHeap data structure (array ko hi banayenge then root ko first element se replace kar denge fir heapify can be run])
Use maxheap fr increasing order and minheap for decreasing order
Keep in mind parent of node at index i is at (i - 1) / 2, not at i / 2
*/

void MaxHeapify(vector<int> &specialVector, int nodeIndex, int heapEnd){
    //remember that Heapify runs on a node we gotta give it with an index
    int largest = nodeIndex, left = (2 * nodeIndex) + 1, right = (2 * nodeIndex) + 2;
    int n = heapEnd;
    if ((left < n) && (specialVector[left] > specialVector[largest])) largest = left;
    if ((right < n) && (specialVector[right] > specialVector[largest])) largest = right;
    if (largest != nodeIndex){
        swap(specialVector[nodeIndex], specialVector[largest]);
        MaxHeapify(specialVector, largest, n);
    }
}

void BuildHeap(vector<int> &specialVector){
    //this method just has to run MaxHeapify for all the internal nodes starting from the last
    int n = specialVector.size();
    for (int i = (n - 2) / 2; i >= 0; i--){
        MaxHeapify(specialVector, i, n);
    }
}

void HeapSort(vector<int> &specialVector){
    BuildHeap(specialVector);
    int n = specialVector.size();
    for (int i = n - 1; i > 0; i--){
        swap(specialVector[i], specialVector[0]);
        MaxHeapify(specialVector, 0, i); //reducing heapsize by 1 in each iteration
    }
}

int main(){
    int n;
    cout << "Enter the length of the array : " << endl;
    cin >> n;
    cout << "Enter the elements : " << endl;
    int elem;
    vector<int> specialVector;
    for (int i = 0; i < n; i++){
        cin >> elem;
        specialVector.push_back(elem);
    }
    HeapSort(specialVector);
    cout << "The final array is : " << endl;
    for (auto i : specialVector){
        cout << i << " ";
    }
    cout << endl;
} 