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

void printDFS(Graph *graph, int start) {
    bool *visited = (bool *) calloc(graph->V, sizeof(bool));

    dfsUtil(graph, start, visited);
}

void dfsUtil(Graph *graph, int node, bool *visited) {
    visited[node] = true;
    printf("%d ", node);

    for (int i = 0; i < graph->V; i++) {
        if (graph->adj[node][i] && !visited[i]) {
            dfsUtil(graph, i, visited);
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

    printf("DFS traversal: ");
    printDFS(graph, 2);

    return 0;
}