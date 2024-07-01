/*
LeetCode Hard problem on Dynamic Programming

Approach: use knapsack pattern of including and excluding dish
Steps:
1) sort the given satisfaction array 
2) Apply the knapsack approach
*/

class Solution {
public:
    int solve(vector<int> &satis, int dishIndex, int time, vector<vector<int>> &dp){
        if(dishIndex >= satis.size()){
            return 0;
        }//base case

        if(dp[dishIndex][time] != -1){
            return dp[dishIndex][time];
        }

        int ans;

        int include = solve(satis, dishIndex+1, time+1, dp) + satis[dishIndex]*time;
        int exclude = solve(satis, dishIndex+1, time, dp);

        ans = max(include, exclude);
        dp[dishIndex][time] = ans;
        return ans;
    }
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end());
        int n = satisfaction.size();

        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        return solve(satisfaction, 0, 1, dp);
    }
};
