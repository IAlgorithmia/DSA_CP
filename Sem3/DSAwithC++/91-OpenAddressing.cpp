#include <bits/stdc++.h>
using namespace std;

/*
Explanation : It is cache friendly advantage over chaining, and the number of slots in hash table is greater than number of keys to be inserted.

Linear Probing : 
index = (h(key) + i) % m; i = 0, 1, 2, ..., h(key) = key
Insert ke liye hash function se index lenge, if somethings already there then we go to the next index.
Search ke liye hash function se index lenge, vahan mil gaya to true, else linearly traverse the hash table, mila to true, we return false in either of 3 cases : 

1. We encounter an empty cell
2. We traverse through the whole table

For deletion, we do not empty the slot as it will harm the searching, instead we mark the cell as deleted, we dont stop the search when we encounter a deleted cell, but insertion can be done there. 

Problem of linear Probing : Clustering

This problem is solved via quadratic probing
index = (h(key) + i^2) % m; i = 0, 1, 2, ..., h(key) = key
but idhar secondary clustering ho jayenge, also sometimes it may not find an empty slot even if it is there, thats aso a prob
This works best when m is prime and factor < 0.5, means size of table should be double the number of elements

This problem is solved via double hashing
index = (h1(key) + i * h2(key)) % m; i = 0, 1, 2, ...
h2 function should never return 0 and h2(key) and m must be relatively prime

Expected number of probes required = (1 / 1 - alpha), 1 - alpha is the fraction of table thats empty

Chaining vs Hash Table : 

Chaining : 

1. Hash Table never fills
2. Less sensitive to hash functions
3. Poor cache performance
4. Extra space for links

Open Addressing : 

1. Table may become full and resizing becomes mandatory
2. Extra care is required for clustering
3. Cache friendly
4. Extra space might be needed to give same performance as chaining

Set is based on red black tree, Unorderedset uses hashing

auto i = unorderedSet_name.begin(), it++, *it se we can traverse
auto it = unordered_set_name.find(element), isko bhi as a starting point use kar sakte hain

Functions : insert, size, begin, end, clear, find, count, erase (either pass element or iterator, range of iterators bhi de sakte ho)

Map is based on red black tree, UnorderedMap uses hashing. We can make the dictionary directly like dict_name[key_name] = value_name.

auto i = unorderedMap_name.begin(), it++, it->first for key and it->second for value se we can traverse
auto it = unordered_map_name.find(element), isko bhi as a starting point use kar sakte hain

functions saare ismein bhi hain, begin, end, size, empty, count, find, erase(key), insert, [], at

Java mein HashSet and HashMap hota hai 

If you have an array named arr and you want to create an unordered set of all its elements, do it like unordered_set_name<int> s(arr, arr + n), this creates an unordered_set with those elements
*/

//Below is OpenAddresssing without any collision handling techniques, pretty shitty implementation
class MyHash {
private:
    int* hashTable;
    int cap, size;

public:
    MyHash(int c) {
        cap = c;
        size = 0;
        for (int i = 0; i < cap; i++){
            hashTable[i] = -1;
        }
    }
    int hash(int key){
        return key % cap;
    }
    bool insert(int key) {
        if (size == cap){
            return false;
        }
        int h = hash(key);
        int i = h;
        while (hashTable[i] != -1 && hashTable[i] != -2 && hashTable[i] != key){
            i = (i + 1) % cap;
        }
        if (hashTable[i] == key){
            return false;
        }
        else{
            hashTable[i] = key;
            size++;
            return true;
        }
    }

    bool remove(int key) {
        int h = hash(key);
        int i = h;
        while (hashTable[i] != -1){
            if (hashTable[i] == key){
                hashTable[i] = -2;
                return true;
            }
            i = (i + 1) % cap;
            if (i == h){
                return false;
            }
        }
        return false;
    }

    bool search(int key) {
        int h = hash(key);
        int i = h;
        while (hashTable[i] != -1){
            if (hashTable[i] == key){
                return true;
            }
            i = (i + 1) % cap;
            if (i == h){
                return false;
            }
        }
        return false;
    }
};

int main() {
    HashObject hashObj(10);
    cout << "Hey there!" << endl;
    return 0;
}