#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 1000

typedef struct Graph {
    int V;
    int **adj;
} Graph;

Graph *createGraph(int V) {
    Graph *graph = (Graph *) malloc(sizeof(Graph));
    graph->V = V;
    graph->adj = (int **) malloc(V * sizeof(int *));
    for (int i = 0; i < V; i++) {
        graph->adj[i] = (int *) calloc(V, sizeof(int));
    }
    return graph;
}

void addEdge(Graph *graph, int src, int dest) {
    graph->adj[src][dest] = 1;
    graph->adj[dest][src] = 1;
}

void printBFS(Graph *graph, int start) {
    bool *visited = (bool *) calloc(graph->V, sizeof(bool));
    int queue[MAX_SIZE];
    int front = -1, rear = -1;

    visited[start] = true;
    queue[++rear] = start;

    while (front < rear) {
        int node = queue[++front];
        printf("%d ", node);

        for (int i = 0; i < graph->V; i++) {
            if (graph->adj[node][i] && !visited[i]) {
                visited[i] = true;
                queue[++rear] = i;
            }
        }
    }
}

int main() {
    Graph *graph = createGraph(4);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 0);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 3);

    printf("BFS traversal: ");
    printBFS(graph, 2);

    return 0;
}