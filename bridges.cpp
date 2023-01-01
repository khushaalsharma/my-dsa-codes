//Bridges in a graph using DFS technique

#include <unordered_map>
#include <list>
void dfs(int node, int parent, int &timer, unordered_map<int,list<int>>&adj, unordered_map<int,bool>&vis, vector<int>&low,vector<int>&disc, vector<vector<int>>&ans){
    vis[node] = true;
    disc[node] = low[node] = timer++;
    for(auto nbr : adj[node]){
        if(nbr == parent){
            continue;
        }
        else if(!vis[nbr]){
            dfs(nbr,node,timer,adj,vis,low,disc,ans);
            low[node] = min(low[node],low[nbr]);
            //checking for bridge
            if(low[nbr] > disc[node]){
                vector<int> a;
                a.push_back(node);
                a.push_back(nbr);
                ans.push_back(a);
            }
        }
        else{
            //back edge case
            low[node] = min(low[node],disc[nbr]);
        }
    }
}
vector<vector<int>> findBridges(vector<vector<int>> &edges, int v, int e) {
    unordered_map<int,list<int>> adj;
    for(int i=0;i<e;i++){
        int u = edges[i][0];
        int v = edges[i][1];
        
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int timer = 0;
    vector<int> disc(v);
    vector<int> low(v);
    int parent = -1;
    unordered_map<int,bool> vis;
    vector<vector<int>> ans;

    for(int i=0;i<v;i++){
        low[i] = -1;
        disc[i] = -1;
    }
    
    //initiate algo
    for(int i=0;i<v;i++){
        if(!vis[i]){
            dfs(i,parent,timer,adj,vis,low,disc,ans);
        }
    }    
    return ans;
}
