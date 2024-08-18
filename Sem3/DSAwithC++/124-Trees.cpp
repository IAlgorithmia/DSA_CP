#include <bits/stdc++.h>
using namespace std;

/*
Explanation : Hierarchy, Internal Nodes means non leaf nodes

Applications : 

Hierarchal Data
Folder Structure
Inheritance
HTML Content (DOM)
BST 
Binary Heap (Priority Queues)
B and B+ trees
Spanning and Shortest Path Trees
Parse Tree, Expression Tree

Other trees : 

Trie
Suffix tree
Binary Index tree
Segment Tree

Binary Tree = Tree with at most 2 children
They can also be represented as arrays, although linked list representation is the most popular

Tree traversals : 
Breadth First Traversal (Level order traversal)
Depth First Traversal - 
DFT is basically recursion, we gotta do three things : Traverse Root, Traverse Left Subtree, Traverse Right Subtree
Inorder (Left Root Right), Preorder (Root Left Right), Postorder (Left Right Root)
*/

// LinkedList Structure
struct Node{
    int key;
    Node* left;
    Node* right;
    Node(int k){
        key = k;
        left = NULL;
        right = NULL;
    }
}

// Inorder traversal O(n) complexity
void func(Node* head){
    if (head != NULL){
        func(Node->left);
        cout << head->key << " ";
        func(Node->right);
    }
}

// Preorder traversal O(n) complexity
void func(Node* head){
    if (head != NULL){
        cout << head->key << " ";
        func(Node->left);
        func(Node->right);
    }
}

//MORRIS TRAVERSAL FOR PRE ORDER : https://www.geeksforgeeks.org/morris-traversal-for-preorder/

// Postorder traversal O(n) complexity
void func(Node* head){
    if (head != NULL){
        func(Node->left);
        func(Node->right);
        cout << head->key << " ";
    }
}

//Height of a binary tree (my solution)
int max_height = INT_MIN;
int func(Node* node, int height){
    //To be called with head and height = 1;
    if (!node){
        return 0;
    }
    if (node->left){
        func(node->left, height + 1);
    }
    if (node->right){
        func(node->right, height + 1);
    }
    if (!node->left && !node->right){
        max_height = max(max_height, height);
        return;
    }
}


//Height of a binary tree (gfg solution) O(n) auxillary time and O(h) auxillary space
int func(Node* root){
    if (!root){
        return 0;
    }
    else{
        return (max(func(root->left), func(root->right)) + 1);
    }
}

//Print nodes at distance k far from root, distance can be seen as the number of edges between the nodes
void distanceK(node, distance){
    if (node is null){
        return
    }
    if (distance is 0){
        print node
        return
    }
    distanceK(node->left, distance - 1)
    distanceK(node->right, distance - 1)
}

//Level order traversal Time complexity is Theta(n), Space complexity is O(n) well actually at max we will have one entire level in the queue at a time so width of binary tree
void printLevels(Node* root){
    queue<Node*> q;
    q.push(root->key);
    while(q.empty() == false){
        Node* curr = q.front();
        cout << curr->key << " ";
        q.pop();
        if (curr->left){
            q.push(curr->left);
        }
        if (curr->right){
            q.push(curr->right);
        }
    }
}
//Level order traversal Line by Line
//Method 1
void printLineByLine(Node* root){
    if (!root){
        return NULL;
    }
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while (q.size() > 1){
        Node* curr = q.front();
        q.pop();
        if (curr == NULL){
            cout << endl;
            q.push(NULL);
            continue;
            //humein null mila means that ek level complete hogya hai, that means uske saare children dal chuke hain, so we need to add another NULL, since we are seperating each level with NULL :) 
        }
        cout << curr->key << " ";
        if (curr->left != NULL){
            q.push(curr->left);
        }
        if (curr->right != NULL){
            q.push(curr->right);
        }
    }
}

//Method 2
void printLevels(Node* root){
    queue<Node*> q;
    q.push(root->key);
    while(q.empty() == false){
        int count = q.size();
        //har level ke liye ke for loop chala dia
        for (int i = 0; i < count; i++){
            Node* curr = q.front();
            cout << curr->key << " ";
            q.pop();
            if (curr->left){
                q.push(curr->left);
            }
            if (curr->right){
                q.push(curr->right);
            }
        }
        cout << endl;
        
    }
}

//Size of a binary tree
int getSize(Node* root){
    if (root == NULL){
        return 0;
    }
    return (getSize(root->left) + getSize(root->right) + 1);
}

//Maximum in binary tree
int getMax(Node* node){
    if (node == NULL){
        return INT_MIN;
    }
    return max(node->key, max(getMax(node->left), getMax(node->right)));
}

//Print left view of a binary tree
//Using the above Method 1, we can just print whatever element is just right of NULL element in the queue and then skip all the others
//Using the above Method 2, we can just add a condition inside the for loop if i = 0, only then print the node->key

//Method 3
int maxLevel = 0;
void leftView(Node* node, int level){
    if (node == NULL){
        return;
    }
    if (level > maxLevel){
        maxLevel = level;
        cout << node->key << " ";
    }
    leftView(node->left, level + 1);
    leftView(node->right, level + 1);
}
// call the above function with leftView(root, 1);
// Right view pucha hota to NULL ke just left vala karte instead of right in method 1, i = 0 ki jagah i = count ka karte in method 2, left se pehle right call kar dete in method 3

//Children Sum Property - for allthe nodes the sum of its immediate children should be equal to it for all the nodes
int func(Node* node){
    if ((node == NULL) || ((node->left == NULL) && (node->right == NULL))){
        return true;
    }
    int sum = 0;
    if (node->left != NULL){
        sum += node->left->val;
    }
    if (node->right != NULL){
        sum += node->right->val;
    }

    if ((func(node->left) && func(node->right)) && (sum == node->val)){
        return true;
    }
    else{
        return false;
    }
}

//Height Balanced subtree condition - the height difference between the left and right subtree must be less than or equal to 1 for all the nodes

//Method 1 - O(n square)
bool balanced(Node* node){
    if (node == NULL){
        return true;
    }
    int lh = height(node->left);
    int rh = height(node->right);
    return (abs(lh - rh) && balanced(node->left) && balanced(node->right));
}

//Method 2 - This involves returning either height of the subtree if it is balanced else -1

bool isBalanced(Node* node){
    if (node == NULL){
        return 0;
    }
    int lh = isBalanced(node->left);
    int rh = isBalanced(node->right);
    if ((lh == -1) || (rh == -1) || (abs(lh - rh) > 1)){
        return -1;
    }
    else{
        return max(lh, rh) + 1;
    }
}

//Maxwidth of binary tree : Level Order Traversal Line by Line Method 1 mein NULLs ke beech max distance nikal lo, or Method 2 mein max count nikal lo


//Convert Binary tree to a doubly linked List - In an inorder fashion 
//The idea is to go to traverse in an inorder fashion and do current->prev = previous and previous->next = current except for the first one

Node* previous = NULL;
Node* BTtoDLL(Node* node){
    if (node == NULL){
        return NULL;
    }
    Node* head = BTtoDLL(node->left);
    if (prev == NULL){
        head = node;
    }
    else{
        node->left = previous;
        previous->right = node;
    }
    previous = node;
    BTtoDLL(node->right);
    return head;
    //Mere hisab se this last line should be return, head should be a global variable and it should be set to node inside the previous = NULL condition only because no other application is there
}

//We can construct a binary tree from given Inorder and one other traversal of the tree, preorder or postorder.
//Constructing from Inorder and preorder - 

//We obviously construct the tree root to root, and since we already have the preorder traversal, we use a pre index and increment it one by one

int preIndex = 0;
Node* cTree(vector<int> in, vector<int> pre, int is, int ie){
    if (is > ie){
        return;
    }
    //ie is inorder end, and is is inorder start
    Node* root = new Node(pre[preIndex++]);

    int inIndex;
    for (int i = is; i <= ie; i++){
        if (in[i] == root->key){
            inIndex = i;
            break;
        }
    }
    root->left = cTree(in, pre, is, inIndex - 1);
    root->right = cTree(in, pre, inIndex + 1, ie);
    return root;
}

//As a challenge try to create the tree from inorder and postorder

//Print spiral traversal of the tree
//Method 1
void printSpiral(Node* node){
    if (node == NULL){
        return;
    }
    queue<Node*> q;
    stack<int> s;
    bool reverse = false;
    q.push(node);
    while (q.empty() == false){
        int count = q.size();
        for (int i = 0; i < count; i++){
            Node* curr = q.front();
            q.pop();
            if (reverse){
                s.push(curr->val);
            }
            else{
                cout << curr->val << " ";
            }
            if (curr->left != NULL) {q.push(curr->left);}
            if (curr->right != NULL) {q.push(curr->right);}
        }
        if (reverse){
            while (s.empty() == false){
                cout << s.top() << " ";
                s.pop();
            }
        }
        reverse = !reverse;
    }
}

//Method 2
/*THis is a two stack s1 and s2 solution: 

1. Push the root into s1
2. While (s1 is not empty) || (s2 is not empty) :
       
       While (s1 is not empty):
           pop s1 top, display it, and push its children into s2
        While (s2 is not empty):
           pop s2 top, display it, and push its children into s1

WRITE THE CODE FOR THE ABOVE IN REVISION
*/

//Diameter of a binary tree : 

// The idea is to calculate the value (1 + lh + rh) for each node in the tree and then return the max value among all nodes

//The naive solution is to compute the above for each node in the tree as follows : 

/*
int func(Node* node){
    if node is null return 0
    int lh = height(node->left)
    int rh = height(node->right)
    return max((lh + rh + 1), max(func(node->left), func(node->right)))
}
*/
//Above is O(n square)

//Better solution is to precompute the heights of the nodes of the tree and store them in an unordered map <Node* ,int> then heights can be called in O(1), hence overall o(n) but auxillary space

//best solution :
int res = 0;
int func(Node* root){
    if (!root){
        return 0;
    }
    else{
        int lh = func(root->left);
        int rh = func(root->right);
        res = max(res, lh + rh + 1);
        return max(lh, rh) + 1;
    }
}

//LCA of a binary tree - This can also be useful for finding out the distance between two nodes in a tree

//Naive solution - We can create an unordered map of Node*, vector<int> and for each recursive call we can pass down the array to be added after the element itself is added, liek if the element is 10 and its parents are 50 40 30 20 (root to parent), then in the map we will put the values 50 40 30 20 10 for that Node* key, after the loop since the map was global we will findout the common node by simply traversing them simultaneously, the last common node we shall return o(n) h ye last traversal be careful, worst case mein ye map banane wala cheez O(n square ho jayegi) this was my solution

//Better Solution : Instead of map, create only the required paths

bool findPath(Node* root, vector<Node*> &p, int n){
    if (root == NULL){
        return false;
    }
    p.push_back(root);
    if (root->key == n){
        return true;
    }
    if (findPath(root->left, p, n) || findPath(root->right, p, n)){
        return true;
    }
    p.pop_back();
    return false;
}

Node* lca(Node* head, int n1, int n2){
    vector<Node*> path1, path2;
    if (findPath(root, path1, n1) == false || findPath(root, path2, n2) == false){
        return NULL;
    }
    for (int i = 0; i < path1.size() - 1; i++){ 
        if (path1[i + 1] != path2[i + 1]){
            return path1[i];
        }
    }
    return NULL;
}

// The above has time complexity Theta(n) + Theta(n) + O(n)
//best solution : 

/*
Requires one traversal and theta(n) aux space for recursive call stack
Assumes that both n1 and n2 are present

Idea : for each node we have the following cases

1. It is equal to either n1 or n2 - return that node
2. One of its subtrees contains n1 and other contains n2 - means we are at the LCA, return that node
3. One of its subtrees contains both n1 and n2 - return whatever the child returns
4. None of its subtrees contains n1 or n2 - wrong move, go back, ie return NULL

*/

Node* lca(Node* root, int n1, int n2){
    if (root == NULL){
        return NULL;
    }
    if (root->key == n1 || root->key == n2){
        return root;
    }
    Node* lca1 = lca(root->left, n1, n2);
    Node* lca2 = lca(root->right, n1, n2);

    if (lca1 != NULL && lca2 != NULL){
        return root;
    }
    if (lca1 != NULL){
        return lca1;
    }
    else{
        return lca2;
    }
}

//Burn a binary tree from leaf - We just need to find the farthest node from the target node, that farthest node will be reachable through one of the ancestors. I need to find the ditance from the target node to that ancestor and the height of the subtree which does not have that node, add them, and return the max value among all ancestor nodes

int res = 0;
int burnTime(Node* root, int leaf, int &dist){
    if (root == NULL){
        return 0;
    }
    if (root->key == leaf){
        dist = 0;
        return 1;
    }
    int ldist = -1;
    int rdist = -1;
    int lh = burnTime(root->left, leaf, ldist);
    int rh = burnTime(root->right, leaf, rdist);
    if (ldist != -1){
        dist = ldist + 1;
        res = max(res, dist + rh);
    }
    else if (rdist != -1){
        dist = rdist + 1;
        res = max(res, dist + lh);
    }
    return max(lh, rh) + 1;
}

//Count nodes in complete binary tree

//Simple method se O(n) mein kar sakte hain but best method is of O(logn * logn)

int countNodes(Node* root){
    if (root == NULL){
        return 0;
    }
    int lh = 0;
    int rh = 0;
    Node* curr = root;
    while(curr != NULL){
        lh++;
        curr = curr->left;
    }
    curr = root;
    while(curr != NULL){
        rh++;
        curr = curr->right;
    }
    if (lh == rh){
        return (pow(2, lh) - 1);
    }
    else{
        return 1 + countNodes(root->left) + countNodes(root->right); //the traditional method when our trick doesnt work
    }
}

//Time complexity will be the best when the tree is a perfect binary tree / fully filled binary tree - Theta(height of tree)
//In other cases T(n) < T(2n/3) + Theta(n), ie O(log n base 3 / 2 * logn base 2 )

//Serialization

// Converting a binary tree into array or string in such a way that it can be constructed back is called Serialization, reverse is deserialization
//Application is in networking, transfer requires serial data

//ONe method is to do the preorder traversal and mark the NULL positions as -1

//Serialization : 

const int empty = -1;

void serialize(Node* root, vector<int> &vect){
    if (root == NULL){
        vect.push_back(empty);
        return;
    }
    vect.push_back(root->key);
    serialize(root->left, vect);
    serialize(root->right, vect);
}

//Deserialization

const int empty = -1;

int index = 0;

Node* deserialize(vector<int> &vect){
    if (index == vect.size()){
        return NULL;
    }
    int val = vect[index];
    if (val == empty){
        return NULL;
    }
    index++;
    Node* root = new Node(val);
    root->left = deserialize(vect);
    root->left = deserialize(vect);
    return root;
}

//Both the above take O(n) time

//Iterative inorder : 

//Obviously we need to have access of the previous nodes to go back to them after the current processing is finished, thus we need stack

void iterativeInorder(Node* root){
    stack<int> s;
    Node* curr = root;
    while (curr != NULL || s.empty() != false){
        while(curr != NULL){
            s.push(curr);
            curr = curr->left;
        }
        curr = s.top();
        s.pop();
        cout << curr->val << " ";
        curr = curr->right;
    }
}

//Iterative Preorder

void iterativePreorder(Node* root){
    if (root = NULL){
        return;
    }
    stack<Node*> st;
    st.push(root);
    while (st.empty() == false){
        Node *curr = st.top();
        cout << curr->key << " ";
        st.pop();
        if (curr->right != NULL){
            st.push(curr->right);
        }
        if (curr->left != NULL){
            st.push(curr->left);
        }
    }
}

//Better version

void iterativePreorder(Node* root){
    if (root = NULL){
        return;
    }
    stack<Node*> st;
    Node* curr = root;
    while (curr != NULL || st.empty() == false){
        while (curr != NULL){
            cout << curr->val << " ";
            if (curr->right != NULL){
                st.push(curr->right);
            }
            curr = curr->left;
        }
        if (st.empty() == false){
            curr = st.top();
            st.pop();
        }
    }
}

int main(){
    cout << "Hey there!" << endl;
}