
 #include <bits/stdc++.h>
using namespace std;

vector<int> graph[10000];
bool visited[10000];

void Dfs(int start){

    visited[start] = true;
    cout << start << " ";

    for (int i : graph[start]) {
        if (!visited[i]) {
            Dfs(i);
        }
    }
}


int main()
{
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
        for(int j = 0; j < graph[i].size(); j++){
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
for(int i = 0; i < n; i++){
visited[i] = false;
}
cout << "DFS Traversal: ";
Dfs(0);
return 0;
}
