#include <bits/stdc++.h>
using namespace std;
typedef pair <int,int> Pair;
class Graph
{
    int V; //Number of Vertices
    list< pair<int,int> > *adj;
public:
    Graph(int V);
    void addEdge(int u, int v, int w);
    void shortestPath(int s);
};

Graph::Graph(int Vertices)
{
    V = Vertices;
    adj = new list <Pair> [Vertices];
}

void Graph::addEdge(int u, int v, int w)
{
    adj[u].push_back(make_pair(v, w)); // Add w to v’s list.
    adj[v].push_back(make_pair(u, w));
}

void Graph::shortestPath(int s)
{
    priority_queue <Pair, vector<Pair>, greater<Pair>  > pq;
    vector<int> dist(V, INT_MAX);

    pq.push(make_pair(0,s));
    dist[s] = 0;

    while (!pq.empty()) {
        int u = pq.top().second; //first element is distance
        pq.pop();
        for (auto it = adj[u].begin(); it != adj[u].end(); it++) {
            int v = it->first;
            if (it->second + dist[u] < dist[v]) {
                dist[v] = it->second + dist[u];
                pq.push(make_pair(dist[v],v));
            }
        }
    }

    // Print shortest distances stored in dist[]
    printf("Vertex   Distance from Source\n");
    for (int i = 0; i < V; ++i)
        printf("%d \t\t %d\n", i, dist[i]);

}

// Driver program to test methods of graph class
int main()
{
   int V = 6;
    Graph g(V);

    //  making above shown graph
    g.addEdge(0, 1, 3);
    g.addEdge(0, 2, 4);
    g.addEdge(1, 3, 2);
    g.addEdge(2, 3, 7);
    g.addEdge(1, 4, 5);
    g.addEdge(3, 4, 9);
    g.addEdge(5, 4, 6);
    g.addEdge(3, 5, 3);
    g.addEdge(2, 5, 1);

    g.shortestPath(0);
    return 0;
}
