#include <bits/stdc++.h>
using namespace std;

int main()
{
    // ARRAY

    array<int, 5> my_array = {1, 4, 6, 3, 9}; // declaration ke sath we have to also input the size of the array
    for (int i = 0; i < my_array.size(); i++) // returns the number of elements in the array
    {
        cout << my_array[i] << endl;
    }
    for (int i : my_array) // This is a range based loop, iterates over vector v, assigns each element to i
    {
        cout << i << " ";
    }
    cout << endl;
    cout << "The element at second index of the array is : " << my_array.at(2) << " " << my_array[2] << endl; // at ke andar index daalna hai
    cout << "Checking whether the array is empty or not : " << my_array.empty() << endl;                      // returns 0 or 1
    cout << "First array element : " << my_array.front() << endl;                                             // returns the first element
    cout << "Last array element : " << my_array.back() << endl;                                               // returns the last element
    cout << endl
         << endl
         << endl;

    // VECTOR

    vector<int> v;
    cout << "Size of the vector is : " << v.size() << endl;         // size is the number of elements
    cout << "Capacity of the vector is : " << v.capacity() << endl; // capacity is the memory allocated to the vector
    v.push_back(1);                                                 // Adds the elemetn to the back side (right)
    v.push_back(9);
    v.push_back(12);
    cout << "Size of the vector after insertions is : " << v.size() << endl;
    cout << "Capacity of the vector after insertions is : " << v.capacity() << endl;
    cout << "The element at second index of the array is : " << v.at(2) << " " << v[2] << endl; // at ke andar index daalna hai
    cout << "First array element : " << v.front() << endl;                                      // returns the first element
    cout << "Last array element : " << v.back() << endl;                                        // returns the last element
    cout << "Before popping : " << endl;
    for (int i : v) // This is a range based loop, iterates over vector v, assigns each element to i
    {
        cout << i << " ";
    }
    cout << endl;
    v.pop_back(); // removes the item from the back
    cout << "After popping : " << endl;
    for (int i : v) // This is a range based loop, iterates over vector v, assigns each element to i
    {
        cout << i << " ";
    }
    cout << endl;
    // push_front() kuch nahi hota
    vector<int> another_v(12, 3); // This means initializing a vector of size 12 with all the values 3, if not mentioned, in default case, vector is initialized with values 0
    vector<int> copy_v(v);        // this creates a new vector having all the elements of v
    cout << "The beginning iterator of the vector is : " << *v.begin() << endl; //Returns the beginnning iterator of the vector, we have to dereference the iterator since they are not printable like regular variables
    cout << "The ending iterator of the vector is : " << *v.end() << endl; //Returns the ending iterator of the vector, we have to dereference the iterator since they are not printable like regular variables
    v.clear();                    // Removes all the elements, but the memory assigned to the vector remains as it is
    cout << "Size of the vector after clearing is : " << v.size() << endl;
    cout << "Capacity of the vector after clearing is : " << v.capacity() << endl;
    cout << endl
         << endl
         << endl;

    // DEQUE - Doubly Ended queue (Starting and end dono positions mein push and pop kar sakte hain). Unlike array and vector, it doesn;t have contiguous memory allocation, different static memory blocks are pieced together to form this

    deque<int> d;
    d.push_back(99);
    d.push_front(12);
    d.push_back(32);
    for (int i : d)
    {
        cout << i << " ";
    }
    cout << endl;
    d.pop_back();
    for (int i : d)
    {
        cout << i << " ";
    }
    cout << endl;
    d.pop_front();
    for (int i : d)
    {
        cout << i << " ";
    }
    cout << endl;
    d.push_front(12);
    d.push_back(32);
    cout << "The beginning iterator of the deque is : " << *d.begin() << endl; // Returns the beginnning iterator of the vector, we have to dereference the iterator since they are not printable like regular variables
    cout << "The ending iterator of the deque is : " << *d.end() << endl;      // Returns the ending iterator of the vector, we have to dereference the iterator since they are not printable like regular variables
    //Similarly .at(), .front(), .back(), .empty() can be used
    d.erase(d.begin(), d.begin() + 1); //It takes two arguments, from and to, both inclusive, and erases that sub deque
    cout << "The size of the deque is : " << d.size(); //Number of elements
    cout << "The max size of the deque is : " << d.max_size(); //Memory allocated
    cout << endl
         << endl
         << endl;

    //LIST - It has been implemented using linked list

    list <int> l;
    l.push_back(12);
    l.push_front(33);
    for (int i : l)
    {
        cout << i << " ";   
    }
    l.erase(l.begin());
    l.push_back(12);
    l.push_back(445);
    l.push_back(122);
    list<int> new_l(l); //Copying method bhi same hai
    list <int> another_l(12, 100); // Initialized a new list having 12 elements, all initialized to 100
    //.pop_front(), pop_back(), empty, front, back, size, begin, end same as before
    cout << endl
         << endl
         << endl;

    //STACK

    stack <int> my_stack;
    my_stack.push(12);
    my_stack.push(32);
    my_stack.push(44);
    my_stack.push(13);
    cout << "The top of my stack is : " << my_stack.top() << endl;
    my_stack.pop();
    cout << "The top of my stack is : " << my_stack.top() << endl; 
    //size, empty same as before
    cout << endl
         << endl
         << endl;

    //QUEUE

    queue <string> my_queue;
    my_queue.push("Vaibhav");
    my_queue.push("Sharma");
    my_queue.push("Rakesh");
    cout << "The front of the queue is : " << my_queue.front() << endl;
    my_queue.pop();
    cout << "The front of the queue is : " << my_queue.front() << endl;
    cout << "The back of the queue is : " << my_queue.back() << endl;
    //size, empty same as before
    cout << endl
         << endl
         << endl;

    //PRIORITY QUEUE - Behind the scenes implementation = Heap Structure. First elementhumesha greatest hoga if the priority queue is max heap and smallest if the queue is minheap
    //Default priority queue is maxheap, that means whenever we take out the element from the queue, the maximum will come out

    priority_queue<int> maxi; //This is a max-heap
    priority_queue<int, vector<int>, greater<int>> mini; //This is a min-heap
    maxi.push(1);
    maxi.push(3);
    maxi.push(2);
    maxi.push(0);
    int n = maxi.size();
    for (int i = 0; i < n; i++){ //Instead of writing maxi.size() directly here, we write n because maxi.size( is changing continuously as the items are being popped
        cout << maxi.top() << " ";
        maxi.pop();
    }
    cout << endl;
    mini.push(1);
    mini.push(3);
    mini.push(2);
    mini.push(0);
    int n2 = mini.size();
    for (int i = 0; i < n2; i++)
    { // Instead of writing maxi.size() directly here, we write n because maxi.size( is changing continuously as the items are being popped
        cout << mini.top() << " ";
        mini.pop();
    }
    //.empty() bhi same hai
    cout << endl
         << endl
         << endl;

    //SET - Behind the scenes implementation using BST. Ismein elements sorted hote hain

    set<int> my_set;
    my_set.insert(2);
    my_set.insert(3);
    my_set.insert(1);
    my_set.insert(5);
    my_set.insert(4);
    my_set.insert(4); //Insert operation ki complexity O(logn) hai 
    my_set.insert(4); //Even if its added more than once, duplicate items will not be added
    //Elements are always stored in set in sorted order, printed out the same way   
    for (auto i:my_set){
        cout << i << " ";
    }
    cout << endl;
    set<int> :: iterator my_iterator = my_set.begin();
    my_iterator++; //Will help us remove the second element, because hum directly my_set.begin()++ nahi kar sakte
    my_set.erase(my_iterator);
    for (auto i : my_set)
    {
        cout << i << " ";
    }
    cout << endl;
    cout << my_set.count(3) << endl; // Tells us whether the element is present in the set or not
    set<int> :: iterator my_iterator_another = my_set.find(5); //Returns the reference of the element if found
    cout << "The value present at the my_iterator_another is : " << *my_iterator_another << endl;
    //Insert, find, erase, count complexity = O(Logn)
    cout << endl
         << endl
         << endl;

    //MAP - Key-value pairs mein stored hota hai data, same key can't point to multiple values, multiple keys can point to the same value though

    map<int, string> m;
    m[0] = "Vaibhav";
    m[1] = "Sharma";
    m[2] = "What's Up";
    m[3] = "HaHaHaHa";
    m.insert({12, "Ths is 12"});
    m[123] = "Wtf is this"; //It's not like indeces, take any number you want, but data sorted way mein store hoga
    for (auto i : m){
        cout << i.first << " : " << i.second << endl;
    }
    cout << endl;
    cout << m.erase(1) << endl; //Erases the key value pair with the key value 1, complexity = O(Logn)
    cout << m.count(12) << endl; //This checks whether the value 12 is present as one of the keys or not
    //.find() as always returns the iterator of the element
    cout << endl
         << endl
         << endl;
    
    //Unordered Set and Unordered Map code wise same hote hain, its just that complexities kam hoti hain and the data isnt sorted

    //ALGORITHMS

    v.push_back(-1);
    v.push_back(9);
    v.push_back(12);
    v.push_back(44);
    cout << "Finding 12 in the vector : " << binary_search(v.begin(), v.end(), 12) << endl;
    cout << "The upper bound for 10 of the vector is : " << upper_bound(v.begin(), v.end(), 10) - v.begin() << endl; //Returns the index of the first element that's greater than 10, the -v.begin() part removes the beginning iterator part from the returned iterator and makes it an index integer
    cout << "The lower bound for 10 of the vector is : " << lower_bound(v.begin(), v.end(), 10) - v.begin() << endl; //Returns the index of the first element that's greater or equal to than 10, the -v.begin() part removes the beginning iterator part from the returned iterator and makes it an index integer
    //.find() methods works the same here
    int a = 6;
    int b = 1;
    cout << "The maximum is  : " << max(a, b) << endl;;
    cout << "The minimum is  : " << min(a, b) << endl;;
    swap(a, b);
    cout << "The values of a and b are : " << a << b << endl;
    string my_string = "Vaibhav";
    reverse(my_string.begin(), my_string.end());
    cout << "The reverserd string is : " << my_string << endl;
    rotate(v.begin(), v.begin() + 1, v.end()); //We have to give three values : beginning, how many times we want to sort it in the form of added to the beginning, and ending iterators
    for (int i : v){
        cout << i << " ";
    } 
    cout << endl;
    sort(v.begin(), v.end());
    for (int i : v)
    {
        cout << i << " ";
    }
    cout << endl;
}