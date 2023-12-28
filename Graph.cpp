#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

class Graph
{
private:
    vector<vector<int>> adj_list;

public:

    Graph(int num_vertices)
    {
        adj_list.resize(num_vertices);
    }

    void add_edge(int u, int v)
    {
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    void bfs(int start_vertex)
    {
        vector<bool> visited(adj_list.size(), false);
        queue<int> q;

        q.push(start_vertex);
        visited[start_vertex] = true;

        while (!q.empty())
        {
            int curr_vertex = q.front();
            q.pop();

            cout << curr_vertex << " ";

            for (int neighbor : adj_list[curr_vertex])
            {
                if (!visited[neighbor])
                {
                    q.push(neighbor);
                    visited[neighbor] = true;
                }
            }
        }

        cout << endl;
    }

    void dfs(int start_vertex)
    {
        vector<bool> visited(adj_list.size(), false);
        stack<int> s;

        s.push(start_vertex);

        while (!s.empty())
        {
            int curr_vertex = s.top();
            s.pop();

            if (!visited[curr_vertex])
            {
                cout << curr_vertex << " ";
                visited[curr_vertex] = true;

                for (int neighbor : adj_list[curr_vertex])
                {
                    if (!visited[neighbor])
                    {
                        s.push(neighbor);
                    }
                }
            }
        }

        cout << endl;
    }
};

int main()
{
    int num_vertices, num_edges, start_vertex;

    cout << "Enter the number of vertices: ";
    cin >> num_vertices;

    Graph graph(num_vertices);

    cout << "Enter the number of edges: ";
    cin >> num_edges;

    cout << "Enter the edges (u v):" << endl;
    for (int i = 0; i < num_edges; i++)
    {
        int u, v;
        cin >> u >> v;

        graph.add_edge(u, v);
    }

    cout << "Enter the start vertex for BFS and DFS: ";
    cin >> start_vertex;

    cout << "BFS: ";
    graph.bfs(start_vertex);

    cout << "DFS: ";
    graph.dfs(start_vertex);

    return 0;
}
