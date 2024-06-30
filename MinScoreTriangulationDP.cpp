/*
Approach: 

We consider the base of the first triangle as the first and last vertex(or index of array)
using this as base we will check all possible combinations of the triangles formed within the polygon with the said base

as we choose a triangle our polygon can be written as 
original_polygon = sub_polygon1 + chosen_triangle + sub_polygon2

We will make recursive calls to solve these sub polygons or recursive sub problems

*/
//Recursive solution
class Solution {
public:
    int solve(vector<int> &values, int start, int end){
        if(start+1 == end){//base case ie a subproblem represents a line segment instead of polygon
            return 0;
        }
        
        int ans = INT_MAX;
        for(int i=start+1; i<end; i++){
            ans = min(ans, values[start]*values[i]*values[end] + solve(values, start, i) + solve(values, i, end));
        }

        return ans;
    }
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();

        return solve(values, 0, n-1);
    }
};


//using memoization and recusion TC: 0ms
class Solution {
public:
    int solve(vector<int> &values, int start, int end, vector<vector<int>> &dp){
        if(start+1 == end){//base case ie a subproblem represents a line segment instead of polygon
            return 0;
        }

        if(dp[start][end] != -1){
            return dp[start][end];
        }
        
        int ans = INT_MAX;
        for(int i=start+1; i<end; i++){
            ans = min(ans, values[start]*values[i]*values[end] + solve(values, start, i, dp) + solve(values, i, end, dp));
        }
        dp[start][end] = ans;
        return ans;
    }
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));

        return solve(values, 0, n-1, dp);
    }
};
