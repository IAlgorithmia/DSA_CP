#include <bits/stdc++.h>
using namespace std;

/*
THIS CHAPTER IS AN EXCEPTION TO NORMAL WAY OF DOING THE COURSE BECAUSE : 

1. LESSER NUMBER OF QUESTIONS ASKED BASED ON LL
2. PROBLEMS OFTEN REQUIRE PREDEFINED STRUCTURES FOR LL, SO DOING ALL ON MY OWN PROVES TO BE FUTILE

BUT 

MOST PROBLEMS ASKED IN INTERVIEWS ARE FROM LL TOO

Explanation : In vectors or arrays, the insertion and deletion of elements in the middle or the end is very costly, gotta traverse the whole array for end and middle mein to har ek right side element ko shift bhi karna padega
1. Round Robin scheduling is very hard to do with arrays/vectors
https://www.geeksforgeeks.org/program-for-round-robin-scheduling-for-the-same-arrival-time/
2. Problem : Given a sequence of items, whenever we see an item x, we need to replace it with 5 instances of another item y. THis problem is hard to solve in arrays/vectors but easy in linked lists
3. Problem : We have multiple sorted sequences and we need to merge them frequently
Basically in problems mein linked list doesnt need extra space

Implementation is below

Har ek function mein head node pointer return karna hai
Here har video ki code nahi h, mostly simple hi hain

Circular linked list mein just last ka next first element hota hai, this can be singly or doubly
if singly then struct will be similar to that
doubly mein struct will be similar to that
single element mein next will be the same as the head

Advantages : 
1. We can traverse through the whole list from any node
2. Helps in implementation of round robin
3. Insertion at beginning and end just by maintaining a tail pointer

Disadvantages: 
1. Implementation of operations are complex

Iske max operation O(1) mein ho jate hain
Iski traversal mein we just check if the curr pointer has become equal to head or not, at that spot we stop, end condition just becomes curr->next != head instead of curr->next != null

Insertion at the beginning can be done in two ways : 
1. Represent your CLL by storing only the tail, insertion at beginning ke liye uske baad ek insert kardo and dont update tail
IMP IMP IMP 2. If you wanna store head only Make a new node, uska next = head ka next, head ka next = vo node, then swap their data so that the new node becomes the first node, and head becomes the second

Insertion at end ka bhi same h, ya to tail maintain karlo else : 
IMP IMP IMP ek naya node banao, temp->next = head->next, head->next = temp, then swap their data, then assign head to temp

head delete karne ke liye second node ka data first mein daalo, first->next = second->next, then delete second

kth delete karne ko kaha h to start and end aise deal karlena nad middle valo ke liye O(k) to lagega hi

Circular Doubly Linked List - previous of first node is last node next of last node is head

Advantages : 
We get all advantages of circular and doubly linked list, we can access last node in O(1) time

Disadvantages : 
We can access last node in constant time without maintaining tail pointer

Sorted Insert in a singly linked list : 
We are given a sorted linked list, we want to insert a new element at its correct position - traverse karte jaao, jab curr->next bada ho raha ho to udhar hi insert kardo beech mein, and corner cases handle karlo

Middle of a linked list : maintain three pointer, prev, slow and fast
fast = fast->next->next
slow = slow->next
prev should be one behind slow

Case 1 : total are odd (total ka pata hum fast ke sath sath ek variable increment karate hue kara sakte hain)

when fast reaches the last node (such that curr->next == NULL), then return the slow variable

Case 2 : total are even

when fast reaches null, return (prev->val + slow->val) / 2

Nth Node from end : 

Ya to aap ek loop mein total length nikal lo then pos from starting dekh lo then us node ko return kardo
else use two pointer, first adn second,
second ko pehle nth position pe pahunchao, fir first = head kardo,
now the difference between them is n, so jab second last mein pahunchegi, first will be at n from end, hence return first at that point

Reverse of a linked list : linking reverse karo instead of reversing the data

Iterative : 
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = NULL;
        while (curr != NULL){
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
};

HAVING A DUMMY NODE HELPS WITH THE TEST CASES AND ALL
THE ABOVE IS THE STANDARD, WE GOTTA MAKE THE CURR AND TEMP NODES OUTSIDE THE WHILE LOOP AND THE NEXT NODE INSIDE THE WHILE LOOP AND THEN RETURN THE PREV NODE

Recursive 1 : 
ListNode* f(ListNode* head){
    ListNode* resultHead = f(head->next); //the updated head of the rest of the linked list
    ListNode* tail = head->next; //the tail of the rest of the updated linked list
    tail->next = head; //the tail of the rest of the linked list should point to the current head
    head->next = NULL; //the current head should point to NULL
    return resultHead; //return the updated head of the linked list
}

Recursive 2 : 
ListNode* f(ListNode* curr, ListNode* prev){
    if (curr == NULL){
        return prev;
    }
    ListNode* temp = curr->next;
    curr->next = prev;
    return f(temp, curr);
}

Iterative - 3 pointers bana lo, second ka next first ko kardo then first ko third banado, second ka third->next and third ko third->next->next and repeat till end 
Recursive - Ismein ya above similar method se hi kardo, else reverse the linking of first n - 1 pointers first then add the nth at the end

Remove duplicates from a sorted SinglyLinkedList : curr and uska next agar not equal then move ahread, else remove the next one and repeat the process

Reversing the first K nodes of a SLL : Simple reverse vale ko run karo, break after k have been reversed, do this for each set of k

Node* reverseK(Node* head, int k){
    Node* curr = head, *prev = NULL;
    int count = 0;
    while (curr != NULL && count < k){
        Node* temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
        count++;
    }
    if (temp != NULL){
        head->next = reverseK(temp, k);
    }
    return prev;
}

Loop Detection :  
1. Either we can maintain an extra variable inside the LL structure itself by the name visited, curr->next ko check karte jao and see whether the visited is already true, if yes then there's a loop
2. Dummy Node - We can create a dummy node, jo jo visit karte ja rahe ho dummy node pe point karado, if you ever find a node which is already pointing to dummy node, return true
3. Set mein store karalo, if curr node mil gaya pehle se return true

Floyd Cycle : slow(moved 1 at a time) and fast(moved 2 at a time) two pointers maintained , if they ever become the same then theres a cycle
the condition to be checked whenever you are doing fast slow pointer method : fast != NULL && fast->next != NULL

Removing cycle from LL : WHen you find the meeting point using Floyd's Cycle, set slow = head, then move the fast and slow at the same speed, tehre will come a point when slow->next == fast->next, at that point fast is at the node whose Next has to be changed to NULL
The above can have some more variations  : Find length of loop, find first node of loop

//removing cycle
class Solution {
public:
    void detectCycle(ListNode *head) {
        ListNode *slow = head, *fast = head;
        do {
            if (fast == NULL || fast->next == NULL){
                return NULL;
            }
            slow = slow->next;
            fast = fast->next->next;
        } while (slow != fast);
        slow = head;
        while (slow->next != fast->next){
            slow = slow->next;
            fast = fast->next;
        }
        fast->next = NULL;
        return;
    }
};

//first above
class Solution {
public:
    int detectCycle(ListNode *head) {
        ListNode *slow = head, *fast = head;
        do {
            if (fast == NULL || fast->next == NULL){
                return NULL;
            }
            slow = slow->next;
            fast = fast->next->next;
        } while (slow != fast);
        int count = 0;
        do{
            slow = slow->next;
            count++;
        } while (slow != fast);
        return count;
    }
};

//second above - first node of loop
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head, *fast = head;
        do {
            if (fast == NULL || fast->next == NULL){
                return NULL;
            }
            slow = slow->next;
            fast = fast->next->next;
        } while (slow != fast);
        slow = head;
        while (slow != fast){
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};

Delete a node with only a pointer to it given : Next vale ki value abhi vale mein daaldo, next vala delete kardo LMAO

Maanlo we have defined a node as Node *temp = new Node(); or prev->next or anything else, if we want to delete it then what we can do is delete(node)

Segregating Odd and Even : two traversals mein pehle odd then even new ll mein add karke to ho hi jayega
For one traversal - we keep connecting even nodes together and odd nodes together as we traverse the node and in the end just do even end->next = odd ka head

Intersection Point of two LL : 
1 Method : First LL ko traverse karte hue saare node values set mein daaldo, second ko traverse karo afterwards jaise hi uska koi mile set mein return kardo
2 Method : Find length of 1, find length of second, do len1 - len2, move the larger LL curr from head (len1  - len2) steps forward, then move both the curr's at the same speed, htye will meet at the intersection point

Pairwise Swapping of Nodes : Ya to data swap karlo, else links change karlo as per requirement

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL || head->next == NULL){
            //if no node or one node
            return head;
        }
        ListNode* third_one = head->next->next;
        ListNode* prev = head;
        head = head->next;
        head->next = prev;
        while (third_one != NULL && third_one->next != NULL){
            //means I have a pair to swap so I must go ahead
            //so I must directly link prev's next to the other pair of the next pair that I have 
            prev->next = third_one->next;
            ListNode* temp = third_one->next->next;
            prev = third_one;
            third_one->next->next = third_one;
            third_one = temp;
        }
        //this might be that now the third_one is not present or just a single node is present, in any case
        //we need to assign this to the prev
        prev->next = third_one;
        return head; 
        //we return head because we switched the first two nodes and assigned head to the second one
    }
};

This loop iterates through the list, swapping adjacent nodes until there are no more pairs to swap.
prev->next is updated to point to the second node of the current pair.
prev is updated to the first node of the current pair.
next is a temporary pointer to store the node after the current pair.
The second node of the current pair's next pointer is updated to point to the first node, completing the swap.
curr is updated to the node after the current pair (next).
After the loop, prev->next is updated to point to curr, which is the remaining node (if any) that was not swapped.
The new head of the list is returned.

Cloning a LL with random pointers along with next : WTF is his see the video please

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node *curr = head;
        while (curr != NULL){
            Node *temp = curr->next;
            curr->next = new Node(curr->val);
            curr->next->next = temp;
            curr = temp;
        }
        curr = head;
        while (curr != NULL){
            curr->next->random = curr->random ? curr->random->next : NULL;
            curr = curr->next->next;
        }
        curr = head;
        Node* final_answer = NULL;
        if (head != NULL) final_answer = head->next;
        while (curr != NULL && curr->next != NULL){
            Node* temp = curr->next;
            curr->next =  curr->next->next;
            curr = temp;
        }
        return final_answer;
    }
};

LRU Cache Design : LRU means least recently used, the concept used is called as temporal locality, See Video

#include <unordered_map>

class DLLNode {
public:
    int key;
    int value;
    DLLNode* next;
    DLLNode* prev;
    DLLNode(int k, int val) {
        key = k;
        value = val;
        next = nullptr;
        prev = nullptr;
    }
};

class LRUCache {
public:
    DLLNode* head;
    DLLNode* tail;
    unordered_map<int, DLLNode*> record;
    int curr_elems, max_elems;

    LRUCache(int capacity) {
        max_elems = capacity;
        curr_elems = 0;
        head = nullptr;
        tail = nullptr;
    }
    
    int get(int key) {
        if (record.count(key)) {
            // Node found, move it to the head and return its value
            DLLNode* curr = record[key];
            moveToHead(curr);
            return curr->value;
        } else {
            return -1;
        }
    }
    
    void put(int key, int value) {
        if (record.count(key)) {
            // Node is already present, update its value and move it to the head
            DLLNode* curr = record[key];
            curr->value = value;
            moveToHead(curr);
        } else {
            // If cache is full, remove the tail node (least recently used)
            if (curr_elems == max_elems) {
                removeTail();
            }

            // Create a new node and add it to the head
            DLLNode* newNode = new DLLNode(key, value);
            addToHead(newNode);
            record[key] = newNode;
            curr_elems++;
        }
    }

private:
    void moveToHead(DLLNode* node) {
        if (node == head) {
            return;  // Node is already at the head
        }

        // Unlink the node
        if (node->prev) {
            node->prev->next = node->next;
        }
        if (node->next) {
            node->next->prev = node->prev;
        }

        // If it's the tail, update the tail pointer
        if (node == tail) {
            tail = node->prev;
        }

        // Move node to the head
        node->next = head;
        node->prev = nullptr;
        if (head) {
            head->prev = node;
        }
        head = node;

        // If the list was empty, set the tail to the new head
        if (!tail) {
            tail = head;
        }
    }

    void addToHead(DLLNode* node) {
        node->next = head;
        node->prev = nullptr;
        if (head) {
            head->prev = node;
        }
        head = node;

        if (!tail) {
            tail = head;
        }
    }

    void removeTail() {
        if (!tail) return;  // No nodes to remove

        record.erase(tail->key);

        DLLNode* temp = tail;
        if (tail->prev) {
            tail = tail->prev;
            tail->next = nullptr;
        } else {
            // If there's no previous node, the list is now empty
            head = tail = nullptr;
        }

        delete temp;
        curr_elems--;
    }
};

Merge Two Sorted Linked Lists : LL basically corner case handling and initialization handling ka khel hai, we initialize head, tail and b to the smaller node of the two starting options, then move b one step ahead. Now we just keep comparing a and b, smaller ko tail next kar denge, and tail ko usi pe le jayenge, and a tha smaller to a = a->next else with b

class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) 
  {
		// if list1 happen to be NULL
		// we will simply return list2.
		if(l1 == NULL)
        {
			return l2;
		}
		
		// if list2 happen to be NULL
		// we will simply return list1.
		if(l2 == NULL)
        {
			return l1;
		} 
		
		// if value pointend by l1 pointer is less than equal to value pointed by l2 pointer
		// we wall call recursively l1 -> next and whole l2 list.
        ListNode* result;
		if(l1 -> val < l2 -> val)
        {
            result = l1;
			result->next = mergeTwoLists(result -> next, l2);
		}
		// we will call recursive l1 whole list and l2 -> next
		else
        {
            result = l2;
			result->next = mergeTwoLists(l1, result -> next);        
		}
        return result;
	}
};	

 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == NULL){
            return list2;
        }
        if (list2 == NULL){
            return list1;
        }
        ListNode *head, *curr;
        if (list1->val < list2->val){
            head = list1;
            list1 = list1->next;
        }
        else{
            head = list2;
            list2 = list2->next;
        }
        curr = head;
        //lets maintain list1 and list2 as the pointer we need to compare as of now
        while (list1 && list2){
            if (list1->val < list2->val){
                ListNode *temp1 = list1->next;
                curr->next = list1;
                list1->next = list2;
                list1 = temp1;
                curr = curr->next;
            }
            else{
                ListNode *temp1 = list2->next;
                curr->next = list2;
                list2->next = list1;
                list2 = temp1;
                curr = curr->next;
            }
        }
        if (list1){
            curr->next = list1;
        }
        if (list2){
            curr->next = list2;
        }
        return head;
    }
};



Palindrome LL : Reverse the second half of the LL, then just traverse the two halves, if at any point they diverge return -1, else return true

 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) {
            return true;
        }

        // Find the middle of the list
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Reverse the second half of the list
        ListNode* prev = NULL;
        ListNode* curr = slow;
        while (curr) {
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }

        // Compare the first half and the reversed second half
        ListNode* left = head;
        ListNode* right = prev;
        while (right) {
            if (left->val != right->val) {
                return false;
            }
            left = left->next;
            right = right->next;
        }

        return true;
    }
};

FLATTENING A LINKED LIST : https://www.geeksforgeeks.org/problems/flattening-a-linked-list/1

Node* mergeTwoLists(Node* head1, Node* head2) {
    // If one of the linked lists is empty, return the other
    if (head1 == NULL)
        return head2;

    if (head2 == NULL)
        return head1;

    Node* result;
    // Compare the nodes and merge them in sorted order
    if (head1->data < head2->data) {
        result = head1;
        // Recursively merge the rest of the nodes
        result->bottom = mergeTwoLists(head1->bottom, head2); //Trust
    } else {
        result = head2;
        // Recursively merge the rest of the nodes
        result->bottom = mergeTwoLists(head1, head2->bottom); //Trust
    }

    return result;
}

Node *flatten(Node *head) {
    if(!head)
        return head;

    Node* temp = flatten(head->next);
    
    return mergeTwoLists(head, temp);
}

*/

//Singly
struct Node{
    int value;
    Node* next;
    Node (int x){
        value = x;
        next = NULL;
    }
    Node (){
        value = NULL;
        next = NULL;
    }
}

//Doubly
struct Node{
    int value;
    Node* next;
    Node* prev;
    Node (int x){
        value = x;
        next = NULL;
        prev = NULL;
    }
    Node (){
        value = NULL;
        next = NULL;
        prev = NULL;
    }
}

/*
Advantages of doubly linked list : 

1. Can be traversed in both directions
2. Insertion at end can be done in O(1) time since we maintain an extra pointer here known as tail along with head

Disadvantages of doubly linked list : 

1. Extra space for prev
2. Code becomes more complex
*/

int main(){
    Node* head = new Node();
    Node* temp1 = new Node();
    Node* temp2 = new Node();
    //The above two lines can be written as 
    // head->next = new Node();
    // head->next->next = new Node();
    head->next = temp1;
    temp1->next = temp2;
    //head, temp1, temp2 teeno hi pointer to Node type ke hain, difference is that node banane ke liye humein ye temp cheejein chahiye, inko address mil jayega vo hum save kara lenge, uske bad their job done. permanent need sirf Address sirf head ka chahiye 
    cout << "Hey there!" << endl;
}