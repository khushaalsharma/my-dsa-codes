//FINDING NO. OF ARTICULATION POINTS SAME APPROACH AS OF BRIDGES IN GRAPH

#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>

using namespace std;

void dfs(int node, int parent, int &timer, vector<int> &cnt, unordered_map<int,list<int>>&adj, unordered_map<int,bool>&vis, vector<int>&low, vector<int>&disc){
    vis[node] = true;
    low[node] = disc[node] = timer++;

    for(auto i : adj[node]){
        if( i == parent){
            continue;
        }
        else if(!vis[i]){
            dfs(i,node,timer,cnt,adj,vis,low,disc);
            low[node] = min(low[node],low[i]);

            //checking for articulation point
            if(low[i] >= disc[node]){
                if(parent != -1){
                    cnt.push_back(node);
                }
                else{
                    if(i>1){
                        cnt.push_back(node);
                    }
                }
            }
        }
        else{
            low[node] = min(low[node],disc[i]);
        }
    }
}

void countArticulationPoints(vector<vector<int>> &edges, int v){
    unordered_map<int,list<int>> adj;
    for(int i=0;i<edges.size();i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> cnt;
    vector<int> disc(v);
    vector<int> low(v);
    int timer = 0;
    int parent = -1;
    unordered_map<int,bool> vis;

    //initiating algo
    for(int i=0;i<v;i++){
        if(!vis[i]){
            dfs(i,parent,timer,cnt,adj,vis,low,disc); 
        }
    }
    for(int i=0;i<cnt.size();i++){
        cout<<cnt[i]<<" ";
    }
}
int main(){
    vector<vector<int>> edges;
    edges = {{1,0},{1,2},{0,3},{3,4},{0,4}};
    cout<<"Articulation Points: "<<endl;
    countArticulationPoints(edges,5);
    return 0;
}
