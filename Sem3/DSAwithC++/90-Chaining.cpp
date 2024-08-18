#include <bits/stdc++.h>
using namespace std;

/*
Explanation : We are implementing chaining here. Object ke 2 attributes honge, ek to bucket size and ek pointer jo ek integer list ko point karega. We are creating an array of linked list, we have created a pointer table, this is of type list, which is used to implement doubly linked list in CPP. 
Breakdown:

list<int>: This part represents a template for a standard library container class (list) that specifically stores integer (int) elements.
*: The asterisk (*) denotes a pointer variable. So, list<int>* declares a pointer that can hold the memory address of a list<int> object.
In simpler terms:

The code defines a pointer variable named table.
This pointer variable is designed to point to an array of list<int> objects.
The actual array is not created yet (it's allocated dynamically using new in the MyHash constructor).
*/

struct MyHash{
    int BUCKET;
    list<int> *table;
    MyHash(int b){
        BUCKET = b;
        table = new list<int>[b];
    }
    void insert(int key){
        int i = key % BUCKET;
        table[i].push_back(key);
    }
    bool search(int key){
        int i = key % BUCKET;
        for (auto x : table[i]){
            if (x == key){
                return true;
            }
        }
        return false;
    }
    void remove(int key){
        int i = key % BUCKET;
        table[i].remove(key);
    }
}

int main(){
    cout << "" << endl;
}