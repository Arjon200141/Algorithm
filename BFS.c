#include <stdio.h>
#include <stdbool.h>
#define MAX 100

int queue[MAX], front = -1, rear = -1;
int visited[MAX];
int graph[MAX][MAX];

void enqueue(int x)
{
    if (rear == MAX - 1)
    {
        printf("Queue overflow\n");
    }
    else
    {
        if (front == -1)
        {
            front = 0;
        }
        rear++;
        queue[rear] = x;
    }
}
int dequeue()
{
    int element;
    if (front == -1 || front > rear)
    {
        printf("Queue underflow\n");
        return -1;
    }
    else
    {
        element = queue[front];
        front++;
        return element;
    }
}
void bfs(int start, int num_nodes)
{
    int i, current;
    enqueue(start);
    visited[start] = true;
    while (front != -1)
    {
        current = dequeue();
        printf("%d ", current);
        for (i = 0; i < num_nodes; i++)
        {
            if (graph[current][i] == 1 && !visited[i])
            {
                enqueue(i);
                visited[i] = true;
            }
        }
    }
}
int main()
{
    int i, j, num, start_node;
    printf("Number of nodes : ");
    scanf("%d", &num);
    printf("Adjacency matrix : \n");
    for (i = 0; i < num; i++)
    {
        for (j = 0; j < num; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }
    printf("Enter the starting node: ");
    scanf("%d", &start_node);
    printf("BFS traversal is: ");
    bfs(start_node, num);
    printf("\n");
    return 0;
}
