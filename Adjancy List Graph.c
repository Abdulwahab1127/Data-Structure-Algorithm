#include <stdio.h>
#define MAX_VERTICES 5

void initializeGraph(int arr[MAX_VERTICES][MAX_VERTICES]) {
    for (int i = 0; i < MAX_VERTICES; i++) {
        for (int j = 0; j < MAX_VERTICES; j++) {
            arr[i][j] = 0;
        }
    }
}

void addEdge(int matrix[MAX_VERTICES][MAX_VERTICES], int src, int dest) {
    matrix[src][dest] = 1;
    matrix[dest][src] = 1;
}

void display(int arr[MAX_VERTICES][MAX_VERTICES], int vertex) {
    printf("Adjacency List:\n\n");
    for (int i = 0; i < vertex; ++i) {
        printf("Vertex %d: ", i);
        for (int j = 0; j < vertex; ++j) {
            if (arr[i][j] == 1) {
                printf("--> %d ", j);
            }
        }
        printf("\n");
    }
}

int main() {
    int vertices = 5;
    int graph[MAX_VERTICES][MAX_VERTICES] = {0};

    addEdge(graph, 2, 3);
    addEdge(graph, 1, 0);
    addEdge(graph, 3, 4);
    addEdge(graph, 4, 1);
    addEdge(graph, 2, 2);

    display(graph, vertices);

    return 0;
}
