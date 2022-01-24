#include <iostream>
#include <queue>
#include <list>
#include <map>
using namespace std;
 
class Graph {
 
    map<int, list<int> > l;
 
public:
 
    void addEdge(int x, int y) {
        l[x].push_back(y);
        l[y].push_back(x);
    }
 
    void dfs_helper(int src, map<int, bool>& visited) {
        // recursive function that traverse the graph
        cout << src << " ";
        visited[src] = true;
        // go to all the nodes that are not visited
        for (int nbr : l[src])
            if (!visited[nbr])
                dfs_helper(nbr, visited);
    }
 
    void dfs(int src) {
        map<int, bool> visited;
        queue<int> q;
        // mark all the nodes as not visited;
        for (auto p : l) {
            int node = p.first;
            visited[node] = false;
        }
        // call the rec dfs_helper
        dfs_helper(src, visited);
        cout << endl;
    }
 

 
    void printList() {
        for (auto x : l) {
            cout << x.first << " : ";
            for (auto li : x.second)
                cout << li << " ";
            cout << endl;
        }
    }
};
 
 
int main() {
    Graph g;
    g.addEdge(0, 1);
    g.addEdge(0, 3);
    g.addEdge(1, 2);
    g.addEdge(1, 5);
    g.addEdge(3, 8);
    g.addEdge(3, 5);
 
    cout << "\n\t DFS \n\n";
    g.dfs(0);
 
    cout << "\n\tgraph \n\n";
    g.printList();
}