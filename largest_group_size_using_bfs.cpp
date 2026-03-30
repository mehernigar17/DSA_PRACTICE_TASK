#include<bits/stdc++.h>
using namespace std;

bool visited[100];
vector<int> graph[100];


int bfs(int start){
    queue<int> q;
    visited[start] = true;
    q.push(start);

    int count = 1; // group size

    while(!q.empty()){
        int node = q.front();
        q.pop();

        for(int i = 0; i < graph[node].size(); i++){
            int neighbour = graph[node][i];

            if(!visited[neighbour]){
                visited[neighbour] = true;
                q.push(neighbour);
                count++;
            }
        }
    }

    return count;
}

int main(){

    int n, e;
    cin >> n >> e;

    // input edges
    for(int i = 0; i < e; i++){
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    // visited initialize
    for(int i = 0; i < n; i++){
        visited[i] = false;
    }

    int maxGroup = 0;

    for(int i = 0; i < n; i++){
        if(!visited[i]){
            int groupSize = bfs(i);
            maxGroup = max(maxGroup, groupSize);
        }
    }

    cout << "Largest Friend Group: " << maxGroup << endl;

    return 0;
}
