// topological sort using DFS traversal
#include <bits/stdc++.h> 
#include <unordered_map>
#include <list>
#include <stack>

void topoSort(unordered_map<int,list<int>>&adj, vector<bool>&visit, int node, stack<int>& st){
    visit[node] = true;
    
    for(auto i : adj[node]){
        if(!visit[i]){
            topoSort(adj,visit,i,st);
        }
    }
    
    st.push(node);
}
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    unordered_map<int,list<int>> adj;
    for(int i=0; i<edges.size();i++){
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
    }
    
    vector<bool> visit(v);
    stack<int> st;
    for(int i=0; i<v; i++){
        if(!visit[i]){
            topoSort(adj,visit,i,st);
        }
    }
    vector<int> ans;
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}
