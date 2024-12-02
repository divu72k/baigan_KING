#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 10

int graph[MAX_VERTICES][MAX_VERTICES];
int visited[MAX_VERTICES];
int n; // Number of vertices

void createGraph() {
    printf("\nEnter the number of vertices in the graph: ");
    scanf("%d", &n);

    printf("\nEnter the adjacency matrix of the graph:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
}

void bfs(int source) {
    int queue[MAX_VERTICES], front = 0, rear = 0, u;
    for (int i = 0; i < n; i++) visited[i] = 0;

    queue[rear++] = source;
    visited[source] = 1;

    printf("\nReachable vertices from %d: ", source);
    while (front < rear) {
        u = queue[front++];
        printf("%d ", u);

        for (int v = 0; v < n; v++) {
            if (graph[u][v] && !visited[v]) {
                queue[rear++] = v;
                visited[v] = 1;
            }
        }
    }
    printf("\n");
}

void dfs(int source) {
    visited[source] = 1;
    for (int v = 0; v < n; v++) {
        if (graph[source][v] && !visited[v]) {
            dfs(v);
        }
    }
}

int isGraphConnected() {
    for (int i = 0; i < n; i++) visited[i] = 0;
    dfs(0); // Assuming 0 as the starting vertex for connectivity check

    for (int i = 0; i < n; i++) {
        if (!visited[i]) return 0; // If any vertex is not visited, graph is not connected
    }
    return 1;
}

int main() {
    int choice, source;

    while (1) {
        printf("\n1. Create Graph\n2. BFS\n3. Check if graph is connected\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createGraph();
                break;
            case 2:
                printf("Enter the source vertex for BFS: ");
                scanf("%d", &source);
                bfs(source);
                break;
            case 3:
                if (isGraphConnected()) {
                    printf("\nThe graph is connected.\n");
                } else {
                    printf("\nThe graph is not connected.\n");
                }
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
