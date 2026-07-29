#include <bits/stdc++.h>
using namespace std;

vector<int> graph[1000];
bool visited[1000];

int bfsDepth(int source) {
    queue<pair<int,int>> q; // {node, depth}

    q.push({source, 0});
    visited[source] = true;

    int maxDepth = 0;

    while (!q.empty()) {
        int node = q.front().first;
        int depth = q.front().second;
        q.pop();

        maxDepth = max(maxDepth, depth);

        for (int child : graph[node]) {
            if (!visited[child]) {
                visited[child] = true;
                q.push({child, depth + 1});
            }
        }
    }

    return maxDepth;
}

int main() {
    int n, e;
    cin >> n >> e;

    for (int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;

        graph[u].push_back(v);
        graph[v].push_back(u); // remove for directed graph
    }

    cout << "Depth = " << bfsDepth(0) << endl;
}
