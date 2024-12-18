#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 4  // Maximum number of vertices (from 1 to 4)
#define MAX_QUEUE_SIZE MAX_VERTICES

// Adjacency Matrix and Queue
int adjMatrix[MAX_VERTICES][MAX_VERTICES] = {
    {0, 0, 1, 0},   // Vertex 1 has a directed edge to vertex 3
    {1, 0, 0, 0},   // Vertex 2 has a directed edge to vertex 1
    {0, 0, 0, 1},   // Vertex 3 has a directed edge to vertex 4
    {0, 0, 1, 0}    // Vertex 4 has a directed edge to vertex 3
};  // Adjacency matrix for the directed graph
int visited[MAX_VERTICES];  // Visited array
int queue[MAX_QUEUE_SIZE];  // Queue for BFS
int front = -1, rear = -1;  // Queue pointers

// Queue functions
int isQueueEmpty() {
    return front == -1;
}

int isQueueFull() {
    return rear == MAX_QUEUE_SIZE - 1;
}

void enqueue(int vertex) {
    if (isQueueFull()) {
        printf("Queue is full!\n");
        return;
    }
    if (front == -1) {
        front = 0;
    }
    rear++;
    queue[rear] = vertex;
}

int dequeue() {
    if (isQueueEmpty()) {
        printf("Queue is empty!\n");
        return -1;
    }
    int vertex = queue[front];
    front++;
    if (front > rear) {  // Reset the queue
        front = rear = -1;
    }
    return vertex;
}

// BFS Function
void BFS(int startVertex) {
    // Initialize visited array to 0 (unvisited)
    for (int i = 0; i < MAX_VERTICES; i++) {
        visited[i] = 0;
    }

    printf("Breadth-First Search starting from vertex %d:\n", startVertex);

    // Start by visiting the start vertex
    visited[startVertex - 1] = 1;  // Adjusting for 1-based indexing
    enqueue(startVertex);

    while (!isQueueEmpty()) {
        int currentVertex = dequeue();
        printf("%d ", currentVertex);  // Print as soon as we dequeue the vertex

        // Visit all adjacent vertices of the current vertex (in the directed graph)
        for (int i = 0; i < MAX_VERTICES; i++) {
            if (adjMatrix[currentVertex - 1][i] == 1 && !visited[i]) {
                visited[i] = 1;  // Mark the vertex as visited
                enqueue(i + 1);  // Adjusting for 1-based indexing
            }
        }
    }
    printf("\n");
}

// Main function
int main() {
    // Start BFS from vertex 1
    BFS(1);

    return 0;
}

