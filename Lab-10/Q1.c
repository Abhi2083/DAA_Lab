#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define V 100

void readAdjacencyMatrix(int graph[V][V], int n) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
}

int minDistance(int dist[], bool sptSet[], int n) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < n; v++) {
        if (!sptSet[v] && dist[v] < min) {
            min = dist[v];
            min_index = v;
        }
    }

    return min_index;
}

void printPath(int parent[], int j) {
    if (parent[j] == -1)
        return;

    printPath(parent, parent[j]);
    printf("->%d", j + 1);
}

void printSolution(int dist[], int parent[], int src, int n) {
    printf("Source Destination Cost Path\n");
    for (int i = 0; i < n; i++) {
        if (i != src) {
            printf("%d %d %d %d", src + 1, i + 1, dist[i], src + 1);
            printPath(parent, i);
            printf("\n");
        }
    }
}

void dijkstra(int graph[V][V], int src, int n) {
    int dist[V];
    bool sptSet[V];
    int parent[V];

    for (int i = 0; i < n; i++) {
        dist[i] = INT_MAX;
        sptSet[i] = false;
    }

    dist[src] = 0;
    parent[src] = -1;

    for (int count = 0; count < n - 1; count++) {
        int u = minDistance(dist, sptSet, n);
        sptSet[u] = true;

        for (int v = 0; v < n; v++) {
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                parent[v] = u;
            }
        }
    }

    printSolution(dist, parent, src, n);
}

int main() {
    int graph[V][V];
    int n, src;

    printf("Enter the Number of Vertices: ");
    scanf("%d", &n);
    printf("Enter the Source Vertex: ");
    scanf("%d", &src);

    readAdjacencyMatrix(graph, n);
    dijkstra(graph, src - 1, n);

    return 0;
}
