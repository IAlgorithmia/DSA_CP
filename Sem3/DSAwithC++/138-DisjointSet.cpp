#include <bits/stdc++.h>
using namespace std;

/*
Explanation : Say we have a sitruation where no one is a frined of each other
if 1 and 2 are friends and 2 and 5 become friends, 1 and 5 also become friends
We can use graph to solve the problem

Disjoint means no two have anything in common, in the universe

It has find and union, union just combines the disjoint sets
Say a dset contains x and y, find(x) = find(y) = something idk, they all have one single representative element

I aint fkin coding it

Elements are just number of trees, in any set, the root is the node which has parent as itself, instead of child we have parent here

Union by rank

Rank is just basically height of the tree, while doing union we just set the smaller rank tree as the child of the larger rank tree
hence overall rank doesnt increase

Path compression mein when we do find(3) say, we also set 3 as the direct child of the root node, if it is not already, this reduces the time taken in future
*/

int main(){
    cout << "Hey there!" << endl;
}