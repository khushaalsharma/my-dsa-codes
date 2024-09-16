//done using set can also be done using minheap or priority_queue

#include <bits/stdc++.h> 
#include <unordered_map>
#include <set>
#include <list>
vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    unordered_map<int,list<pair<int,int>>> adj;
    for(int i=0;i<edges;i++){
        int u = vec[i][0];
        int v = vec[i][1];
        int w = vec[i][2];
        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));
    }
    vector<int> dist(vertices, INT_MAX);
    //set for short distance track 
    set<pair<int,int>> st;
    //pair is order (distance,node)
    dist[source] = 0;
    st.insert(make_pair(0,source));
    
    while(!st.empty()){
        //taking front node
        auto p = *(st.begin());
        st.erase(st.begin());
        
        int dis = p.first;
        int node = p.second;
        for(auto i : adj[node]){
            if(dis+i.second < dist[i.first]){
                auto record = st.find(make_pair(dist[i.first],i.first));
                if(record != st.end()){//record found then erase
                    st.erase(record);
                }
                dist[i.first] = dis + i.second;
                st.insert(make_pair(dist[i.first],i.first));
            }
        }
    }
    
    return dist;
    
}
