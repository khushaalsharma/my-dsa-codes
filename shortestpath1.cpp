//Shortest path in undirected graph from src node to dst node

#include <unordered_map>
#include <list>
#include <queue>

vector<int> shortestPath( vector<pair<int,int>> edges , int n , int m, int s , int t){
	
	unordered_map<int,list<int>> adj;
    for(int i=0;i<edges.size();i++){
        int u = edges[i].first;
        int v = edges[i].second;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    unordered_map<int,bool> vis;
    unordered_map<int,int> parent;
    
    queue<int> q;
    q.push(s);
    vis[s] = true;
    parent[s] = -1;
	  while(!q.empty()){
        int front = q.front();
        q.pop();
        for(auto i : adj[front]){
            if(!vis[i]){
                vis[i] = true;
                parent[i] = front;
                q.push(i);
            }
        }
    }
    
    vector<int> ans;
    int src = t;
    ans.push_back(src);
    while(src != s){
        src = parent[src];
        ans.push_back(src);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

