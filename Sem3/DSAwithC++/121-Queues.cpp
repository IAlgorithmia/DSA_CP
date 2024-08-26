#include <bits/stdc++.h>
using namespace std;

/*
Explanation :

### QUEUES ###

Applications :

Single Resource and Multiple Consumers
Synchronization between slow and fast devices
OS - Semaphores, FCFS Schedulling, Spooling, Buffer
In Computer Science(Routers, Switches, Mail Queues)
Variations : Deque, Priority Queue and Doubly Ended Priority Queue

Queue using vector :

bool isFull(){
    return cap == size;
}

bool isEmpty(){
    return cap == 0;
}

int getFront(){
    if (isEmpty()){
        return -1;
    }
    else{
        return front;
    }
}


int getRear(){
    if (isEmpty()){
        return -1;
    }
    else{
        return (front + size - 1) % cap;
    }
}

void enque(int x){
    if (isFull()){
        return;
    }
    int rear = getRear();
    rear = (rear + 1);
    arr[rear] = x;
    size++;
}

void deque(){
    if (isEmpty()) return;
    front  = (front + 1) % cap;
    size--;
}

Queue using LinkedList :

struct Node{
    int data;
    Node* next;
    Node (int x){
        data = x;
        next = NULL;
    }
}

struct Queue{
    Node *front, *rear;
    int size;
    Queue(){
        front = NULL;
        rear = NULL;
        size = 0;
    }

    void enQue(int x){
        Node *temp = new Node(x);
        size++;
        if (front == NULL){
            front = temp;
            rear = temp;
        }
        rear->next = temp;
        rear = temp;
    }

    void deQue(){
        size--;
        if (front == NULL){
            return;
        }
        Node *temp = front;
        front = front->next;
        if (front == NULL){
            rear = NULL;
        }

        delete(temp);
    }
}

Implementing Stack using Queue :

You gotta choose whether you want to maintain the newly inserted element just at the front or the rear of the queue

We take two queues, q1 and q2

1. Making Push Costly

We are gonna implement the things such that each newly inserted item is in the front of the queue
top mein we return the front
size mien we return size
pop mein we just dequeue (since starting se hi remove karne hain)

so

push mein we first move all elements from q1 to q2 by getting front and through dequeuing and enqueuing
then we enqueue the requested item in q1, then we move the items from q2 to q1 by dequeuing and enqueuing

2. Making pop costly

In the above implementation we made push operation costly, similarly we can make the pop operation costly which will change the direction of the stack

newly inserted element is at the end of the queue

Top mein we return rear
size mein size
push mein enqueue
pop mein jab tak 1 na reh jaaye tak tab dequeue karke q2 mein enqueue karte raho, last vale ko dequeue ardo q1 se then q2 ke saare q1 mein daaldo

3. Using only one queue

https://www.geeksforgeeks.org/implement-a-stack-using-single-queue/

For Above Point 1 -
First rear ko chod ke baaki ka queueu reverse karna padega after all is said and done

For Above Point 2 -
Final pure me pure queue ko reverse karna hoga, then well get the correct answer

Implementing Queue using Stack :

You gotta choose whether you want to maintain the newly inserted element just at the top or the bototm of the stack

1. Making Enqueue costly :

Gotta save the most newly inserted element for rear, front ke liye top return akr denge, dequeue ke liye pop, enqueue ke liye pehle saare doosre mein daalo then fir new vala daaldo s1 mein then vo saare vapas le aao

2. Making Dequeue Costly :

Gotta save the first element for front, rear ke liye top return kar denge, enqueue mein bas push kar denge, dequeue ke liye pehle last vale ke sivaye saare doosre mein bheejo, last nikalo then vapas le aao vo saare

3. Using only one stack (One recursion call stack) :

For both the above implementations we can easily use the recursion call stack to get intended result
basically 2 stacks needed hi hain, acually we are stll using 2 stacks

Reversing a Queue :

1. Iterative : Stack mein daaldo dequeue karte karte then stack se enqueue karate raho, ya fir dequeue karo and immedaitely enque krdo

2. Recursive : Queue ke front ko store karo, fir dequeue karo, fir func call karo, (uski base condition ye rekhna is size == 1 then do nothing and return), fir nikala hua element vapas daldo

void reverse(queue<int> q){
    if (q.empty()) return;
    int x = q.front();
    q.pop();
    reverse(q);
    q.push(x);
}

We will be given a number n, we have to find out n numbers in increasing order such that all of them have digits either 5 or 6

5 6
6 55 56
55 56 65 66
56 65 66 555 556 and so on

We take numbers as string here since for a large n, the number may go out of range

void printFirstN(int n){
    queue<int> q;
    q.push("5");
    q.push("6");
    for (int i = 0; i < n; i++){
        string str = q.pop();
        cout << str << endl;
        q.push(str + "5");
        q.push(str + "6");
    }
}

Were this a general case, we wouldve done the str + thing aprt in a loop for all the given digits

If the question was to return the nth number, we would've created a counter, increased it each time we were going to insert
anything into the queue, if it ever became equal to n, we would return what we were going to insert


### DEQUEUES ###

Implementation :

Doubly Linked List and Circular Array
Singly Linked List not done because deletion from tail not possile in O(1) even if we maintain tail pointer

Simple array implementation mein either we can make the pop costly (rear grows towards right and each time we deque something we gotta shift all the next elements leftwards) or the push costly (front grows towards right and each time we enque something we first gotta shif tall the items rightwards)
Circular array mein we can use the fact that rear = (front + size - 1) % cap - here size is the number of elements and cap is the limit, ismein upar vali bakchodi nahi hai enque mein rear ko badha do bas % cap karke and deque mein front ko badha do %cap karke, empty and full ki conditions check kar lena

Circular Array Implementation :

insert at rear : we are going to increase the rear count
delete at rear : we are going to decrease the rear count
insert at front : we are going to decrease the front count
delete at front : we are going to increase the front count

// C++ implementation of De-queue using circular
// array
#include <iostream>
using namespace std;

// Maximum size of array or Dequeue
#define MAX 100

https://www.geeksforgeeks.org/implementation-deque-using-circular-array/

// A structure to represent a Deque
class Deque {
    int arr[MAX];
    int front;
    int rear;
    int size;

public:
    Deque(int size)
    {
        front = -1;
        rear = 0;
        this->size = size;
    }

    // Operations on Deque:
    void insertfront(int key);
    void insertrear(int key);
    void deletefront();
    void deleterear();
    bool isFull();
    bool isEmpty();
    int getFront();
    int getRear();
};

// Checks whether Deque is full or not.
bool Deque::isFull()
{
    return ((front == 0 && rear == size - 1)
            || front == rear + 1);
}

// Checks whether Deque is empty or not.
bool Deque::isEmpty() { return (front == -1); }

// Inserts an element at front
void Deque::insertfront(int key)
{
    // check whether Deque if full or not
    if (isFull()) {
        cout << "Overflow\n" << endl;
        return;
    }

    // If queue is initially empty
    if (front == -1) {
        front = 0;
        rear = 0;
    }

    // front is at first position of queue
    else if (front == 0)
        front = size - 1;

    else // decrement front end by '1'
        front = front - 1;

    // insert current element into Deque
    arr[front] = key;
}

// function to inset element at rear end
// of Deque.
void Deque ::insertrear(int key)
{
    if (isFull()) {
        cout << " Overflow\n " << endl;
        return;
    }

    // If queue is initially empty
    if (front == -1) {
        front = 0;
        rear = 0;
    }

    // rear is at last position of queue
    else if (rear == size - 1)
        rear = 0;

    // increment rear end by '1'
    else
        rear = rear + 1;

    // insert current element into Deque
    arr[rear] = key;
}

// Deletes element at front end of Deque
void Deque ::deletefront()
{
    // check whether Deque is empty or not
    if (isEmpty()) {
        cout << "Queue Underflow\n" << endl;
        return;
    }

    // Deque has only one element
    if (front == rear) {
        front = -1;
        rear = -1;
    }
    else
        // back to initial position
        if (front == size - 1)
        front = 0;

    else // increment front by '1' to remove current
        // front value from Deque
        front = front + 1;
}

// Delete element at rear end of Deque
void Deque::deleterear()
{
    if (isEmpty()) {
        cout << " Underflow\n" << endl;
        return;
    }

    // Deque has only one element
    if (front == rear) {
        front = -1;
        rear = -1;
    }
    else if (rear == 0)
        rear = size - 1;
    else
        rear = rear - 1;
}

// Returns front element of Deque
int Deque::getFront()
{
    // check whether Deque is empty or not
    if (isEmpty()) {
        cout << " Underflow\n" << endl;
        return -1;
    }
    return arr[front];
}

// function return rear element of Deque
int Deque::getRear()
{
    // check whether Deque is empty or not
    if (isEmpty() || rear < 0) {
        cout << " Underflow\n" << endl;
        return -1;
    }
    return arr[rear];
}

// Driver code
int main()
{
    Deque dq(5);

    // Function calls
    cout << "Insert element at rear end : 5 \n";
    dq.insertrear(5);

    cout << "insert element at rear end : 10 \n";
    dq.insertrear(10);

    cout << "get rear element "
        << " " << dq.getRear() << endl;

    dq.deleterear();
    cout << "After delete rear element new rear"
        << " become " << dq.getRear() << endl;

    cout << "inserting element at front end \n";
    dq.insertfront(15);

    cout << "get front element "
        << " " << dq.getFront() << endl;

    dq.deletefront();

    cout << "After delete front element new "
        << "front become " << dq.getFront() << endl;
    return 0;
}

//Using DLL

https://www.geeksforgeeks.org/implementation-deque-using-doubly-linked-list/

// C++ implementation of Deque using
// doubly linked list
#include <bits/stdc++.h>

using namespace std;

// Node of a doubly linked list
struct Node {
    int data;
    Node *prev, *next;
    // Function to get a new node
    static Node* getnode(int data)
    {
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->data = data;
        newNode->prev = newNode->next = NULL;
        return newNode;
    }
};

// A structure to represent a deque
class Deque {
    Node* front;
    Node* rear;
    int Size;

public:
    Deque()
    {
        front = rear = NULL;
        Size = 0;
    }

    // Operations on Deque
    void insertFront(int data);
    void insertRear(int data);
    void deleteFront();
    void deleteRear();
    int getFront();
    int getRear();
    int size();
    bool isEmpty();
    void erase();
};

// Function to check whether deque
// is empty or not
bool Deque::isEmpty() { return (front == NULL); }

// Function to return the number of
// elements in the deque
int Deque::size() { return Size; }

// Function to insert an element
// at the front end
void Deque::insertFront(int data)
{
    Node* newNode = Node::getnode(data);
    // If true then new element cannot be added
    // and it is an 'Overflow' condition
    if (newNode == NULL)
        cout << "OverFlow\n";
    else {
        // If deque is empty
        if (front == NULL)
            rear = front = newNode;

        // Inserts node at the front end
        else {
            newNode->next = front;
            front->prev = newNode;
            front = newNode;
        }

        // Increments count of elements by 1
        Size++;
    }
}

// Function to insert an element
// at the rear end
void Deque::insertRear(int data)
{
    Node* newNode = Node::getnode(data);
    // If true then new element cannot be added
    // and it is an 'Overflow' condition
    if (newNode == NULL)
        cout << "OverFlow\n";
    else {
        // If deque is empty
        if (rear == NULL)
            front = rear = newNode;

        // Inserts node at the rear end
        else {
            newNode->prev = rear;
            rear->next = newNode;
            rear = newNode;
        }

        Size++;
    }
}

// Function to delete the element
// from the front end
void Deque::deleteFront()
{
    // If deque is empty then
    // 'Underflow' condition
    if (isEmpty())
        cout << "UnderFlow\n";

    // Deletes the node from the front end and makes
    // the adjustment in the links
    else {
        Node* temp = front;
        front = front->next;

        // If only one element was present
        if (front == NULL)
            rear = NULL;
        else
            front->prev = NULL;
        free(temp);

        // Decrements count of elements by 1
        Size--;
    }
}

// Function to delete the element
// from the rear end
void Deque::deleteRear()
{
    // If deque is empty then
    // 'Underflow' condition
    if (isEmpty())
        cout << "UnderFlow\n";

    // Deletes the node from the rear end and makes
    // the adjustment in the links
    else {
        Node* temp = rear;
        rear = rear->prev;

        // If only one element was present
        if (rear == NULL)
            front = NULL;
        else
            rear->next = NULL;
        free(temp);

        // Decrements count of elements by 1
        Size--;
    }
}

// Function to return the element
// at the front end
int Deque::getFront()
{
    // If deque is empty, then returns
    // garbage value
    if (isEmpty())
        return -1;
    return front->data;
}

// Function to return the element
// at the rear end
int Deque::getRear()
{
    // If deque is empty, then returns
    // garbage value
    if (isEmpty())
        return -1;
    return rear->data;
}

// Function to delete all the elements
// from Deque
void Deque::erase()
{
    rear = NULL;
    while (front != NULL) {
        Node* temp = front;
        front = front->next;
        free(temp);
    }
    Size = 0;
}

// Driver program to test above
int main()
{
    Deque dq;
    cout << "Insert element '5' at rear end\n";
    dq.insertRear(5);

    cout << "Insert element '10' at rear end\n";
    dq.insertRear(10);

    cout << "Rear end element: " << dq.getRear() << endl;

    dq.deleteRear();
    cout << "After deleting rear element new rear"
        << " is: " << dq.getRear() << endl;

    cout << "Inserting element '15' at front end \n";
    dq.insertFront(15);

    cout << "Front end element: " << dq.getFront() << endl;

    cout << "Number of elements in Deque: " << dq.size()
        << endl;

    dq.deleteFront();
    cout << "After deleting front element new "
        << "front is: " << dq.getFront() << endl;

    return 0;
}



Applications :

1. Can be used as both a stack and queue
2. Manage History of Actions in a limited size buffer
3. Steal Process Schedulling Algorithm
4. Implementing Priority Queue with two priorities
5. Maximum/Minimum of all subarrays of size k in an array

If we are required to design a DS such that we need to implement insertMin, insertMax,
getMin, getMax, extractMin, extractMax

WE can either use two stacks, one for min one for max, or we can use a simple Dequeue, using its one ends as min and other as max
*/

int main()
{
    cout << "Hey there!" << endl;
}