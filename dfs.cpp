#include <bits/stdc++.h>
using namespace std;

class Graph
{
    int V; //Number of Vertices
    list<int> *adj;
    void DFS_helper(int s, bool visited[]);
public:
    Graph(int V);
    void addEdge(int v, int w);
    void DFS(int s);

};

Graph::Graph(int Vertices)
{
    V = Vertices;
    adj = new list <int> [Vertices];
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); // Add w to v’s list.
    adj[w].push_back(v);
}

void Graph::DFS_helper (int s, bool visited[]) {

    visited[s] = true;
    cout << s << " ";

    for (auto it = adj[s].begin(); it != adj[s].end(); it++) {
        if (!visited[*it]) {
            DFS_helper(*it, visited);
        }
    }
}

void Graph::DFS (int s) {
    bool visited[100];
    for (int i = 0; i < V; i++) {
        visited[i] = false;
    }

    DFS_helper(s, visited);
}

// Driver program to test methods of graph class
int main()
{
    Graph g(7);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 5);
    g.addEdge(2, 6);

    cout << "Following is Breadth First Traversal "
         << "(starting from vertex 0) \n";
    g.DFS(0);

    return 0;
}
