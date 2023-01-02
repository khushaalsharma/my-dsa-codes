//Shortest path using Bellman-Ford technique to be used if the graph has negative weights

#include <bits/stdc++.h> 
#include <unordered_map>
#include <list>
#include <math.h>

int bellmonFord(int n, int m, int src, int dest, vector<vector<int>> &edges) {
    vector<int> dist(n+1,1e9);
    dist[src] = 0;
    //distance updated n-1 times
    for(int i=1;i<n;i++){
        //traversal on edge list
        for(int j=0;j<m;j++){
            int u = edges[j][0];
            int v = edges[j][1];
            int w = edges[j][2];
            
            if(dist[u] != 1e9 && (dist[u]+w < dist[v])){
                dist[v]= dist[u] + w;
            }
        }
    }
    //check for negative cycle
    bool flag = 0;
    for(int j=0;j<m;j++){
        int u = edges[j][0];
        int v = edges[j][1];
        int w = edges[j][2];

        if(dist[u] != 1e9 && (dist[u]+w < dist[v])){
            dist[v]= dist[u] + w;
        }
    }
    if(flag == 0){
        return dist[dest];
    }
    else{
        return 1e9;
    }
}
