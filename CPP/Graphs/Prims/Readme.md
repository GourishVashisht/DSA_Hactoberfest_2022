# Prim's Algorithm
Prim'a algorithm is a minimum spanning tree algorithm that takes a graph as input and finds
the subset of the edges of that graph which:
* forms a tree that includes every vertex
* has the minimum sum of weights among all the trees that can be formed from the graph

## Algorithm
Prim's algorithm falls is a greedy approach.
We start from one of the vertex, and keep on adding edges with the lowest weight until we reach our goal...
1) Initialize the minimum spanning tree with a vertex chosen at random (or 0th vertext)
2) Find all the edges that connect the tree to new vertices, find the minimum and add it to the tree
3) Keep repeating step 2 until we get a minimum spanning tree...
