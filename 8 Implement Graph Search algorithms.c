#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100


typedef struct Node {
    int vertex;
    struct Node* next;
} Node;


typedef struct Graph {
    int numVertices;
    Node* adjLists[MAX_VERTICES];
    int visited[MAX_VERTICES];
} Graph;


typedef struct Queue {
    int items[MAX_VERTICES];
    int front;
    int rear;
} Queue;

// --- Node and Graph Management Functions ---


Node* createNode(int v) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        perror("Failed to allocate memory for Node");
        exit(EXIT_FAILURE);
    }
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}


void initGraph(Graph* graph, int vertices) {
    if (vertices > MAX_VERTICES) {
        fprintf(stderr, "Error: Number of vertices exceeds MAX_VERTICES limit.\n");
        exit(EXIT_FAILURE);
    }
    graph->numVertices = vertices;
    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
        graph->visited[i] = 0;
    }
}

void addEdge(Graph* graph, int src, int dest) {
    // Add edge src -> dest (Head insertion for simplicity)
    Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    // Add edge dest -> src (Since the graph is undirected)
    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}


void freeGraph(Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        Node* current = graph->adjLists[i];
        Node* next;
        while (current != NULL) {
            next = current->next;
            free(current);
            current = next;
        }
        graph->adjLists[i] = NULL; // Ensure the list head is NULL after freeing
    }
}


void initQueue(Queue* q) {
    q->front = -1;
    q->rear = -1;
}

int isEmpty(Queue* q) {
    return q->front == -1;
}

void enqueue(Queue* q, int value) {
    if (q->rear == MAX_VERTICES - 1) {
        fprintf(stderr, "Queue overflow!\n");
        return;
    }
    if (q->front == -1)
        q->front = 0;
    q->items[++q->rear] = value;
}

int dequeue(Queue* q) {
    if (isEmpty(q)) {
        return -1; // Should handle this case where called
    }
    int item = q->items[q->front];
    if (q->front >= q->rear) {
        // Reset queue if the last item is dequeued
        q->front = -1;
        q->rear = -1;
    } else {
        q->front++;
    }
    return item;
}


void DFS(Graph* graph, int vertex) {
    // Mark the current node as visited and print it
    graph->visited[vertex] = 1;
    printf("%d ", vertex);

   
    Node* temp = graph->adjLists[vertex];
    while (temp) {
        int adjVertex = temp->vertex;
        if (!graph->visited[adjVertex]) {
            DFS(graph, adjVertex);
        }
        temp = temp->next;
    }
}


void BFS(Graph* graph, int startVertex) {
    Queue q;
    initQueue(&q);


    graph->visited[startVertex] = 1;
    enqueue(&q, startVertex);

    while (!isEmpty(&q)) {
        // Dequeue a vertex and print it
        int currentVertex = dequeue(&q);
        printf("%d ", currentVertex);

        Node* temp = graph->adjLists[currentVertex];
        while (temp) {
            int adjVertex = temp->vertex;
            if (!graph->visited[adjVertex]) {
                graph->visited[adjVertex] = 1;
                enqueue(&q, adjVertex);
            }
            temp = temp->next;
        }
    }
}


void resetVisited(Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        graph->visited[i] = 0;
    }
}



int main() {
    Graph graph;
    int vertices = 6;
    initGraph(&graph, vertices);

    
    addEdge(&graph, 0, 1);
    addEdge(&graph, 0, 2);
    addEdge(&graph, 1, 3);
    addEdge(&graph, 1, 4);
    addEdge(&graph, 2, 4);
    addEdge(&graph, 3, 4);
    addEdge(&graph, 3, 5);
    addEdge(&graph, 4, 5);

    printf("--- Graph Traversal Demonstration (Adjacency List) ---\n");

    printf("DFS starting from vertex 0 (Depth First Search):\n");
    DFS(&graph, 0);

    resetVisited(&graph);
    printf("\n\n");

    printf("BFS starting from vertex 0 (Breadth First Search):\n");
    BFS(&graph, 0);
    printf("\n");

    freeGraph(&graph);

    return 0;
}
