/*
type: DP with Strings

approach
if(char match ir a[i] = b[j]):
  call for solution of further subproblem
else:
  insert -> solution of subpron after insert an element
  del -> solution of subpron after deleting the ele
  rep -> solution of subpron after replacing the elem
  ans = 1 + min(insert, del, rep)
All the three operations here are just visualized, we don't do them actually
*/

class Solution {
public:
    int solve(string a, string b, int i, int j, vector<vector<int>> &dp){
        if(i == a.length()){
            return b.length() - j;
        }
        if(j == b.length()){
            return a.length() - i;
        }
        //end of base case

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        int ans = 0;
        if(a[i] == b[j]){
            ans = solve(a, b, i+1, j+1, dp);
        }
        else{
            int insert = solve(a, b, i, j+1, dp);
            int del = solve(a, b, i+1, j, dp);
            int replace = solve(a, b, i+1, j+1, dp);

            ans = 1 + min(insert, min(del, replace));
        }

        return dp[i][j] = ans;
    }
    int minDistance(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        return solve(word1, word2, 0, 0, dp);
    }
};
