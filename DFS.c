#include <stdio.h>
#include <stdlib.h>
#define MAX_NODES 100

typedef struct
{
    int data;
    int visited;
} Node;

Node* create(int data)
{
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->visited = 0;
    return node;
}
void DFS(Node* start, Node* graph[], int numNodes)
{
    printf("%d ", start->data);
    start->visited = 1;

    for (int i = 0; i < numNodes; i++)
    {
        Node* current = graph[i];
        if (!current->visited && start != current)
        {
            DFS(current, graph, numNodes);
        }
    }
}
int main()
{
    int numNodes, numEdges;
    printf("Number of nodes: ");
    scanf("%d", &numNodes);

    Node* graph[MAX_NODES];

    for (int i = 0; i < numNodes; i++)
    {
        graph[i] = create(i);
    }

    printf("Number of edges : ");
    scanf("%d", &numEdges);

    for (int i = 0; i < numEdges; i++)
    {
        int source, des;
        printf("Enter edge %d (source destination): ", i + 1);
        scanf("%d %d", &source, &des);

        graph[source]->visited = 0;
        graph[des]->visited = 0;

        printf("DFS Traversal: ");
        for (int i = 0; i < numNodes; i++)
        {
            if (!graph[i]->visited)
            {
                DFS(graph[i], graph, numNodes);
            }
        }
        return 0;
    }
}
