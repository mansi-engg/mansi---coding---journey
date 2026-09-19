#include <stdio.h>

#define INF 9999

int main() {
    int n, i, j, source;
    int graph[20][20];
    int distance[20];
    int visited[20] = {0};
    int min, next;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter the weighted adjacency matrix:\n");
    printf("Enter 0 if there is no edge.\n");

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);

            if (i != j && graph[i][j] == 0)
                graph[i][j] = INF;
        }
    }

    printf("Enter source vertex (0 to %d): ", n - 1);
    scanf("%d", &source);

    // Initialize distances
    for (i = 0; i < n; i++) {
        distance[i] = graph[source][i];
    }

    distance[source] = 0;
    visited[source] = 1;

    // Dijkstra's Algorithm
    for (i = 1; i < n; i++) {

        min = INF;
        next = -1;

        // Find the nearest unvisited vertex
        for (j = 0; j < n; j++) {
            if (!visited[j] && distance[j] < min) {
                min = distance[j];
                next = j;
            }
        }

        if (next == -1)
            break;

        visited[next] = 1;

        // Update distances
        for (j = 0; j < n; j++) {
            if (!visited[j] &&
                distance[next] + graph[next][j] < distance[j]) {

                distance[j] = distance[next] + graph[next][j];
            }
        }
    }

    printf("\nShortest distances from vertex %d:\n", source);

    for (i = 0; i < n; i++) {
        if (distance[i] == INF)
            printf("%d -> %d = INF\n", source, i);
        else
            printf("%d -> %d = %d\n", source, i, distance[i]);
    }

    return 0;
}