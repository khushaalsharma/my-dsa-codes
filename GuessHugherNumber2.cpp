/*
Type: DP + Merge Intervals

This problem requires us to plan for the worst case instead of playing the game
We assume that at every chance, we make a wrong guess and hence have to pay that amount thus considering only the worst case ie wrong

for i to n ans = min(ai) i goes 1 to n
and ai = i + max(f(1, i-1), f(i+1, n)) -> subproblem solution
*/

class Solution {
public:
    int solve(int start, int end, vector<vector<int>> &dp){
        if(start >= end){
            return 0;
        }

        if(dp[start][end] != -1){
            return dp[start][end];
        }

        int ans = INT_MAX;
        for(int i=start ; i<=end; i++){
            ans = min(ans, i + max(solve(start, i-1, dp), solve(i+1, end, dp)));
        }

        return dp[start][end] = ans;
    }
    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        return solve(1, n, dp);
    }
};
