#include <bits/stdc++.h>
using namespace std;

/*
Explanation : Implements dict, sets. No duplicate keys are allowed. Not used in : Finding closest value, sorted data, prefix searching. Used in : Dictionaries, Database Indexing, Cryptography, Caches, Symbol tables in compilers/interpreters, Routers, Getting data from db.
Hashing is based on Direct Address Table - Say Im gonna give you a value from 0 to 999, and you have to perform insert, delete, search in O(1) time, you will create an array with size 1000 (indices from 0 to 999) initialized to value 0. Then jo jo dia h us index pe 1 kar doge accordingly, using which teeno cheezein ho jayengi. Range agar 1000 to 1999 bhi hoti to -1000 karke kaam kar dete apna. 
Demerits : If range of keys is from 0 to 10^5, high space req even though 1 2 keys gotta be stored. Second keys can be floating, strings, or others.

So we use Hash Functions, which take a key value, do some magic, and convert that key value into a smaller usable key. 
Hash Functions Requirements : 

1. Should always map a large key to same small value
2. Should generate values from 0 to m - 1, m = size of array
3. Should be fast, O(1) for integers and O(len) for strings
4. Should uniformly distribute large keys into hash table slots (MOST IMP)

Hash table size is proportional to the size of Keys. Goodness of hash func can be seen to how much it avoids collision, so least collision is there.

Universal Hashing : Pick one randomly out of many has funcs
If we know keys in advance, we can do perfect hashing

Collision handling techniques : 

1. Chaining
2. Open Addressing

Open Addressing : 
1. Linear Probing
2. Quadratic Probing
3. Double Hashing

For integers we generally use index = (value) % some_prime_number
For integers we generally use index = sumOfASCII values

Chaining mein we maintain an array of Linked List
m = number of slots in hash table
n = number of keys to be inserted
load factor = n / m (How big you want your hash table to be)
expected chain length = load factor
time to search, insert and delete = O(1 + load_factor)
The above is all under the assumption that keys are stored almost uniformly

Other DS for Chaining = Dynamic Sized arrays, Self Balancing BST
Ye ek rule maanke rakhlo ke jab bhi hum linked list banate hain tab pointer hi banayenge uske data type ka like Node* ptr = new Node(); ek node class hai, ptr to pointer hai jo Node data type ko point kar raha hai, and us class ka object banake use address bhi thama dia 

Maps mein map[item]++ directly kar sakte hain, without wondering about insertion if not present or not
*/

int main(){
    cout << "Hey there!" << endl;
}