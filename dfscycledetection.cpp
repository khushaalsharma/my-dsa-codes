//cycle detection in directed graph
#include <unordered_map>
#include <list>
bool dfscycle(unordered_map<int,list<int>>&adj, unordered_map<int,bool> &visit, int node,unordered_map<int,bool> &dfsvis){
    visit[node] = true;
    dfsvis[node] = true;
    for(auto i : adj[node]){
        if(!visit[i]){
            bool check = dfscycle(adj,visit,i,dfsvis);
            if(check){
                return true;
            }
        }
        else if(dfsvis[i] == true){
            return true;
        }
    }
   dfsvis[node] = false;
   return false;
}

int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  unordered_map<int,list<int>> adj;
    for(int i=0;i<edges.size();i++){
        int src = edges[i].first;
        int dst = edges[i].second;
        adj[src].push_back(dst);
    }
    unordered_map<int,bool> visit;
    unordered_map<int,bool> dfsvis;
    for(int i=1;i<=n;i++){
        if(!visit[i]){
            bool ans = dfscycle(adj,visit,i,dfsvis);
            if(ans == true){
                return 1;
            }
        }
    }
    return 0;
}
