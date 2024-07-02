class Solution {
public:

    int solve(int start, int end, vector<int> &slices, int slice, vector<vector<int>> &dp){
        //base case
        if(slice == 0 || start > end){
            return 0;
        }

        if(dp[start][slice] != -1){
            return dp[start][slice];
        }

        int include = slices[start] + solve(start+2, end, slices, slice-1, dp);
        int exclude = solve(start+1, end, slices, slice, dp);

        return dp[start][slice] = max(include, exclude);
    }
    int maxSizeSlices(vector<int>& slices) {
        int size = slices.size();
        int n = size/3;
        vector<vector<int>> dp1(size, vector<int>(size, -1));
        vector<vector<int>> dp2(size, vector<int>(size, -1));
        int case1 = solve(0, size-2, slices, n, dp1);
        int case2 = solve(1, size-1, slices, n, dp2);

        return max(case1, case2);
    }
};
