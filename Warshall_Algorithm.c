#include <stdio.h>

int main() {
    int n, i, j, k;
    int graph[20][20];

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix:\n");

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    // Warshall's Algorithm
    for (k = 0; k < n; k++) {
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                graph[i][j] = graph[i][j] ||
                              (graph[i][k] && graph[k][j]);
            }
        }
    }

    printf("\nTransitive Closure:\n");

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }

    return 0;
}