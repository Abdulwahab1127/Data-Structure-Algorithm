#include <stdio.h>

#define NUM_VERTICES 4

int adjacencyMatrix[NUM_VERTICES][NUM_VERTICES];

void initializeGraph(int arr[][NUM_VERTICES]) {
    for (int i = 0; i < NUM_VERTICES; i++) {
        for (int j = 0; j < NUM_VERTICES; j++) {
            arr[i][j] = 0;
        }
    }
}

void addEdge(int arr[][NUM_VERTICES], int vertex1, int vertex2) {
    arr[vertex1][vertex2] = 1;
    arr[vertex2][vertex1] = 1;
}

void printGraph(int arr[][NUM_VERTICES]) {
    for (int i = 0; i < NUM_VERTICES; i++) {
        printf("%d: ", i);
        for (int j = 0; j < NUM_VERTICES; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

int main() {
    initializeGraph(adjacencyMatrix);

    int numEdges;
    printf("Enter the number of edges: ");
    scanf("%d", &numEdges);

    printf("Enter pairs of vertices for edges Using Space :\n");
    for (int i = 0; i < numEdges; i++) {
        int vertex1, vertex2;
        printf("%d:  ",i+1);
        scanf("%d %d", &vertex1, &vertex2);
        addEdge(adjacencyMatrix, vertex1, vertex2);
    }

    printGraph(adjacencyMatrix);

    return 0;
}

