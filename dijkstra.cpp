#include<iostream>
#include<set>
#include<unordered_map>
#include<climits>
#include<list>
using namespace std;

template<typename T>
class Graph {	
	
	unordered_map<T, list<pair<T, int> > > m;
	
	public:
		void addEdge(T u, T v, int dist, bool bidir=true) {
			m[u].push_back(make_pair(v, dist));
			if (bidir) {
				m[v].push_back(make_pair(u, dist));
			}
		}
		
		void printAdj() {
			// Let's try to print the adj list
			// Iterate over all the Key value pairs in the map
			for(auto j: m) {
				cout<<j.first<<"-> ";
				// Iterate over the list of cities
				for(auto l: j.second) {
					cout<<"("<<l.first<<","<<l.second<<") ";
				}
				cout<<endl;
			}
		}
		
		void dijkstraSSSP(T src) {
			unordered_map<T, int> dist;		// (node, it's min distance)
			// Set all distances to infinity
			for(auto j: m) {
				dist[j.first] = INT_MAX;
			}
			dist[src] = 0;
			
			// Make a set to find out a node with the minimum distance
			// (distance, node)
			set<pair<int, T> > s;		// Sorting according to first parameter
			
			s.insert(make_pair(0, src));
			
			while(!s.empty()) {
				// Find the pair at the front.
				auto p = *(s.begin());
				T node = p.second;
				int nodeDist = p.first;
				s.erase(s.begin());
				
				// Iterate over the neighbours of current node
				for(auto childPair: m[node]) {
					if (nodeDist + childPair.second < dist[childPair.first]) {
						// In the set updation of a particular node is not possible
						// We have to remove the old pair, and insert the new pair to simulation updation
						T dest = childPair.first;
						auto f = s.find(make_pair(dist[dest], dest));
						if (f != s.end()) {
							// Remove the child pair
							s.erase(f);
						}
						// Insert the new pair
						dist[dest] = nodeDist + childPair.second;
						s.insert(make_pair(dist[dest], dest));
					}
				}
			}
			
			// Let's print distances to all other nodes from src
			for(auto d: dist) {
				cout<<d.first<<" is located at distance of "<<d.second<<endl;
			}
		}
};

int main() {

	
	Graph<int> g;
	g.addEdge(1, 2, 1);
	g.addEdge(1, 3, 4);
	g.addEdge(2, 3, 1);
	g.addEdge(3, 4, 2);
	g.addEdge(1, 4, 7);
	g.dijkstraSSSP(1);
	
	/*
	Graph<string> india;
	india.addEdge("Amritsar", "Delhi", 1);
	india.addEdge("Amritsar", "Jaipur", 4);
	india.addEdge("Jaipur", "Delhi", 2);
	india.addEdge("Jaipur", "Mumbai", 8);
	india.addEdge("Bhopal", "Agra", 2);
	india.addEdge("Mumbai", "Bhopal", 3);
	india.addEdge("Agra", "Delhi", 1);
//	india.printAdj();
	india.dijkstraSSSP("Amritsar");
	*/
	
	return 0;
}

