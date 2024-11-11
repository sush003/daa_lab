#include <iostream>
#include <climits>
using namespace std;

#define V 5  // Number of vertices in the graph

int minCost(int cost[], bool visited[]) {
    int min = INT_MAX, min_index;
    for (int v = 0; v < V; v++) {
        if (!visited[v] && cost[v] < min) {
            min = cost[v];
            min_index = v;
        }
    }
    return min_index;
}

void dijkstra(int graph[V][V], int src) {
    int cost[V];
    bool visited[V];

    for (int i = 0; i < V; i++) {
        cost[i] = INT_MAX;
        visited[i] = false;
    }

    cost[src] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = minCost(cost, visited);
        visited[u] = true;

        for (int v = 0; v < V; v++) {
            if (!visited[v] && graph[u][v] != 0 && cost[u] != INT_MAX && cost[u] + graph[u][v] < cost[v]) {
                cost[v] = cost[u] + graph[u][v];
            }
        }
    }

    cout << "Vertex \t\tMinimum Cost from Source (" << src << ")\n";
    for (int i = 0; i < V; i++) {
        cout << i << " \t\t " << cost[i] << endl;
    }
}

int main() {
    int graph[V][V] = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };

    int source;
    cout << "Enter the source vertex (0 to 4): ";
    cin >> source;

    dijkstra(graph, source);

    return 0;
}
