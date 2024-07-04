/*
type: DP with Strings
? -> replace any character
* -> replace any sequence


*/

class Solution {
public:
    bool solve(string& s, string& p, int i, int j, vector<vector<int>>& dp){
        //base case
        if(i<0 && j<0){
            return true;
        }
        if(i >= 0 && j < 0){//pattern is exhausted
            return false;
        }
        if(i < 0 && j >= 0){//string is exhausted has two case: its * or some other character
            for(int k=0; k<=j; k++){ //for some other character
                if(p[k] != '*'){
                    return false;
                }
            }

            return true; //for *
        }
        //base case

        if(dp[i][j] != -1){
            return dp[i][j]; //memoization
        }

        if(s[i] == p[j] || p[j] == '?'){//match found
            return solve(s, p, i-1, j-1, dp); 
        }
        else if(p[j] == '*'){//match may or maynot be found
            bool replaceAsEmptyString = solve(s, p, i, j-1, dp);
            bool replaceWithFoundChar = solve(s, p, i-1, j, dp);

            return dp[i][j] = (replaceAsEmptyString || replaceWithFoundChar);
        }
        else{ //match not found
            return dp[i][j] = false;
        }

    }
    bool isMatch(string s, string p) {
        vector<vector<int>> dp(s.length(), vector<int>(p.length(), -1));
        return solve(s, p, s.length()-1, p.length()-1, dp);   
    }
};
