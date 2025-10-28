#include <stdio.h>
#include <limits.h>

#define V 5   // Number of vertices in the graph (change as needed)

// Function to find the vertex with the minimum key value
int minKey(int key[], int mstSet[]) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (mstSet[v] == 0 && key[v] < min)
            min = key[v], min_index = v;

    return min_index;
}

// Function to print the constructed MST
void printMST(int parent[], int graph[V][V]) {
    int totalWeight = 0;
    printf("Edge \tWeight\n");
    for (int i = 1; i < V; i++) {
        printf("%d - %d \t%d \n", parent[i], i, graph[i][parent[i]]);
        totalWeight += graph[i][parent[i]];
    }
    printf("Total Weight of MST = %d\n", totalWeight);
}

// Function to construct and print MST using Prim's algorithm  
void primMST(int graph[V][V]) {
    int parent[V];   // Array to store constructed MST
    int key[V];      // Key values to pick minimum weight edge
    int mstSet[V];   // To represent vertices not yet included in MST

    // Initialize all keys as INFINITE
    for (int i = 0; i < V; i++)
        key[i] = INT_MAX, mstSet[i] = 0;

    // Always include first vertex in MST
    key[0] = 0;     
    parent[0] = -1; // First node is always root of MST

    for (int count = 0; count < V - 1; count++) {
        // Pick minimum key vertex not yet included in MST
        int u = minKey(key, mstSet);

        mstSet[u] = 1;

        // Update key and parent for adjacent vertices
        for (int v = 0; v < V; v++)
            if (graph[u][v] && mstSet[v] == 0 && graph[u][v] < key[v])
                parent[v] = u, key[v] = graph[u][v];
    }

    printMST(parent, graph);
}

// Driver code
int main() {
    /* Example graph represented as adjacency matrix */
    int graph[V][V] = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };

    primMST(graph);

    return 0;
}
