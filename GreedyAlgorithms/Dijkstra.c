#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define V 6  // Number of vertices in the graph (You can change this value)

// Function to find the vertex with minimum distance value
int minDistance(int dist[], bool visited[]) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++) {
        if (!visited[v] && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }

    return min_index;
}

// Function to print the shortest distances from the source
void printSolution(int dist[], int src) {
    printf("\nShortest distances from source vertex %d:\n", src);
    for (int i = 0; i < V; i++) {
        printf("Vertex %d -> Distance = ", i);
        if (dist[i] == INT_MAX)
            printf("INF\n");
        else
            printf("%d\n", dist[i]);
    }
}

// Dijkstra’s algorithm implementation
void dijkstra(int graph[V][V], int src) {
    int dist[V];        // Output array: dist[i] will hold shortest distance from src to i
    bool visited[V];    // visited[i] is true if vertex i is included in shortest path tree

    // Initialize all distances as INFINITE and visited[] as false
    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        visited[i] = false;
    }

    // Distance to source is 0
    dist[src] = 0;

    // Find shortest path for all vertices
    for (int count = 0; count < V - 1; count++) {
        // Pick the minimum distance vertex from those not yet processed
        int u = minDistance(dist, visited);

        // Mark the picked vertex as processed
        visited[u] = true;

        // Update dist[v] for adjacent vertices of u
        for (int v = 0; v < V; v++) {
            // Update dist[v] only if:
            // - it’s not visited
            // - there is an edge from u to v
            // - and total weight of path through u is smaller than current dist[v]
            if (!visited[v] && graph[u][v] && dist[u] != INT_MAX 
                && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    // Print the constructed distance array
    printSolution(dist, src);
}

// Driver Code
int main() {
    // Example weighted adjacency matrix representation
    // 0 means no direct edge between vertices
    int graph[V][V] = {
        {0, 4, 0, 0, 0, 0},
        {4, 0, 8, 0, 0, 0},
        {0, 8, 0, 7, 0, 4},
        {0, 0, 7, 0, 9, 14},
        {0, 0, 0, 9, 0, 10},
        {0, 0, 4, 14, 10, 0}
    };

    int source;
    printf("Enter the source vertex (0 to %d): ", V - 1);
    scanf("%d", &source);

    dijkstra(graph, source);

    return 0;
}
