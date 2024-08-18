//GFG article at the bottom see that
//I couldnt reember the code in theory I know but I wont be able to write the code

#include <bits/stdc++.h>
using namespace std;

/*
Explanation : Selection sort is good compared to other algos, No other sorting algo can do lesser memory writes than this, so EEPROM where write is costly, n square worst case time, inplace and not stable, useful for ques like how many minimum swaps are needed for sorting the array. We basically take each element, count the number of elements smaller than that, getting the correct eventual position of that element in the final sorted array. This sorting algo assumes that the array has ony distinct elements, no duplicates.
cs means cycle start, see the image he showed
elements upto cs are already sorted because we have already run our code considering them as cycle starts hence unka to sab set ho hi chuka hai
pos holds the number of elements that are smaller than current cs

In cycle sort we process the elements in cycles
*/

void CycleSortDistinct(vector<int> &sampleVector){
    int n = sampleVector.size();
    for (int cs = 0; cs < n - 1; cs++){
        int item = sampleVector[cs];
        //below is the first part of the cycle - in which se process the first element separately
        int pos = cs;
        //I start the checking from cs + 1 because firstly cs se khud to karenge naih
        //secondly if I am currently at cs, means all the elemnts from 0 to cs - 1 have already been processed and since processing results in correct positioning of elements at places, they are all smaller
        //basically itna to hoga hi ye, peeche to ja nahi sakta since those indices already have the correct element there
        //hence aur kitna aage leke jana h thats what we search for
        for (int i = cs + 1; i < n; i++){
            //last element ya to already theek ho hi jayega being a part of some cycle or else, agar kisi bhi cycle ka part nahi hai that means that its the largest
            if (sampleVector[i] < item){
                pos++;
            }
        }
        swap(item, sampleVector[pos]);
        // below is the later parts of the cycle
        while (pos != cs){
            pos = cs;
            for (int i = cs + 1; i < n; i++){
                if (sampleVector[i] < item){
                    pos++;
                }
            }
            swap(item, sampleVector[pos]);
        }
    }
}

//He gave homework for finding out a way to handle duplicates but I couldn't
//time complexity is O(n square), all average, best, worst, and space complexity is O(1)

int main(){
    cout << "Enter the array length : " << endl;
    int n;
    cin >> n;
    cout << "Enter the distinct elements : " << endl;
    int elem;
    vector<int> specialVector;
    for (int i = 0; i < n; i++){
        cin >> elem;
        specialVector.push_back(elem);
    }
    CycleSortDistinct(specialVector);
    cout << "The final array is : " << endl;
    for (auto i : specialVector){
        cout << i << " ";
    }
    cout << endl;
}

GFG ARTICLE

// C++ program to implement cycle sort
#include <iostream>
using namespace std;

// Function sort the array using Cycle sort
void cycleSort(int arr[], int n)
{
	// count number of memory writes
	int writes = 0;

	// traverse array elements and put it to on
	// the right place
	for (int cycle_start = 0; cycle_start <= n - 2; cycle_start++) {
        
		// initialize item as starting point
		int item = arr[cycle_start];

		// Find position where we put the item. We basically
		// count all smaller elements on right side of item.
		int pos = cycle_start;

        //I start the checking from cs + 1 because firstly cs se khud to karenge naih
        //secondly if I am currently at cs, means all the elemnts from 0 to cs - 1 have already been processed and since processing results in correct positioning of elements at places, they are all smaller
        //basically itna to hoga hi ye, peeche to ja nahi sakta since those indices already have the correct element there
        //hence aur kitna aage leke jana h thats what we search for

		for (int i = cycle_start + 1; i < n; i++)
			if (arr[i] < item)
				pos++;

		// If item is already in correct position
		if (pos == cycle_start)
			continue;

		// ignore all duplicate elements
		while (item == arr[pos])
			pos += 1;

		// put the item to it's right position
		if (pos != cycle_start) {
			swap(item, arr[pos]);
			writes++;
		}

		// Rotate rest of the cycle
		while (pos != cycle_start) {
			pos = cycle_start;

			// Find position where we put the element
			for (int i = cycle_start + 1; i < n; i++)
				if (arr[i] < item)
					pos += 1;

			// ignore all duplicate elements
			while (item == arr[pos])
				pos += 1;

			// put the item to it's right position
			if (item != arr[pos]) {
				swap(item, arr[pos]);
				writes++;
			}
		}
	}

	// Number of memory writes or swaps
	// cout << writes << endl ;
}

// Driver program to test above function
int main()
{
	int arr[] = { 1, 8, 3, 9, 10, 10, 2, 4 };
	int n = sizeof(arr) / sizeof(arr[0]);
	cycleSort(arr, n);

	cout << "After sort : " << endl;
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	return 0;
}
