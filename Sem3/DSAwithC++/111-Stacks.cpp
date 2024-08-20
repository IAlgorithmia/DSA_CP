#include <bits/stdc++.h>
using namespace std;

/*

Monotonic stack is just a stack which either follows an order
strictly increasing or strictly decreasing, maybe baaki bhi kar sake idk

MONOTONIC TYPE STACK IS USED IN PLACES LIKE NEXT GREATER ELEMENT FOR EACH
ELEMENT TYPE OF QUESTIONS

MONOTONIC STACK === ORDER PRESERVING STACK

Explanation : isEmpty, push, pop, peek, size
Situations : overflow, underflow

In arrays and vectors, push ad pop operations are O(1) if done on the right side, and left side for singly linked list since we are always given the head of the LL, doubly ho to its equal both ways

Applications of stack : 

Function Calls
Parenthesis Check
Reversing Items
Infix to Postfix/Prefix
Evaluation of Postfix/Prefix
Stock Span Problems and its variations
Undo/Redo and Forward/Backward

CPP Stack : 
push pop top empty size

stack<int> myStack;
myStack.push(10);
myStack.push(4);
myStack.push(213);
myStack.push(2);
myStack.push(-99);
cout << myStack.top() << endl;

//Incorrect traversal way
for (auto i : myStack){
    cout << i << endl;
}

//Correct traversal way
while (!myStack.empty()) {
   cout << myStack.top() << endl;
   myStack.pop();
}

pop function doesnt return the removed element here in CPP

Implementing two stacks in an array : 

Lets say size is n
cap = n
top1 = -1
top2 = n

push1 mein if (top1 < top2 - 1) then push and arr[++top1] pe daaldo new element
push2 mein if (top1 < top2 - 1) then push and arr[--top2] pe daaldo new element

pop1 mein if top1 > -1 then remove and top1-- else error
pop2 mein if top2 < n then remove top2++ else error

*/

//creating array stack struct although we have the built-in data type

struct myStackArray{
    int *arr; //or we can write arr[] too
    int cap;
    int top;
    myStackArray(int c){
        cap = c;
        arr = new int[cap];
        top = -1;
    }
    void Push(int x){
        //handle case when stack is full
        arr[++top] = x;
    }
    int Pop(){
        //handle case when stack is empty, return -1
        int res = arr[top--];
        return res;
    }
    int Peek(){
        //handle case when stack is empty, return -1
        return res[top];
    }
}

//creating linked listf stack struct although we have the built-in data type

struct Node{
    int val;
    Node* next;

    Node(int d){
        val = d;
        next = NULL;
    }
    //other things for node of SLL
}

struct myStackSLL{
    Node* head;
    int size;
    myStackSLL(){
        head = NULL;
        size = 0;
    }
    void push(int x){
        //this operation is basically insert at beginning in SLL
        Node* temp = new Node(x);
        temp->next = head;
        head = temp;
        size++;
    }
    int pop(){
        //remove from beginning in a SLL
        if (!head){
            return INT_MAX;
        }
        int res = head->data;
        Node* temp = head;
        head = head->next;
        delete(temp);
        size--;
        return res;
    }
    //similarly we can have size, isEmpty and peek
}

// Implement K stacks in an array : This one is fucking tricky

struct KStacks{
    int *arr;
    int *top;
    int *next;
    int k, freeTop, cap;
    KStacks(int k1, int n){
        k = k1;
        cap = n;
        arr = new int[cap];
        top = new int[k]; //this will maintain the tops informations
        next = new int[cap];
        freeTop = 0
        // initialize all elements of top to -1
        // initialize all all elements of next to i + 1 where i is the index, except the last element, initialize that as -1
        //freetop next array ka index specify kar raha hai, nothing to do with stack's tops
        //bhai freetop 0 hai, next ke oth ko access karega vo naya top dega, freeTop is now 1, and top array mein actual top for 0th array is now 0 thats why we gotta store the old freeTop
        //next means below it
        //next basically tells us pushing ke time that next element konse index pe daalna hai, and popping ke time ke top ko konsa index assign karna hai ab
        //
    }

    void push(int x, int sn){
        //Handle overflow case

        //The order in which we do the below operations is very important
        int i = freeTop;
        freeTop = next[i];
        next[i] = top[sn];
        top[sn] = i;
        arr[i] = x;
    }

    void pop(int sn){
        //Handle overflow case

        //The order in which we do the below operations is very important
        int i = top[sn];
        top[sn] = next[i];
        next[i] = freeTop;
        freeTop = i;
        return arr[i];
    }
};

int main(){
    cout << "Hey there!" << endl;
}