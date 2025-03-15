#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define HASH_TABLE_SIZE 1009

typedef struct WeightNode {
    int weight;
    struct WeightNode* next;
} WeightNode;

WeightNode* weightTable[HASH_TABLE_SIZE] = {NULL};

// Returns pointer to the shared weight; creates a new node if not found.
int* get_weight(int weight) {
    int index = abs(weight) % HASH_TABLE_SIZE;
    WeightNode* current = weightTable[index];
    while (current != NULL) {
        if (current->weight == weight) {
            return &(current->weight);
        }
        current = current->next;
    }
    WeightNode* newNode = (WeightNode*)malloc(sizeof(WeightNode));
    if (newNode == NULL) {
        fprintf(stderr, "Memory allocation error: Could not create new WeightNode.\n");
        exit(EXIT_FAILURE);
    }
    newNode->weight = weight;
    newNode->next = weightTable[index];
    weightTable[index] = newNode;
    return &(newNode->weight);
}

void freeWeightTable() {
    for (int i = 0; i < HASH_TABLE_SIZE; i++) {
        WeightNode* current = weightTable[i];
        while (current != NULL) {
            WeightNode* temp = current;
            current = current->next;
            free(temp);
        }
        weightTable[i] = NULL;
    }
}

typedef struct Edge {
    int dest;
    int* weight;  // shared weight pointer
    struct Edge* next;
} Edge;

typedef struct Graph {
    int numVertices;
    Edge** adjLists;
} Graph;

// Creates a graph with the specified number of vertices.
Graph* createGraph(int vertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    if (graph == NULL) {
        fprintf(stderr, "Memory allocation error: Could not create Graph.\n");
        exit(EXIT_FAILURE);
    }
    graph->numVertices = vertices;
    graph->adjLists = (Edge**)malloc(vertices * sizeof(Edge*));
    if (graph->adjLists == NULL) {
        fprintf(stderr, "Memory allocation error: Could not create adjLists.\n");
        free(graph);
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
    }
    return graph;
}

// Adds an edge from src to dest with the given weightValue.
void addEdge(Graph* graph, int src, int dest, int weightValue) {
    int* sharedWeight = get_weight(weightValue);
    Edge* newEdge = (Edge*)malloc(sizeof(Edge));
    if (newEdge == NULL) {
        fprintf(stderr, "Memory allocation error: Could not create new Edge.\n");
        exit(EXIT_FAILURE);
    }
    newEdge->dest = dest;
    newEdge->weight = sharedWeight;
    newEdge->next = graph->adjLists[src];
    graph->adjLists[src] = newEdge;
}

// Prints the graph's adjacency list.
void printGraph(Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        Edge* temp = graph->adjLists[i];
        printf("Node %d:\n", i);
        while (temp) {
            printf(" -> %d (weight = %d, address = %p)\n", temp->dest, *(temp->weight), (void*)temp->weight);
            temp = temp->next;
        }
        printf("\n");
    }
}

void freeGraph(Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        Edge* temp = graph->adjLists[i];
        while (temp) {
            Edge* toFree = temp;
            temp = temp->next;
            free(toFree);
        }
    }
    free(graph->adjLists);
    free(graph);
}

int main() {
    Graph* graph = createGraph(5);
    addEdge(graph, 0, 1, 2);
    addEdge(graph, 0, 2, 5);
    addEdge(graph, 1, 2, 1);
    addEdge(graph, 1, 3, 4);
    addEdge(graph, 2, 3, 2);
    addEdge(graph, 3, 4, 2);
    addEdge(graph, 4, 0, 5);
    addEdge(graph, 2, 4, 4);
    addEdge(graph, 4, 1, 1);
    printGraph(graph);
    freeGraph(graph);
    freeWeightTable();
    return 0;
}
