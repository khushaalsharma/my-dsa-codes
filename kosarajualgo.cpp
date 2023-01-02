//FINDING THE NO. OF STRONLY CONNECTED COMPONENTS USING KOSIRAJU ALGORITHM

#include<bits/stdc++.h>
void dfs(unordered_map<int, list<int> > &adj, unordered_map<int, bool> &vis, 
        stack<int> &st, int node){
    vis[node] = true;
    
    for(auto i:adj[node]){
        if(!vis[i])
            dfs(adj, vis, st, i);
    }
    st.push(node);
}
 void tfdfs(unordered_map<int, list<int> > &transpose, unordered_map<int, bool> &vis,  int node){
     
     vis[node] = true;
     for(auto i:transpose[node]){
         if(!vis[i])
             tfdfs(transpose, vis, i);
     }
     
 }
int stronglyConnectedComponents(int v, vector<vector<int>> &edges)
{
    unordered_map<int, list<int> > adj;
    for(int i = 0; i < edges.size(); i++){
        int u = edges[i][0];
        int v = edges[i][1];
        
        adj[u].push_back(v);
     
    }
    unordered_map<int, bool> vis;
    stack<int> st;
    for(int i = 0; i < v; i++){
        if(!vis[i])
            dfs(adj, vis, st, i);
    }
    unordered_map<int, list<int> > transpose;
    for(int i = 0; i < v; i++){
        vis[i] = 0;
        for(auto nbr:adj[i])
            transpose[nbr].push_back(i);
    }
    int cnt = 0;
    while(!st.empty()){
        int top = st.top();
        st.pop();
        
        if(!vis[top]){
            cnt ++;
            tfdfs(transpose, vis, top);
        }
    }
    return cnt;
}
