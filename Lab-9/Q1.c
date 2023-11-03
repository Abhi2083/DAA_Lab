#include <stdio.h>
#include <stdbool.h>

#define INF 999999

void readGraph(int n, int graph[n][n]) {
    FILE *file = fopen("inUnAdjMat.dat", "r");
    if (file == NULL) {
        printf("File not found!\n");
        return;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            fscanf(file, "%d", &graph[i][j]);
        }
    }
    fclose(file);
}

int findMinKey(int n, int key[n], bool mstSet[n]) {
    int min = INF;
    int min_index;
    for (int v = 0; v < n; v++) {
        if (!mstSet[v] && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    }
    return min_index;
}

void primMST(int n, int graph[n][n]) {
    int parent[n];
    int key[n];
    bool mstSet[n];

    for (int i = 0; i < n; i++) {
        key[i] = INF;
        mstSet[i] = false;
    }

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < n - 1; count++) {
        int u = findMinKey(n, key, mstSet);
        mstSet[u] = true;
        for (int v = 0; v < n; v++) {
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    int totalWeight = 0;
    printf("Cost Adjacency Matrix of Minimum Spanning Tree:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (parent[j] == i)
                printf("%d ", graph[i][j]);
            else
                printf("0 ");
            totalWeight += (parent[j] == i) ? graph[i][j] : 0;
        }
        printf("\n");
    }

    printf("Total Weight of the Spanning Tree: %d\n", totalWeight);
}

int main() {
    int n, startVertex;
    printf("Enter the Number of Vertices: ");
    scanf("%d", &n);
    printf("Enter the Starting Vertex: ");
    scanf("%d", &startVertex);

    int graph[n][n];
    readGraph(n, graph);
    primMST(n, graph);

    return 0;
}