class Solution {
public:
    // int removeStones(vector<vector<int>>& stones) {
    //     sort(stones.begin(), stones.end());

    //     int remStones = 0;

    //     map<int, vector<pair<int, int>>> rows;
    //     map<int, vector<pair<int, int>>> cols;

    //     for(auto stone : stones){
    //         int x = stone[0];
    //         int y = stone[1];

    //         rows[x].push_back(make_pair(x, y));
    //         cols[y].push_back(make_pair(x, y));
    //     }
    //     int n = stones.size();
    //     for(int i = n-1; i>=0; i--){
    //         int x = stones[i][0];
    //         int y = stones[i][1];

    //         if(rows[x].size() > 1 || cols[y].size() > 1){
    //             remStones++;

    //             //removing from both the tally maps
    //             auto itrRow = find(rows[x].begin(), rows[x].end(), make_pair(x, y));
    //             rows[x].erase(itrRow, itrRow+1);
    //             auto itrCol = find(cols[y].begin(), cols[y].end(), make_pair(x, y));
    //             cols[y].erase(itrCol, itrCol+1);
    //         }
    //     }

    //     return remStones;
    // } 
    //better to solve it using graph
    //consider an edge between node if they have same row/col
    void dfs(int i, vector<vector<int>>& stones, vector<bool>& vis){
        vis[i] = true;

        for(int j = 0; j < stones.size(); j++){
            if(!vis[j] && (stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1])){
                dfs(j, stones, vis);
            }
        }
    }
    int removeStones(vector<vector<int>>& stones){
        int n = stones.size();
        vector<bool> vis(n, false);

        int connectedStones = 0;

        for(int i=0; i<n; i++){
            if(!vis[i]){
                connectedStones++;
                dfs(i, stones, vis);
            }
        }

        return (n - connectedStones);
    }
};
