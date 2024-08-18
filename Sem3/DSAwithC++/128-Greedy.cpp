#include <bits/stdc++.h>
using namespace std;

/*
Explanation : Greedy Methods are used for optimization problems

Greedy may not always work : say you got 18 1 and 10 coins and you gotta give 20, greey says pick 18 first then we have to pick 2 1s, but actually optimal is 2 10 coins if we are trying to optimize the number of coins
Similar situations occur in shortest paths problems in graphs

Applications : 
ACtivity Selection
Fractional Knapsack
Job Sequencing 
Prims
Kruskals 
Dijkstra's
Huffman Coding
 
Finding close to optimal solutions for NP problems like travelling salesman problem

Job Sequencing Problem : 
Sort jobs in decreasing order of profit
Initialize the result as first job in the sorted list and assign the latest possible slot
For the n - 1 remaining jobs :
    If this job cant be added ignore it
    else add it to the latest possible slot
*/

int main(){
    cout << "Hey there!" << endl;
}