#include <bits/stdc++.h> 
#include <unordered_map>
#include <set>
#include <queue>
void createAdj(unordered_map<int,set<int>> &adj, vector<pair<int,int>> edges){
    for(int i=0;i<edges.size();i++){
        int u = edges[i].first;
        int v = edges[i].second;
        adj[u].insert(v);
        adj[v].insert(u);
    }
    return ;
}
void bfs(unordered_map<int,set<int>>&adj, unordered_map<int,bool>&visit, vector<int>& ans, int node){
    queue<int> q;
    q.push(node);
    visit[node] = true;
     while(!q.empty()){
         int front = q.front();
         q.pop();
         ans.push_back(front);
        for(auto i:adj[front]){
            if(!visit[i]){
                q.push(i);
                visit[i]  =true;
            }
        }
     }
}
vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    unordered_map<int, set<int>>  adj;
    vector<int> ans;
    unordered_map<int,bool> visit;
    createAdj(adj,edges);
    
    for(int i=0;i<vertex;i++){
        if(!visit[i]){
            bfs(adj,visit,ans,i);
        }
    }
    return ans;
}
