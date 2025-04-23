#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define WHITE 0
#define GRAY 1
#define BLACK 2
#define MAX 100

void printArray(int arr[], int n, char *name) {
    printf("%s: ", name);
    for (int i = 0; i < n; i++) {
        if (arr[i] == INT_MAX)
            printf("INF ");
        else if (arr[i] == -1)
            printf("NIL ");
        else
            printf("%d ", arr[i]);
    }
    printf("\n");
}

void printQueue(int queue[], int front, int rear) {
    printf("Queue: ");
    for (int i = front; i <= rear; i++)
        printf("%d ", queue[i]);
    printf("\n");
}

void BFS(int **adj, int n, int start) {
    int color[n], distance[n], parent[n];
    int queue[MAX], front = 0, rear = -1;

    for (int i = 0; i < n; i++) {
        color[i] = WHITE;
        distance[i] = INT_MAX;
        parent[i] = -1;
    }

    color[start] = GRAY;
    distance[start] = 0;
    queue[++rear] = start;

    printf("\n--- BFS Traversal ---\n");
    while (front <= rear) {
        int u = queue[front++];
        printf("\nVisiting Node: %d\n", u);
        for (int v = 0; v < n; v++) {
            if (adj[u][v] == 1 && color[v] == WHITE) {
                color[v] = GRAY;
                distance[v] = distance[u] + 1;
                parent[v] = u;
                queue[++rear] = v;
            }
        }
        color[u] = BLACK;
        printQueue(queue, front, rear);
        printArray(color, n, "Color");
        printArray(distance, n, "Distance");
    }

    printf("\nParent Tree (π):\n");
    for (int i = 0; i < n; i++)
        printf("π[%d] = %d\n", i, parent[i]);
}

int main() {
    int n;
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    int **adj = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
        adj[i] = (int *)malloc(n * sizeof(int));

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &adj[i][j]);

    int startVertex = 3;  // Index of 'D' (0-based)
    BFS(adj, n, startVertex);

    for (int i = 0; i < n; i++)
        free(adj[i]);
    free(adj);
    return 0;
}
