#include <bits/stdc++.h>
using namespace std;

class Graph
{
    int V; //Number of Vertices
    list<int> *adj;
public:
    Graph(int V);
    void addEdge(int v, int w);
    void BFS(int s);
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

void Graph::BFS(int s)
{
    // Mark all the vertices as not visited
    bool visited[100];
    for(int i = 0; i < V; i++)
        visited[i] = false;
    // Create a queue for BFS
    queue<int> Q;

    visited[s] = true;
    Q.push(s);

    while(!Q.empty())
    {
        // Dequeue a vertex from queue and print it
        s = Q.front();
        cout << s << " ";
        Q.pop();


        for (auto i = adj[s].begin(); i != adj[s].end(); i++)
        {
            if (!visited[*i])
            {
                visited[*i] = true;
                Q.push(*i);
            }
        }
    }
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
    g.BFS(0);

    return 0;
}
