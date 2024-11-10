#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Structure for a queue
struct Queue {
    int items[MAX];
    int front;
    int rear;
};

// Function to create a queue
struct Queue* createQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

// Function to check if the queue is empty
int isEmpty(struct Queue* q) {
    return q->front == -1;
}

// Function to enqueue an element
void enqueue(struct Queue* q, int value) {
    if (q->rear == MAX - 1) {
        printf("Queue is full!\n");
        return;
    }
    if (isEmpty(q)) {
        q->front = 0;
    }
    q->rear++;
    q->items[q->rear] = value;
}

// Function to dequeue an element
int dequeue(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return -1;
    }
    int item = q->items[q->front];
    q->front++;
    if (q->front > q->rear) { // Reset queue after the last dequeue
        q->front = q->rear = -1;
    }
    return item;
}

// Function to perform BFS
void bfs(int graph[MAX][MAX], int visited[MAX], int numVertices, int startVertex) {
    struct Queue* q = createQueue();
    visited[startVertex] = 1; // Mark the starting vertex as visited
    enqueue(q, startVertex);

    printf("BFS Traversal: ");

    while (!isEmpty(q)) {
        int currentVertex = dequeue(q);
        printf("%d ", currentVertex);

        // Visit all the adjacent vertices
        for (int i = 0; i < numVertices; i++) {
            if (graph[currentVertex][i] == 1 && !visited[i]) {
                visited[i] = 1; // Mark as visited
                enqueue(q, i);
            }
        }
    }
    printf("\n");
}

// Main function
int main() {
    int graph[MAX][MAX], visited[MAX], numVertices, startVertex;

    printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);

    // Initialize the graph and visited array
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            graph[i][j] = 0; // No edges
        }
        visited[i] = 0; // Not visited
    }

    // Input the edges
    printf("Enter the adjacency matrix (0/1):\n");
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter the starting vertex (0 to %d): ", numVertices - 1);
    scanf("%d", &startVertex);

    // Perform BFS
    bfs(graph, visited, numVertices, startVertex);

    return 0;
}

