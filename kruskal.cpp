// 00724105101138 Offline-4
#include <windows.h>
#include <psapi.h>
#include <stdio.h>
#include <stdlib.h>
#include<bits/stdc++.h>
using namespace std;
#pragma comment(lib, "Psapi.lib") // Needed for MSVC linking
// Replace with your CPU's approximate average power (Watts)
#define CPU_POWER_WATTS 65.0
// Bangladesh grid emission factor (kg CO2 / kWh)
#define BD_EMISSION_FACTOR 0.62

#define INF 1000000000

struct Edge {
    int w, u, v;
};
bool compare(Edge a, Edge b)
{
    return a.w < b.w;
}
int parent[1000], rnk[1000];

void MakeSet(int v)
{
    parent[v] = v;
    rnk[v] = 0;
}

int FindSet(int v)
{
    if (parent[v] != v)
        parent[v] = FindSet(parent[v]);
    return parent[v];
}

void Union(int a, int b)
{
    a = FindSet(a);
    b = FindSet(b);
    if (a == b) return;
    if (rnk[a] < rnk[b]) swap(a, b);
    parent[b] = a;
    if (rnk[a] == rnk[b]) rnk[a]++;
}




int main() {
LARGE_INTEGER freq, start, end;

ifstream fin("sparsegraph.txt");
//ifstream fin("densegraph.txt");
    if (!fin) {

        return 1;
    }

    int V, E;
    fin >> V >> E;

    vector<Edge> edges(E);
    for (int i = 0; i < E; i++) {
        int u, v, w;
        fin >> u >> v >> w;
        edges[i].u = u;
        edges[i].v = v;
        edges[i].w = w;
    }
fin.close();

QueryPerformanceFrequency(&freq);
QueryPerformanceCounter(&start);

// -------- Your algorithm here --------

    for (int v = 0; v < V; v++)
    {
      MakeSet(v);
    }
    sort(edges.begin(), edges.end(), compare);
    vector<Edge> T;
    int totalWeight = 0;

    for (auto& e : edges)
    {
        if (FindSet(e.u) != FindSet(e.v))
        {
            T.push_back(e);
            Union(e.u, e.v);
            totalWeight += e.w;
        }
     }
// -------------------------------------
QueryPerformanceCounter(&end);

  for (auto e : T)
  {
      cout << e.u << " , " << e.v << "  (w:  " << e.w << ")\n";
  }

  cout << "Total weight: " << totalWeight << "\n";





double elapsed = (double)(end.QuadPart - start.QuadPart) / freq.QuadPart;
double energy = CPU_POWER_WATTS * elapsed; // Joules
double energy_kWh = energy / 3.6e6; // kWh
double co2 = energy_kWh * BD_EMISSION_FACTOR; // kg CO2
// ----- Memory usage -----
PROCESS_MEMORY_COUNTERS_EX pmc;
if (GetProcessMemoryInfo(GetCurrentProcess(), (PROCESS_MEMORY_COUNTERS*)&pmc,
sizeof(pmc))) {
SIZE_T peakMemUsed = pmc.PeakWorkingSetSize; // Peak RAM usage
printf("Execution time: %.6f seconds\n", elapsed);
printf("Estimated energy consumption: %.2f Joules\n", energy);
printf("Peak Memory Usage: %zu KB\n", peakMemUsed / 1024);
printf("Estimated CO2 emissions (Bangladesh): %.8f kg\n", co2);
} else {
printf("Failed to get memory info.\n");
} return 0;}
