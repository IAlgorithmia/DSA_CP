#include <bits/stdc++.h>
using namespace std;

/*
Explanation : BST begins

All keys are typically considered as distinct, its a linked data structure

Search delete insert and find closest are O(logn) in the BST which is balanced, in worst case it can become O(n) and as a generallization it is O(height), sorted traversal is O(n)

Search operation in BST recursive or iterative is easy asf, both are O(h) and aux space in resursion is O(h) h = height

Similarly insert operation is recursive or iterative, usmein just if NULL node mila to insert kar denge instead of returning NULL 

Deletion for a leaf node is simple asf, for a node with only one child we just transfer that child to the aprent node, for a node with two children we can either pick the lower closest among all its children ot the upper closest, its our choice, I shall pick the upper closest all the time. Closest greater value in BST is inorder successor

Recursive : 

Node* getSuccesor(Node* node){
    Node* curr = node;
    curr = curr->right;
    while (curr != NULL && curr->left != NULL){
        curr = curr->left;
    }
    return curr; this is the inorder successor
}

Node* delNode(Node* node, int x){
    if (node == NULL){
        return NULL;
    }

    if (node->key > x){
        delNode(node->left, x);
    }
    else if (node->key < x){
        delNode(node->right, x);
    }
    else{
        if (node->left == NULL){
            Node* temp = node->right;
            delete node;
            return temp; child linked to the parent of the node which was deleted
        }
        else if (node->right == NULL){
            Node* temp = node->left;
            delete node;
            return temp; child linked to the parent of the node which was deleted
        }
        else{
            Node* temp = getSuccessor(node, x);
            node->key = temp->key;
            node->right = delNode(node->right, node->key);
        }
        return node;
    }
}

Complexitry of the above code is O(h)

Floor of a BST in binary tree means the closest smaller or equal to value
We will simply perform the BST search, if the current node is equal to the required node, then the node itself will be returned, if that node is larger then we update the curr as curr->left, if it is smaller, we set res = curr and curr = curr->right, because the current root is also a candidate for floor

Ceil of a BST in binary tree means the closest greater or equal to value 
Same as the above, just the conditions reversed

Self balancing BST, keep the height as O(logn) for the tree
Same set of keys can give different BST heights
If we know the keys in advance its easy to make perfectly balanced BST, put the keys in sorted order, take the middle and make it the root, then do the same thing for its left part and right part to build the left and right subtrees
When we dont know the keys in advance, we check whether the insertion or deletion operation is making the tree unbalanced, if it is then we do restructuring which is basically right or left rotate the bst 
The main idea here is the rotation operation which requires only O(1) time

There are two types of self balancing trees
AVL Tree and Red Black tree, RB is used more, in both of these trees, the search is same as search in BST

i[arr] = *(i + arr) love babbur

AVL Tree = The difference between the left subtree and right subtree for each node should not be greater than 1, this difference is known as balance factor
Whenever we insert a new node, we just need to check for any imbalance in the ancerstors of the position where we insert the node, since only they are suceptible 
If there is a disturbance (balance factor > 1) then we perform one or more of : 
Single Rotations 
Left Left - right
Right Right - left
Double Rotations
Left Right - left then right
Right Left - right then left

Ye structure of ancestors h in the case of imbalanced insertion, uske hisab se rotations hongi

Delete operations are complex

For AVL tree, h < clog(n + 2) base 2 + b, c is 1.4405, b is -1.3277

RBT is loose, not strict loose, disadvantage is worst case height becoming high, and search becoming costly
If I have many elements to insert, and few to search then RBT
If reverse then AVL Tree

Rules are  : 

Every node is either red or black
Root is always black
No two consecutive reds
Black height of a node should be same through all descendent leaves ie number of black nodes from a node to all of its descendent leaves should be the same

The condition that arises here is that we cannot have more then twice the nodes between root and closest leaf in the path from root to farthest leaf 

In case of imbalancing we perform either recoloring and if that doesnt work then we perform rotations

Applications of self balancing BST : 

To maintain sorted set of data
Doubly ended priority queue - for eg to get both min and max
Sorting an array
To solve smaller/greater in a stream
Floor/Ceil/Greater/Smaller in a stream

Sets in CPP are based on red black tree - along with that, it has rbegin, rend (r for reverse), cbegin, cend (c for constant)
lower_bound(x) - this returns iterator to that element if present, if not then the element just greater than x, if x is greater than the greatest element in the set, it returns s.end
upper_bound(x) - this returns iterator to the next greater element if that element is present or not present, if x is greater than the greatest element in the set, it returns s.end
the abovw two and insert find erase(element) anc count are O(logn) time complexity
erase(iterator) does function in O(1)
applications - doubly ended priority queue, sorted stream of data

Maps in CPP are also based on RBT
at this throws an error if the key is not present, insert, [] operator this creates a new key if key not present, size, empty, clear, begin, end 
This too has, find, count, lower_bound, upper_bound, erase

In find function we get the address
In count function we either get 1 or 0

count ,find, erase, insert, [] are all logn time complex
applications - doubly ended priority queue with pair data, sorted stream of pair data 

Ceiling of an array : 
For each element we need to find the smallest number greater than that number on its left side
We saw that lower_bound gives us the ceiling of the BST
In CPP, a self balancing binary search tree is represented by set, hashing is done through unordered_set

so we first print -1 for the first element always, after that we create a set and insert the first element into it
after that, from index 1 to n - 1, we check whether s has ceiling(arr[i]) using simply lower_bound, if yes we print it else -1, and then in all cases insert arr[i] into s

Finding out kth smallest node : we make use of augmented BST here, in each node we store the number of nodes in its left subtree
Say that number is lcount, we now compare k with lcount + 1 : 
if same, we return the root
if lcount + 1 is greater, we go to the left subtree and recur
if lcount + 1 is smaller, we go to the right subtree after modifying k = k - lcount - 1 and recur

It is very easy to maintain this lcount variable because as we are inserting new elements, we just perform search and at whichever point we had to go to the left subtree, we will increment the lcount for that node
Same thing with deletion

Check whether a tree is a BST or not : 
1. Inefficient solution - For each node find out the maximum from the left subtree and minimum from the right subtree, the correct order should be the maximum < root value < the minimum
2. Efficient - For each node we pass a range, for the root it is -infinite to +infinite, going left subtree, we change the upper limit as the roots value, and for the right side, we change the minimum of the range to roots value

bool isBST(Node* root, int min, int max){
    if (root == NULL){
        return true;
    }
    return (root->key > min && root->key < max && isBST(root->left, min, root->key) && isBST(root->right, root->key, max));
}

3. Efficient : The key idea is that the inorder array traversal of a BST will be sorted, we can either create an array recursively and then check whether it is sorted or not or we can just maintain a previous value variable
int prev = INT_MIN;
bool isBST(Node* root){
    if (root == NULL){
        return true;
    }
    if (isBST(root->left) == false){
        return false;
    }
    if (root->val < prev){
        return false;
    }
    prev = root->key;
    return (isBST(root->right)); // right last mein kar rahe hain because for the current node, we just gotta check its left part
}

Fix BST with two nodes swapped : 
First we do this for an array, then for the tree without the aux array

prev = INT_MIN
first = INT_MIN
second = INT_MIN

for (i from 0 to n - 1){
    if (arr[i] < prev){
        if (first == INT_MIN){
            first == prev;
        }
        second = arr[i];
    }
    prev = arr[i]
}

swap(first, second)

Now we can have some references first second and previous to solve the above problem for the trees
For the trees we perform inorder search, while doing that if we see a violation, we do the same thing as arrays

Node* prev = NULL, first = NULL, second = NULL;

void fixBST(Node* root){
    if (root == NULL){
        return NULL;
    }
    fixBST(root->left); //since inorder 
    if (root->key < prev){
        if (first == NULL){
            first = prev;
        }
        second = root->key;
    }
    prev = root;
    fixBST(root->right);
}

Pair with given sum in BST : 

Method 1 : Form n array from inorder, and use two pointers method, O(n) twice - Theta(n) actually

Method 2 : Hashing

boolean isPairSum(Node* root, int sum, unordered_set<int> s){
    if (root == NULL){
        return false;
    }
    if (isPairSum(root->left, sum, s) == true){
        return true;
    }
    if (s.find(sum - root) != s.end()){
        return true;
    }
    else{
        s.insert(root);
    }
    return isPairSum(root->right, sum, s);
}

The above approach can also be used for a normal binary tree :)

Vertical Sum in a binary tree : Based on the horizontal distance from the root, same vertical line mein sabka sum karna hai
What we do is we create a map and using any of the traversals, put key as the horizontal distance and value as the node value. If the key already exists then we add current to existing else we insert the new key value pair
Since data is stored in ordered manner, we print out the values in that fashion

Vertical traversal in a binary tree : 

Almost same fkin thing as above, just that we use vectors as values in the maps, and use level order traversal, then we just print the arrays (Values) of the keys in ascending order

void Traversal(Node* node){
    map<int, vector<int>> m;
    queue< pair<Node*, int>> q;
    q.insert({node, 0});
    while (q.empty() == false){
        auto p = q.front();
        Node* curr = p.first;
        int h = p.second;
        m[h].push_back(curr->key);
        q.pop();
        if (curr->left != NULL){
            q.insert({curr->left, h - 1});
        }
        if (curr->right != NULL){
            q.insert({curr->right, h + 1});
        }
    }
    //print map contents now
}

Top view of a binary tree : Do level order traversal, in the map, if the key is already present do nothing, else insert that key value pair
Bottom view of a binary tree : Do level order traversal, in the map, set the key with the current value, pehle thi to updted, nahi thi to added

*/


int main(){
    cout << "Hey there!" << endl;
}