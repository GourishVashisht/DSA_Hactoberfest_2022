//Given an adjacency list representation of graph... we need to print the adjacency list
void printGraph(vector<int> adj[], int v) {
    for(int i=0;i<v;i++) {
        for(int x:adj[i]) cout << x << " ";
        cout << endl;
    }
}
