#include <stdio.h>

struct Edge {
    int u, v, weight;
};

int parent[20];

int find(int i) {
    while (parent[i] != i)
        i = parent[i];

    return i;
}

void unionSet(int a, int b) {
    int rootA = find(a);
    int rootB = find(b);

    parent[rootA] = rootB;
}

int main() {
    int n, e;
    int i, j;
    int total = 0;
    int count = 0;

    struct Edge edges[100], temp;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &e);

    printf("Enter edges (source destination weight):\n");

    for (i = 0; i < e; i++) {
        scanf("%d %d %d",
              &edges[i].u,
              &edges[i].v,
              &edges[i].weight);
    }

    /* Initialize parent */
    for (i = 0; i < n; i++)
        parent[i] = i;

    /* Sort edges by weight */
    for (i = 0; i < e - 1; i++) {
        for (j = 0; j < e - i - 1; j++) {
            if (edges[j].weight > edges[j + 1].weight) {
                temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }
        }
    }

    printf("\nEdges in Minimum Spanning Tree:\n");

    for (i = 0; i < e && count < n - 1; i++) {
        int u = edges[i].u;
        int v = edges[i].v;

        if (find(u) != find(v)) {
            printf("%d - %d : %d\n",
                   u, v, edges[i].weight);

            total += edges[i].weight;
            unionSet(u, v);
            count++;
        }
    }

    if (count != n - 1) {
        printf("Graph is not connected.\n");
    } else {
        printf("Minimum Cost = %d\n", total);
    }

    return 0;
}