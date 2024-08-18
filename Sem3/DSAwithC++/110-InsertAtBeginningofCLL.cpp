#include <bits/stdc++.h>
using namespace std;

/*
Explanation : 
*/

struct Node{
    int value;
    Node* next;
    Node* prev;
    Node (int x){
        value = x;
        next = NULL;
        prev = NULL;
    }
};

Node *reverseDoublyLL(Node* head){
    if ((head->next == NULL) || (head == NULL)){
        return head;
    }
    Node* curr = head;
    Node* temp;
    while (curr != NULL){
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;
        curr = curr->prev;
    }
    return temp->prev;
}

int main(){
    cout << "Enter how many elements you want to add in LL : " << endl;
    int n;
    cin >> n;
    cout << "Enter the elements : " << endl;
    int value;
    cin >> value;
    Node* head = new Node(value);
    Node* previousNode = head;
    for (int i = 1; i <= n - 1; i++){
        cin >> value;
        Node* temp = new Node(value);
        temp->prev = previousNode;
        previousNode->next = temp;
        previousNode = temp;
    }
    Node* curr = head;
    cout << "The created linked list is : " << endl;
    while (curr != NULL){
        cout << curr->value << " ";
        curr = curr->next;
    }
    cout << endl;
    head = reverseDoublyLL(head);
    curr = head;
    cout << "The linked list after operation is : " << endl;
    while (curr != NULL){
        cout << curr->value << " ";
        curr = curr->next;
    }
    cout << endl;
}