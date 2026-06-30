
#include <bits/stdc++.h>
using namespace std;

vector<int> graph[1000];
int indegree[1000];

int main()
{
    int n, e;
    cin >> n >> e;

    // Directed graph input
    for(int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;

        graph[u].push_back(v);
        indegree[v]++;   // incoming edge count
    }

    queue<int> q;

    // Step 1: push all nodes with indegree 0
    for(int i = 0; i < n; i++)
    {
        if(indegree[i] == 0)
        {
            q.push(i);
        }
    }

    vector<int> topo;

    // Step 2: BFS process
    while(!q.empty())
    {
        int node = q.front();
        q.pop();

        topo.push_back(node);

        for(int i = 0; i < graph[node].size(); i++)
        {
            int neighbor = graph[node][i];

            indegree[neighbor]--;

            if(indegree[neighbor] == 0)
            {
                q.push(neighbor);
            }
        }
    }

    // Step 3: print result
    cout << "Topological Sort: ";

    for(int i = 0; i < topo.size(); i++)
    {
        cout << topo[i] << " ";
    }

    cout << endl;

    return 0;
}
