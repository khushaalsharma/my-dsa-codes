#include <unordered_map>
#include <set>
#include <vector>
void dfs(unordered_map<int,set<int>> &adj, unordered_map<int,bool>&visit, int node, vector<int>&ans){
    visit[node] = true;
    ans.push_back(node);
    for(auto i:adj[node]){
        if(!visit[i]){
            dfs(adj,visit,i,ans);
        }
    }
}
vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)//vector<vector<int>> is used becayse the graph is assumed to be undirected and disconnected
{
    unordered_map<int,set<int>> adj;
    unordered_map<int,bool> visit;
    vector<vector<int>> result;
    for(int i=0;i<edges.size();i++){
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].insert(v);
        adj[v].insert(u);
    }
    for(int i=0;i<V;i++){
        if(!visit[i]){
            vector<int> ans;
            dfs(adj,visit,i,ans);
            result.push_back(ans);
        }
    }
    return result;
}
