#include<iostream>
#include<list>
#include<map>
#include<queue>
using namespace std;

template<typename T>
class Graph {	
	map<T, list<T> > adjList;
	
	void dfsHelper(T node, map<T, bool> &visited) {
		// Whenever come to a node, mark it visited
		visited[node] = true;
		cout<<node<<" ";
		
		// Try to find out a node which is neighbour of current node and not yet visited
		for(T neighbour: adjList[node]) {
			if (!visited[neighbour]) {
				dfsHelper(neighbour, visited);
			}
		}
	}
	
	public:
		
		Graph() {}
		
		void addEdge(T u, T v, bool bidir = true) {
			adjList[u].push_back(v);
			if (bidir) {
				adjList[v].push_back(u);
			}
		}
		
		void print() {
			// Iterate over map
			for(auto i: adjList) {
				cout<<i.first<<"->";
				
				// i.second is LL
				for(auto entry: i.second) {
					cout<<entry<<",";
				}
				cout<<endl;
			}
		}
		
		void dfs(T src) {
			map<T, bool> visited;		// which nodes are visited or not
			dfsHelper(src, visited);
		}
};

int main() {

	Graph<int> g;
	g.addEdge(0, 1);
	g.addEdge(1, 2);
	g.addEdge(0, 4);
	g.addEdge(2, 4);
	g.addEdge(2, 3);
	g.addEdge(3, 5);
	g.addEdge(3, 4);

	g.dfs(0);

	return 0;
}

