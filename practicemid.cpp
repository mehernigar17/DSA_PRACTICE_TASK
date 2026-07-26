#include<bits/stdc++.h>
using namespace std;

const int N=1e6;
const int inf=1e9;
int n,e;
int parent[N];
int distance[N];
vector<pair<int,int>> graph[N];
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> q;
void initializeshort(int start){

for(int i=1;i<=n;i++){

    distance[i]=inf;
    parent[i]=-1;

}

distance[start]=0;

}

void relax(int u,int v,int w){


if(distance[v]>distance[u]+w){
    distance[v]=distance[u]+w;
  parent[v]=u;
  q.push{(distance[v],u};
}






}
void dijkstra(vector<pair<int,int>> &a){

q.push(a);
while(!q.empty()){

   int node=q.top().second;
   int dist=q.top().first;
   q.pop();
   if(dist>distance[node]){
    continue;
   }

   for(auto i:graph[node]){

    int u=i.first;
    int w=i.second;
    relax(node,u,w);

   }

}






}

int main(){

int n,e;
cin>>n>>e;
for(int i=0;i<e;i++){

  int u,v,w;
  cin>>u>>v>>w;
  graph[u]  .push_back({v,w});



}

int start=1;




initializeshort(start);





  pair<int,int> root={0,start};
   dijkstra(root);

   cout << endl;

   for(int i = 1; i <= n ; i++ )
   {
       cout << distances[i] << " ";
   }







return 0;
}
