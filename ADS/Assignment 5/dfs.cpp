#include<iostream>
#include<vector>

using namespace std;

class Graph {
private:
    int numVertices; 
    vector<vector<int>> adjList; 

public:
    Graph(int n) {
        numVertices = n; 
        adjList.resize(numVertices);
    }

    void addEdge(int src, int dest) {
        adjList[src].push_back(dest);
        adjList[dest].push_back(src);
    }

    void printGraph() {
        for(int i = 0; i < numVertices; i++) {
            cout << "Adjacency list of vertex " << i << ": ";
            for(auto j : adjList[i]) {
                cout << j << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    int numVertices = 5; // number of vertices in the graph
    Graph g(numVertices); // create a graph object with 5 vertices

    // add edges to the graph
    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    g.printGraph(); // print the adjacency list representation of the graph

    return 0;
}
