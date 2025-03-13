#include "dijkstras.h"
#include <algorithm>
vector<int> dijkstra_shortest_path(const Graph& G, int source, vector<int>& previous){
    int leng = G.numVertices;
    vector<int> distance(n, INF);
    vector<bool> visited(n, false);
    previous.resize(n, -1);

    priority_queue<Node, vector<Node>, greater<Node>> pq;
    pq.push(Node(source, 0));
    distance[source] = 0;

    while (!pq.empty()) {
        Node current = pq.top();
        pq.pop();
        int u = current.vertex;

        if (visited[u]) continue;
        visited[u] = true;

        for (const Edge& neighbor : G[u]) {
            int v = neighbor.dst;
            int weight = neighbor.weight;

            if (!visited[v] && distance[u] + weight < distance[v]) {
                distance[v] = distance[u] + weight;
                previous[v] = u;
                pq.push(Node(v, distance[v]));
            }
        }
    }
    return distance;
}

vector<int> extract_shortest_path(const vector<int>& distances, const vector<int>& previous, int destination){
    vector<int> path;
    for (int v = destination; v != -1; v = previous[v]) {
        path.push_back(v);
    }
    reverse(path.begin(), path.end());
    return path;

}

void print_path(const vector<int>& v, int total){
    cout << "Total cost is " << total << endl;
    for (int i : v){
        cout << i << " "
    }
    cout << endl;
}