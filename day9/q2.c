#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define WHITE 0
#define GRAY 1
#define BLACK 2

int time = 0;

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

void DFSVisit(int **adj, int u, int n, int *color, int *start, int *finish, int *parent) {
    color[u] = GRAY;
    time++;
    start[u] = time;
    printf("\nVisiting Node: %d\n", u);
    printArray(color, n, "Color");
    printf("Start Times: ");
    for (int i = 0; i < n; i++) printf("%d ", start[i]); printf("\n");
    printf("Finish Times: ");
    for (int i = 0; i < n; i++) printf("%d ", finish[i]); printf("\n");

    for (int v = 0; v < n; v++) {
        if (adj[u][v] == 1 && color[v] == WHITE) {
            parent[v] = u;
            DFSVisit(adj, v, n, color, start, finish, parent);
        }
    }
    color[u] = BLACK;
    time++;
    finish[u] = time;

    printf("Finished Node: %d\n", u);
    printArray(color, n, "Color");
    printf("Start Times: ");
    for (int i = 0; i < n; i++) printf("%d ", start[i]); printf("\n");
    printf("Finish Times: ");
    for (int i = 0; i < n; i++) printf("%d ", finish[i]); printf("\n");
}

void DFS(int **adj, int n, int startVertex) {
    int color[n], start[n], finish[n], parent[n];

    for (int i = 0; i < n; i++) {
        color[i] = WHITE;
        start[i] = finish[i] = 0;
        parent[i] = -1;
    }

    DFSVisit(adj, startVertex, n, color, start, finish, parent);

    for (int i = 0; i < n; i++) {
        if (color[i] == WHITE) {
            DFSVisit(adj, i, n, color, start, finish, parent);
        }
    }

    printf("\nTree Structure (π):\n");
    for (int i = 0; i < n; i++) {
        printf("π[%d] = %d\n", i, parent[i]);
    }

    printf("\nParenthesis Representation:\n");
    for (int i = 0; i < n; i++) {
        printf("Node %d: (%d, %d)\n", i, start[i], finish[i]);
    }
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

    int startVertex = 3; // D
    DFS(adj, n, startVertex);

    for (int i = 0; i < n; i++)
        free(adj[i]);
    free(adj);

    return 0;
}
