#include <bits/stdc++.h>
using namespace std;

/*
Explanation : 

Degree of undirected graph : Number of edges going through it, sum of degrees = 2 * |E|, maximum number of edges = |V| * (|V| - 1) / 2
Degree of directed graph : InDegree - number of edges coming into the node, Outdegree - going out, sum of indegrees = sum of out degrees = |E|, maximum number of edges = |V| * (|V| - 1), ignoring self loop
Graph with all possible edges - complete graph

(Path) Walk : Path but duplicate allowed 
(Simple Path) Path : Duplicates not allowed
Cyclic : There exists a walk that starts and ends at the same vertex
We can have directed cyclic and undirected cyclic both
Directed Acyclic Graph : Important

Weighted Graphs and Unweighted Graphs

Graph Representations : 

1. Adjacency Matrix - WE have 1 at the position where there exists an edge between the nodes, basically mat[i][j] = {1 if there is an edge between i and j, 0 otherwise}
For an undirected graph this is a symmetric matrix, size of the matrix is |V| X |V|
mat[i][j] = For the directed graph, we have 1 only when there is an outgoing edge from i to j
For handling vertex names having complex strings, we create a hash table with string_name : index

Properties : 

Space Required - O(v X v)
Operations - 
Check if u and v are adjacent: O(1)
Check all adjacent vertices to u : O(v)
Find degree of u : O(v)
Add/Remove an edge : O(1)
Add/Remove a vertex : O(v^2)

The above also stores some redundant information

Adjacency List : 
Vectors are used for storing the nodes connected to a node, with the node as the key
We use vectors instead of LL because of their cache friendliness
Space required - O(v + 2e) for undirected and O(v + e) for directed
Check if there is an edge between u and v - o(v)
Find all adjacent of u - O(degree(u))
Add an edge - O(1)
Remove an edge - O(v)
Add/Remove a vertex - less than O(v^2)

void addEdge(vector<int> &adj, int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u); //this is only for undirected
}

void printAdj(vector<vector<int>> &adj, int n){
    for (int i = 0; i < n; i++){
        cout << i << " : ";
        for (int x : adj[i]){
            cout << x << " ";
        }
        cout << endl;
    }
}

int main(){
    int n = 5;
    vector<vector<int>> adj(n);
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    printAdj(adj, n);
    return 0;
}

We assumed that the vertices are 0 to v - 1, hence we created a vector with v places
In other cases, unordered_map<int, vector<int>> might work better

Most of the real world graphs are sparse graphs, not dense graphs

BFS : 

1st Variation : Source given and Graph is not disconnected

void BFS(vector<vector<int>> adj, int v, int s){
    unordered_set<int> visited;
    queue<int> q;
    q.push(s);
    visited.insert(s)
    while (q.empty() == false){
        int elem = q.front();
        q.pop();
        cout << elem << " ";
        for (int x : adj[elem]){
            if (visited.find(x) == visited.end()){
                q.push(x);
                visited.insert(x);
            }
        }
    }
}

2nd Variation : Graph may be disconnected and source is not given

void BFSdis(vector<vector<int>> adj, int v){
    //We now know vertices are from 0 to v - 1
    unordered_set<int> visited;
    for (int i = 0; i < v; i++){
        if (visited.find(i) == visited.end()){
            BFS(adj, v, visited);
        }
    }
    //we pass visited as reference so that it is updated throughout that
}

then we implement the above BFS with a global visited unordered

Time complexity : O(v + e)

Variation : Count connected components in undirected graph
We just count the number of times we had to call BFS, count++, return count

Applications : 

Shortest Path in unweighted graph
Crawlers in Search engines
Peer to Peer networks
Social networking Search
Chenny's Algoritms
Cycle Detection
Ford Fulkersen Algo
Broadcasting

DFS : 

1st Variation : Undirected graph, connected, source given

void DFSRec(vector<vector<int>> adj, int s, unordered_set<int> &visited){
    cout << s << " ";
    visited.insert(s);
    for (int x : adj[s]){
        if (visited.find(s) == visited.end()){
            DFSRec(adj, x, visited);
        }
    }
}

2nd Variation : Same as in BFS above

void DFSDis(vector<vector<int>> adj, int v){
    //o to v - 1
    unordered_set<int> visited;
    for (int i = 0; i < v; i++){
        if (visited.find(i) == visited.end()){
            DFSRec(adj, i, visited);
        }
    }
}

Count connected components : Count the number of times we are calling DFS

Time complexity : O(V + e)

Cycle Detection
topological sorting
Strongly Connected Components
Solving Maze and Similar Problems
Path Finding

Shortet Path in an Unweghted Graph with source given : Basically BFS

vector<int> dist(v, INT_MAX);
queue<int> q;
unordered_set<int> uset;
p.push(s);
dist[s] = 0;
uset.insert(s);
while (!q.empty()){
    int elem = q.front();
    q.pop();
    for (int x : adj[elem]){
        if (visited.find(x) == visited.end()){
            q.push(x);
            visited.insert(x);
            dist[x] = dist[elem] + 1; //since x is just adjacent to elem
        } 
    }
}

print dist vector

Detect Cycle with an undirected graph : We maintain a parent, if a node has adjacent elements which has already been visited and its not the parent for that node, then there is a cycle. Parent here = the node from which we just came to the current node

DFSrec(adj, s, visited, parent){
    visited.insert(s);
    for (int x : adj[s]){
        if (visited.find(s) == visited.end()){
            if (DFSrec(adj, x, visited, s) == true){
                return true;
            }
        }
        else if (x != parent){
            return true;
        }
    }
    return false;
}

bool cycleDec(){
    for (int i = 0; i < v; i++){
        if (visited.find(i) == visited.end()){
            if (DFSrec(adj, i, visited, -1) == true){
                return true;
            }
        }
    }
    return false;
}

Detect cycle in a directed graph : In DFS, if we see an edge from one of the descendants to one of the ancestors which is currently active in the recursion call stack, then we say there is a cycle. These edes are called as Back Edges

So we will maintain two things here, visited set and currently active recursion call stack

DFSrec(adj, s, &visited, &recurCS){
    recurCS, visited mein insert karo s
    for every u adjacent of s{
        if (recurCS mein hai u){
            return true;
        }
        else if ((s is not visited yet) && DFSrec(adj, s, visited, recurCS) == true){
            return true;
        }
    }
    remove s from recurCS;
    return false;
}

DFS(adj, v){
    unordered_set<int> visited;
    unordered_set<int> recurCS;
    for (i 0 to v - 1){
        if (i is not visited){
            if (DFSrec(adj, i, visited, recurCS) == true){
                return true;
            }
        }
    }
    return false;

    //Almost similar to undirected one
}

Complexity is O(V + E)

Topological Sorting : Well do this one in kinda BFS fashion
We are given a directed acyclic graph 

Kahn's Algorithm - O(v + e)
Steps : 
1. Store Indegree of each vertex
2. Create a queue, q
3. Insert the nodes with indegrees 0
4. While the queue is not empty : 
pop the front, and decrease the indegrees of the nodes connected to it by 1, if any of them becomes 0, insert them into the queue

O(V + E)

Kahn's Algorithm can also be used for cycle detection : 
Although it was used above for directed asyclic graphs, but here we are gonna modify it to detect a cycle
It is for a fact that if there is a cycle in a graph, at some point in the kahns algorithm, the queue is gonna be empty before all the nodes are processed
ie theres not gonna be any node with indegree 

Modified Kahn's Algorithm - O(v + e)
Steps : 
1. Store Indegree of each vertex
2. Create a queue, q, count = 0
3. Insert the nodes with indegrees 0
4. While the queue is not empty : 
count++, pop the front, and decrease the indegrees of the nodes connected to it by 1, if any of them becomes 0, insert them into the queue
5. return count != v; v = total number of vertices, if we processed them all then there isnt a cycle, else there is

Topological Sorting : Now we do in DFS kinda fashion

1. create an empty stack
2. for every vertex u : 
    if u is not visited : 
        DFSnew(u, st)
3. print all items of the stack

DFSnew(u, st){
    1. Mark u as visited
    2. for each x adjacent to u: 
        if (x is not visited){
            DFS(x, st)
        }
    3. Push u into the stack
}

Shortest Path in DAG : 
1. Initialize all distances as 0
2. set dist_vector[source] = 0
3. Find a topological sort of the graph
4. For every vertex u in the topological sort : 
    for every v adjacent of u : 
        if (dist[v] > dist[u] + weight(u, v)) : then
            dist[v] = dist[u] + weight(u, v)

Time complexity of this is O(V + E)

The reason for topological sort is so that we can update the distance vector without any complex things
Look kuch bhi ho sakta hai shortest distance from a node, so its better to get some order through topological sort
Bhai vo order to hoga hi, jana hai to rasta to yahi hai
After that we just optimize the distances as we traverse the nodes in correct order

Minimum spanning tree : 
It is defined for undirected connected and weighted graph
Spanning tree is a tree without any cycle, and having minimum number of edges
If there are v vertices then there must be v - 1 edges
For a weighted graph, out of all the spanning trees, we want to find the one having minimum edge weight sum

For finding it, we have : 

Prims Algo : Greedy algo 
It maintains two sets, one set contains the vertices which have been processed, other the ones which have not been
Making a cut method for selecting the edge with minimum weight that connects to the rest of the graph
Kisi bhi random vertex se start kar sakte hain

int primMST(vector<vector <int>> graph, int v){
    int res = 0;
    vector<int> key(v, INT_MAX);
    key[0] = 0;
    vector<bool> mSet(v, false);
    for (int count = 0; count < v; count++){
        int u = -1;
        for (int i = 0; i < v; i++){
            if (!mSet[i] && (u == -1 || key[i] < key[u])){
                u = i;
            }
        }
        mSet[u] = true;
        res += key[u];
        for (int u = 0; u < v; u++){
            if (graph[v][u] != 0 && !mSet[u]){
                key[u] = min(key[u], graph[v][u]);
            }
        }
    }
    return res;
}

NO FKING CLUE WTF HAPPENED ABOVE

Time complexity : O(v square)

The above implementation can be optimized using adjacency list representation and minHeap
The above will have O(Elogv)

Dijkstra's Algorithm

Given a weighted graph and a source, find the distance from the source to all vertices
We perform relaxation operation many times, Relax(u, v) u = vertex just finalized, v is adjacent of u
if d[v] > d[u] + w(u, v), then we update d[v] = d[u] + w(u, v)

In each ieration we perform relaxation operation on the neighbours of the vertex we are currently processing
After all the adjacents of a vertex are explored and relaxation has been performed, that vertex is finalized and we dont disturb it in future

Dijkstra's Algo doesnt work for negative weights
Does the shortest path change if we add a certain weight to all the edges of a graph - Yes, because number of edges comes into picture
Does the shortest path change if we multiply a certain weight to all the edges of a graph - No

Implementation : 

Create an empty minHeap
Initialize all distances to INT_MAX
set source distance as 0
insert all dist to minheap
while minheap is not empty : 
    u = extract min from minheap
    relax all adj of u that are not in pq

time complexity overall = O((v + e)(logv))

vector<int> dijkstra(vector<vector<int>> graph, int v, int src){
    vector<int> dist(v, INT_MAX);
    dist[src] = 0;
    vector<bool> fin(v, false); //finalized vector
    for (int count = 0; count < (v - 1); count++){
        int u = -1;
        for (int i = 0; i < v; i++){
            if (!fin[i] && (u == -1 || dist[i] < dist[u])){
                u = i;
            }
        }
        fin[i] = true;
        for (int u = 0; u < v; u++){
            if (graph[v][u] != 0 && fin[u] == false){
                dist[u] = min(dist[u], dist[v] + graph[v][u]);
            }
        }
    }
    return dist;
}

LOOK HOW SIMILAR THE ABOVE CODE IS TO PRIMS
Time complexity : O(v square)

The above implementation can be optimized using adjacency list representation and minHeap
The above will have O((E + v)logv)

Strongly connected components problem : Kosaraju's Algorithm
Strongly connected components are the ones in which are nodes are reachable from one another

For undirected graphs, we call DFS/BFS starting from any component, after that we just keep calling DFS/BFS for the unvisited components until all are visited 

One solution for directed graphs is that instead of starting from any vertex, we call DFS in order from sink component to source component

Kosaraju's Algo steps

Order ghe vertices in decreasing order of finish times in DFS - this is done in a fashion similar to topological sort
Reverse all edges
Do DFS of the reversed graph in the order obtained in step 1, for every vertex print all reachable vertices, as one strongly connected component

1. create an empty stack
2. for every vertex u : 
    if u is not visited : 
        DFSnew(u, st)
3. while st is not empty : 
    pop the to and add to result

DFSnew(u, st){
    1. Mark u as visited
    2. for each x adjacent to u: 
        if (x is not visited){
            DFS(x, st)
        }
    3. Push u into the stack
}

Bellman Ford Algorithm - Minimum distance from Source to every other vertex, -ve weights also allowed

Shortest Paths yet :
1. Based on number of edges (We do bfs, first we get all nodes at distance 1, then at 2 and so on)
2. Based on number of edges Directed Acyclic Graph : Topological Sort
3. Dijkstra's Algo : just not for -ve weight edges
4. Bellman Ford Algo : Also accomodates -ve edge weights

This is a DP algorithm, so bottom up
We relax all edges v - 1 times
We find shortest paths that are at edge length 1 then 2 then 3 and so on with each iteration

We can perform relaxation of all the edges in any order, they just have to be in the format source -> destination
and just keep updating the table

relaxation : 

for (int count = 0; count < v -1; count++){
    for every edge (u, v):
        if (d[v] > d[u] + w(u, v)): 
            d[v] = d[u] + w(u, v)

Also if after v - 1 iterations we are getting a shorter path, then there exists a negative weight cycle in the graph
complexity = O(v + e)

Articulation Point : 
Given an undirected and connected graph - the points which if removed along with their edges increases the number of connected components to more than 1
These point can form weaknesses in networks, we want to remove as many as we can
We find these points using DFS and two rules : 

1. If the root of the DFS tree has two or more children, then it is an articulation point
2. Discovery Time - the time at which the node was touched and Low Value - Lowest discovery time reachable from that node
if for any edge u to v : if low[v] >= discovery[u] then u is an articulation point ie if the lowest discovery time reachable from the child node is more than or equal to the discovery time of the parent, means child has no way of going back to the ancestors above its parent, means the parent is an articulation point

Bridges in a graph : 
an edge which if removed leads to an increase in the number of connected components in the graph

An edge u -> v is called as an articulation bridge if low[v] > disc[u], NOTE THE STRICTLY GREATER

Tarjans Algorithm for finding strongly connected components in a directed graph
this is better than kosaraju

Kosarajus Algorithm requires two DSF traversals, we have to ignore cross edges in this algo

Cross edges point from a node to a previously visited node that is neither an ancestor nor a descendant.
Back edge point to an ancestor in the recursion call stack

Whenever we come across a vertex whose all children are explored and this vertex has same low value and discovery time then this vertex is the start of a strongly connected component, we simply remove all the elements in recursive call stack and print them, they form the strongly connected component
This is because in the condition, the node has no way to reach to any of its ancestors and hence it is a beginning of a strongly connected component

Kruskal's Algorithm for minimum spanning tree : 
This is based on the facts that we need to pick the minimum weight edges and there should be no cycles, this is a greedy algo

1. Sort all the edges in inc order
2. initialize mst = {} and res = 0
3. Do the following for every edge e while mst size does not become v - 1 : 
    if adding e to mst does not cause a cycle then : 
        mst = mst + e
        res = res + e.weight
4. Return res

Here we need to represent the graph as a collection of edges, so we don't use adjacent matrix or list

struct Edge{

    int src, des, wt;

    Edge (int s, int d, int w){
    src = s;
    des = d;
    wt = w;
    }
}

bool myCmp(Edge e1, Edge e2){
    return e1.wt < e2.wt;
}

WE have to use disjoint set, we have two operations - adding the edge and checking the cycle
We maintain different sets for different vertices initially, when we process an edge, we consider both the vertices and check if their sets are same, if yes then they are already connected and we skip the edge, else connect

vector<int> parent(v), rank(v);

int Kruskal(vector<Edge> arr){
    sort(arr, arr + arr.size(), myCmp);
    for (int i = 0; i < v; i++){
        parent[i] = i;
        rank[i] = 0;
    }
    int res = 0;
    for (int i = 0, s = 0; s < v - 1; i++){
        Edge e = arr[i];
        int x = find(e.src);
        int y = find(e.dst);
        if (x != y){
            res += e.wt;
            Union(x, y);
            s++;
        }
    }
    return res;
}

i = index of next edge
s = current size of mst
v = total number of vertices
e = total number of edges
find and union have their standard implementation

Time complexity : O(ElogE + V + E * variable(can be constant or logV))
Auxillary Space is : O(v)

*/

int main(){
    cout << "Hey there!" << endl;
}
