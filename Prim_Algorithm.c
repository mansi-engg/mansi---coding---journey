#include <stdio.h>

#define INF 9999

int main() {
    int n, i, j;
    int graph[20][20];
    int selected[20] = {0};
    int edges = 0, min, x, y, total = 0;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter the weighted adjacency matrix:\n");
    printf("Enter 0 if there is no edge.\n");

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);

            if (graph[i][j] == 0)
                graph[i][j] = INF;
        }
    }

    selected[0] = 1;

    printf("\nEdges in Minimum Spanning Tree:\n");

    while (edges < n - 1) {
        min = INF;
        x = -1;
        y = -1;

        for (i = 0; i < n; i++) {
            if (selected[i]) {
                for (j = 0; j < n; j++) {
                    if (!selected[j] && graph[i][j] < min) {
                        min = graph[i][j];
                        x = i;
                        y = j;
                    }
                }
            }
        }

        if (x == -1 || y == -1) {
            printf("Graph is not connected.\n");
            return 0;
        }

        printf("%d - %d : %d\n", x, y, min);

        total += min;
        selected[y] = 1;
        edges++;
    }

    printf("Minimum Cost = %d\n", total);

    return 0;
}