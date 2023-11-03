// 9.2 Aim of the program: Given an undirected weighted connected graph G(V, E). Apply
// Krushkal’s algorithm to
// ● Find the minimum spanning tree T(V, E’) and Display the selected edges of G.
// ● Display total cost of the minimum spanning tree T.

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int u, v, w;
} Edge;

int compare(const void* a, const void* b) {
    return ((Edge*)a)->w - ((Edge*)b)->w;
}

int find(int parent[], int i) {
    if (parent[i] == i)
        return i;
    return find(parent, parent[i]);
}

void unionSet(int parent[], int rank[], int x, int y) {
    int xroot = find(parent, x);
    int yroot = find(parent, y);

    if (rank[xroot] < rank[yroot])
        parent[xroot] = yroot;
    else if (rank[xroot] > rank[yroot])
        parent[yroot] = xroot;
    else {
        parent[yroot] = xroot;
        rank[xroot]++;
    }
}

void Kruskal(Edge edges[], int V, int E) {
    qsort(edges, E, sizeof(edges[0]), compare);

    int* parent = malloc(V * sizeof(int));
    int* rank = malloc(V * sizeof(int));

    for (int v = 0; v < V; ++v) {
        parent[v] = v;
        rank[v] = 0;
    }

    Edge* result = malloc((V - 1) * sizeof(Edge));
    int e = 0;
    int i = 0;

    while (e < V - 1 && i < E) {
        Edge next_edge = edges[i++];

        int x = find(parent, next_edge.u);
        int y = find(parent, next_edge.v);

        if (x != y) {
            result[e++] = next_edge;
            unionSet(parent, rank, x, y);
        }
    }

    printf("Edge Cost\n");
    int totalWeight = 0;
    for (i = 0; i < e; ++i) {
        printf("%d--%d %d\n", result[i].u + 1, result[i].v + 1, result[i].w);
        totalWeight += result[i].w;
    }
    printf("Total Weight of the Spanning Tree: %d\n", totalWeight);

    free(parent);
    free(rank);
    free(result);
}

int main() {
    int V, E;
    scanf("%d %d", &V, &E);

    Edge* edges = malloc(E * sizeof(Edge));

    for (int i = 0; i < E; ++i) {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
        edges[i].u--;
        edges[i].v--;
    }

    Kruskal(edges, V, E);

    free(edges);

    return 0;
}
