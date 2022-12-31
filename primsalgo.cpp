//TO FIND THE MINIMUM SPANNING TREE

#include <bits/stdc++.h> 
#include <unordered_map>
#include <list>
#include <limits.h>
vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    unordered_map<int,list<pair<int,int>>> adj;
    for(int i=0; i<g.size(); i++){
        int u = g[i].first.first;
        int v = g[i].first.second;
        int w = g[i].second;
        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));
    }
    unordered_map<int,bool> mst;
    unordered_map<int,int> key;
    unordered_map<int,int> parent;
    key[1] = 0;
    parent[1] = -1;
    for(int i=2;i<=n;i++){
        key[i] = INT_MAX;
        parent[i] = -1;
    }
    
    for(int i=1;i<=n;i++){
        int mini = INT_MAX;
        int u;
        //finding minimum node
        for(int j=1;j<=n;j++){
            if(mst[j] == 0 && key[j]<mini){
                u = j;
                mini = key[j];
            }
        }
        //set mst[u]
        mst[u] = true;
        for(auto it : adj[u]){
            int node = it.first;
            int dis = it.second;
            if(mst[node] == false && dis < key[node]){
                parent[node] = u;
                key[node] = dis;
            }
        }
    }
    vector<pair<pair<int, int>, int>> ans;
    for(int i=2;i<=n;i++){
        ans.push_back({{parent[i],i},key[i]});
    }
    return ans;
}
