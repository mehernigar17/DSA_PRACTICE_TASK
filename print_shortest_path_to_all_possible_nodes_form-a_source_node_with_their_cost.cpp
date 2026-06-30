
#include <bits/stdc++.h>
using namespace std;

vector<int> graph[1000];
bool visited[1000];
int dist[1000];

void BFS(int source)
{
    queue<int> q;

    visited[source] = true;
    dist[source] = 0;

    q.push(source);

    while(!q.empty())
    {
        int node = q.front();
        q.pop();

        for(int i = 0; i < graph[node].size(); i++)
        {
            int neighbor = graph[node][i];

            if(!visited[neighbor])
            {
                visited[neighbor] = true;
                dist[neighbor] = dist[node] + 1;
                q.push(neighbor);
            }
        }
    }
}

int main()
{
    int n, e;
    cin >> n >> e;

    for(int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;

        graph[u].push_back(v);
        graph[v].push_back(u); // Undirected Graph
    }

    int source;
    cin >> source;

    for(int i = 0; i < n; i++)
    {
        visited[i] = false;
        dist[i] = -1;
    }

    BFS(source);

    cout << "Node\tCost" << endl;

    for(int i = 0; i < n; i++)
    {
        cout << i << "\t" << dist[i] << endl;
    }

    return 0;
}
