
#include <bits/stdc++.h>
using namespace std;

vector<int> graph[1000];
bool visited[1000];

void Bfs(int start){
    queue<int> q;
    visited[start] = true;

    q.push(start);

    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        cout << node << " ";
        for(int i = 0; i < graph[node].size(); i++)
        {
           int neighbor = graph[node][i];
           if(!visited[neighbor])
           {
             visited[neighbor] = true;
             q.push(neighbor);
           }
        }
    }
}

int main(){
    int n, e;
    cin >> n >> e;
    for(int i = 0; i < e; i++){
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
     for(int i = 0; i < n; i++){
        cout << i << " -> ";
        for(int j = 0; j < graph[i].size(); j++)
        {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
    for(int i = 0; i < n; i++){
            visited[i] = false;
    }
    cout << "BFS Traversal: ";
    Bfs(0);
    return 0;}


