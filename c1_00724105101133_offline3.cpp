
#include<bits/stdc++.h>
#include <windows.h>
#include <psapi.h>
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <vector>
#include <queue>
#include <iostream>
#include <functional>

#pragma comment(lib, "Psapi.lib")

using namespace std;

#define INF 1000000000
#define CPU_POWER_WATTS 65.0
#define BD_EMISSION_FACTOR 0.62

const int N=45;

vector<vector<int>> edges;
int totalEdge;

double measure_energy(double time_sec){
    return CPU_POWER_WATTS * time_sec;
}

void calcPerformance(LARGE_INTEGER start,LARGE_INTEGER end,LARGE_INTEGER freq){
    double elapsed =(double)(end.QuadPart - start.QuadPart)/ freq.QuadPart;
    double energy = measure_energy(elapsed);
    double energy_kWh = energy / 3.6e6;
    double co2 = energy_kWh * BD_EMISSION_FACTOR;
    PROCESS_MEMORY_COUNTERS_EX pmc;
     GetProcessMemoryInfo(GetCurrentProcess(),(PROCESS_MEMORY_COUNTERS*)&pmc,sizeof(pmc)
    );

    cout << fixed << setprecision(6);
    cout << "Execution time: " << elapsed << " seconds" << endl;
    cout << "Estimated energy: " << energy << " Joules" << endl;
    cout << "Peak memory: " << pmc.PeakWorkingSetSize / 1024 << " KB" << endl;
    cout << fixed << setprecision(8);
    cout << "Estimated CO2 (BD): " << co2 << " kg" << endl << endl;
}

void generate_sparse_graph(){
    edges.clear();
    int E = 150+rand()%51;
    for (int i=0;i<E;i++){
        int u = rand() % N;
        int v = rand() % N;
        while (u == v){
          v = rand() % N;
        }
        int w = rand() % 20 + 1;
        edges.push_back({u, v, w});
    }

    totalEdge = edges.size();
}

void generate_dense_graph(){
    edges.clear();
    for (int i = 0; i < N; i++){
        for (int j = i + 1; j < N; j++){
            int w = rand() % 20 + 1;
            edges.push_back({i, j, w});
            edges.push_back({j, i, w});
        }
    }
    totalEdge = edges.size() / 2;
}


void floydWarshall(){
    int dist[N][N];
   for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            if (i == j){
                dist[i][j] = 0;
            }
            else{
                dist[i][j] = INF;
            }
        }
    }

    for (auto e : edges){
        int u = e[0];
        int v = e[1];
        int w = e[2];
    if (w < dist[u][v]){
            dist[u][v] = w;
        }
    }

    for (int k = 0; k < N; k++){
        for (int i = 0; i < N; i++){
            for (int j = 0; j < N; j++){
                if (dist[i][k] != INF &&
                    dist[k][j] != INF &&
                    dist[i][k] + dist[k][j] < dist[i][j]){
                    dist[i][j] =dist[i][k] + dist[k][j];
                }
            }
        }
    }
}


vector<int> dijkstra(int V,vector<vector<pair<int,int>>> &adj,int S){
    vector<int> dist(V, INT_MAX);
    priority_queue<
        pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>
    > pq;

    dist[S] = 0;
    pq.push({0, S});

    while (!pq.empty()){
        int dis = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if (dis > dist[node]){
            continue;
        }

        for (auto &it : adj[node]){
            int adjNode = it.first;
            int weight = it.second;
            if (dis + weight < dist[adjNode]){
                dist[adjNode] =dis + weight;
             pq.push({dist[adjNode], adjNode});
            }
        }
    }

    return dist;
}


vector<int> bellman_ford(int V,vector<vector<int>> &edges,int S){
    vector<int> dist(V, INT_MAX);
    dist[S] = 0;
    for (int i = 0; i < V - 1; i++){
        bool changed = false;

        for (auto &it : edges){
            int u = it[0];
            int v = it[1];
            int wt = it[2];

            if (dist[u] != INT_MAX && dist[u] + wt < dist[v]){
                dist[v] = dist[u] + wt;
                changed = true;
            }
        }

        if(!changed){
            break;
        }
    }

    return dist;
}


void johnson(){
    vector<vector<int>> E = edges;
    for (int i=0; i<N;i++){
        E.push_back({N,i,0});
    }

        vector<int> h =bellman_ford(N + 1, E, N);
    vector<vector<pair<int,int>>> adj(N);
    for (auto &e : edges){
        int u = e[0];
        int v = e[1];
        int w = e[2];

        int newWeight=w+h[u]-h[v];

        adj[u].push_back({v, newWeight});
    }
    for (int i = 0; i < N; i++){
        vector<int> d =dijkstra(N, adj, i);
        for (int j = 0; j < N; j++){
            if (d[j] != INT_MAX){
                d[j] =d[j] - h[i] + h[j];
            }
        }
    }
}

int main()
{
    LARGE_INTEGER freq, start, end;
    QueryPerformanceFrequency(&freq);
    srand(time(0));
    generate_sparse_graph();
    cout << "Vertices: " << N << endl;
    cout << "Edges:" <<totalEdge<< endl;



    // Floyd-Warshall
    QueryPerformanceCounter(&start);
    floydWarshall();
    QueryPerformanceCounter(&end);
    cout<<"Floyd-Warshall Algorithm:"<<endl;
    calcPerformance(start, end, freq);


    // Johnson
    QueryPerformanceCounter(&start);
    johnson();
    QueryPerformanceCounter(&end);
    cout<<"Johnson's Algorithm:"<<endl;
    calcPerformance(start, end, freq);


    generate_dense_graph();

    cout << "Vertices: " << N << endl;
    cout << "Edges:" <<totalEdge<< endl;


    // Floyd-Warshall
    QueryPerformanceCounter(&start);
    floydWarshall();
    QueryPerformanceCounter(&end);
    cout<<"Floyd-Warshall Algorithm:"<<endl;
    calcPerformance(start, end, freq);


    // Johnson
    QueryPerformanceCounter(&start);
    johnson();
    QueryPerformanceCounter(&end);
    cout<<"Johnson's Algorithm:"<<endl;
    calcPerformance(start, end, freq);


    return 0;
}

