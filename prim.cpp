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
    vector<int> key(V, INT_MAX);
    vector<int> parent(V, -1);
    vector<bool> inMST(V, false);
    pq.push(make_pair(0,s));
    key[s] = 0;

    while (!pq.empty()) {
        int u = pq.top().second; //first element is distance
        pq.pop();
        if (inMST[u])
            continue;
        inMST[u] = true;
        for (auto it = adj[u].begin(); it != adj[u].end(); it++) {
            int v = it->first;
            if (inMST[v] == false && key[v] > it->second) {
                key[v] = it->second;
                pq.push(make_pair(key[v],v));
                parent[v] = u;
            }
        }
    }
    cout << "Parent - Child\n";
    for (int i = 1; i < V; ++i)
        printf("%d - %d\n", parent[i], i);

}

// Driver program to test methods of graph class
int main()
{
    int V = 6;
    Graph g(V);

    //  making above shown graph
    g.addEdge(0, 1, 3);
    g.addEdge(0, 2, 4);
    g.addEdge(1, 2, 1);
    g.addEdge(1, 3, 2);
    g.addEdge(2, 3, 7);
    g.addEdge(1, 4, 5);
    g.addEdge(3, 4, 9);
    g.addEdge(5, 4, 6);
    g.addEdge(3, 5, 3);
    g.addEdge(2, 5, 8);

    g.shortestPath(0);
    return 0;
}
