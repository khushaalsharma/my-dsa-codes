/*
Problem Type: Find the distinct ways

*/

long long solve(int dice, int face, int x, vector<vector<long long>> &dp){
    //base case
    if(x < 0){
        return 0;
    }
    if(dice == 0 && x != 0){
        return 0;
    }
    if(x == 0 && dice != 0){
        return 0;
    }
    if(x == 0  && dice == 0){
        return 1;
    }
    //end of base cases
    
    if(dp[dice][x] != -1){
        return dp[dice][x];
    }
    
    long long ans = 0;
    for(int i=1; i<=face; i++){
        ans = ans + solve(dice-1, face, x-i, dp);
    }
    return dp[dice][x] = ans;
    
}
long long noOfWays(int M , int N , int X) {
    vector<vector<long long>> dp(N+1, vector<long long>(X+1, -1));
    return solve(N, M, X, dp);
}
