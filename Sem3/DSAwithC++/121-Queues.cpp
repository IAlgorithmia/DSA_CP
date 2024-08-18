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

Top mein we return rear
size mein size
push mein enqueue
pop mein jab tak 1 na reh jaaye tak tab dequeue karke q2 mein enqueue karte raho, last vale ko dequeue ardo q1 se then q2 ke saare q1 mein daaldo

3. Using only one queue

For Above Point 1 - 
First rear ko chod ke baaki ka queueu reverse karna padega after all is said and done

For Above Point 2 -
Final pure me pure queue ko reverse karna hoga, then well get the correct answer

Implementing Queue using Stack : 

1. Making Enqueue costly : 

Gotta save the most newly inserted element for rear, front ke liye top return akr denge, dequeue ke liye pop, enqueue ke liye pehle saare doosre mein daalo then fir new vala daaldo s1 mein then vo saare vapas le aao

2. Making Dequeue Costly : 

Gotta save the first element for front, rear ke liye top return kar denge, enqueue mein bas push kar denge, dequeue ke liye pehle last vale ke sivaye saare doosre mein bheejo, last nikalo then vapas le aao vo saare

3. Using only one stack (One recursion call stack) : 

For both the above implementations we can easily use the recursion call stack to get intended result

Reversing a Queue : 

1. Iterative : Stack mein daaldo dequeue karte karte then stack se enqueue karate raho

2. Recursive : Queue ke front ko store karo, fir dequeue karo, fir func call karo, (uski base condition ye rekhna is size == 1 then do nothing and return), fir nikala hua element vapas daldo


We will be given a number n, we have to find out n numbers in increasing order such that all of them have digits either 5 or 6

We take numbers as string here since for a large n, the number may go out of range
We solve the above by first adding 5 and 6 to the queue, after for n - 2 times, we keep dequeuing a number from the queue and add two elements to it, one after appending 5 to the end of the dequeued item and one after appending 6

5 6
6 55 56
55 56 65 66
56 65 66 555 556 and so on
 
Limit ke liye count rakhlo ya fir loop hi kam baar chalao

### DEQUEUES ###

Implementation : 

Doubly Linked List and Circular Array

Simple array implementation mein either we can make the pop costly (rear grows towards right and each time we deque something we gotta shift all the next elements leftwards) or the push costly (front grows towards right and each time we enque something we first gotta shif tall the items rightwards)
Circular array mein we can use the fact that rear = (front + size - 1) % cap - here size is the number of elements and cap is the limit, ismein upar vali bakchodi nahi hai enque mein rear ko badha do bas % cap karke and deque mein front ko badha do %cap karke, empty and full ki conditions check kar lena

Applications : 

1. Can be used as both a stack and queue
2. Manage History of Actions in a limited size buffer
3. Steal Process Schedulling Algorithm
4. Implementing Priority Queue with two priorities
5. Maximum/Minimum of all subarrays of size k in an array


*/

int main(){
    cout << "Hey there!" << endl;
}