#include <vector>
#include <stdlib.h>
#include <queue>
class cmp{
    public:
    bool operator()(vector<int>&a, vector<int>&b){
        if(a[2]>b[2]){
            return true;
        }
    }
};
void makeSet(vector<int>&parent, vector<int>&rank){
    for(int i=0;i<rank.size();i++){
        parent[i] = i;
        rank[i] = 0;
    }
}
int findParent(vector<int>&parent, int node){
    if(parent[node] == node){
        return node;
    }
    return parent[node] = findParent(parent,parent[node]);//path compression
}
void makeUnion(int u, int v, vector<int>&parent, vector<int>&rank){
    int upar = findParent(parent,u);
    int vpar = findParent(parent,v);
    if(rank[upar] == rank[vpar]){
        parent[upar] = vpar;
        rank[vpar]++;
    }
    else if(rank[upar]>rank[vpar]){
        parent[vpar] = upar;
    }
    else{
        parent[upar] = vpar;
    }
}
int minimumSpanningTree(vector<vector<int>>& edges, int n)
{
    sort(edges.begin(),edges.end(),cmp);
    
    vector<int> parent(n);
    vector<int> rank(n);
    makeSet(parent,rank);
//     priority_queue<vector<int>, vector<vector<int>>, cmp> newds;
//     for(int i=0;i<edges.size();i++){
//         newds.push(edges[i]);
//     }
    int sum = 0;
    for(int i=0;i<edges.size();i++){
        //vector<int> top = newds.top();
        int u = findParent(parent,edges[i][0]);
        int v = findParent(parent,edges[i][1]);
        if(u != v){
            sum += edges[i][2];
            makeUnion(u,v,parent,rank);
        }
    }
    return sum;
}
