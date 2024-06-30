/*
Approach:

consider this matrix
1 1 1 1
1 1 1 1
1 1 1 1 
1 1 1 1

each single 1 is a square itself.
We will check if the square is extensible to a higher dimension
for mat[0][0] = 1
check following for mat[1][1]
1) if it is equal to one
2) if at diagonal we have a square of some dimension, say n
3) if on left we have n 1's
4) if on top we have n 1's 

If these conditions are satisfied we can say that we have a square of dimension n+1

This can be solved using DP - recursion and memoization
*/
//TOP DOWN APPROACH: 0 to row-1, 0 to col-1
//Recursive solution -> TLE

int solve(vector<vector<int>> mat, int i, int j, int &maxi){
    if(i >= mat.size() || j >= mat[0].size()){
        return 0;//out of index
    }
    
    int right = solve(mat, i, j+1, maxi);
    int diagonal = solve(mat, i+1, j+1, maxi);
    int down = solve(mat, i+1, j, maxi);
    
    if(mat[i][j] == 1){
        int ans = min(right , min(diagonal, down)) + 1;
        maxi = max(maxi, ans);
        return ans;
    }
    else{
        return 0;
    }
    
}
int maxSquare(int n, int m, vector<vector<int>> mat){
    int maxi = 0;
    solve(mat, 0, 0, maxi);
    
    return maxi;
}


//Recursion + memoization -> may cause TLE

int solve(vector<vector<int>> &mat, int i, int j, int &maxi, vector<vector<int>> &dp){
    if(i >= mat.size() || j >= mat[0].size()){
        return 0;//out of index
    }
    
    if(dp[i][j] != -1){
        return dp[i][j];
    }
    
    int right = solve(mat, i, j+1, maxi, dp);
    int diagonal = solve(mat, i+1, j+1, maxi, dp);
    int down = solve(mat, i+1, j, maxi, dp);
    
    if(mat[i][j] == 1){
        int ans = min(right , min(diagonal, down)) + 1;
        maxi = max(maxi, ans);
        dp[i][j] = ans;
        return ans;
    }
    else{
        return 0;
    }
    
}
int maxSquare(int n, int m, vector<vector<int>> mat){
    int maxi = 0;
    vector<vector<int>> dp(n, vector<int>(m, -1));
    solve(mat, 0, 0, maxi, dp);
    
    return maxi;
}

//tabulation method
//BOTTOM UP APPROACH -> col-1 to 0, row-1 to 0

int solveTab(vector<vector<int>> &mat, int &maxi){
        
    int row = mat.size();
    int col = mat[0].size();
    vector<vector<int>> dp(row+1, vector<int>(col+1, 0)); //row+1 and col+1 as for right, diagonal and down row or col index for last elements can go beyond matrix limit
    
    for(int i=row-1; i>=0; i--){
        for(int j=col-1; j>=0; j--){
            int right = dp[i][j+1];
            int diagonal = dp[i+1][j+1];
            int down = dp[i+1][j]; 
            
            if(mat[i][j] == 1){
                dp[i][j] = 1 + min(right, min(diagonal, down));
                maxi = max(maxi, dp[i][j]);
            }
            else{
                dp[i][j] = 0;
            }
        }
    }
    
    return dp[0][0]; //doesn't mean anything as we require maxi's value
    
}
int maxSquare(int n, int m, vector<vector<int>> mat){
    int maxi = 0;
    solveTab(mat, maxi);
    
    return maxi;
}
