/*
This question has two approaches:
1) Dynamic Programming -> knapsack method(include,exclude) here we get all the possible inc subsequences
2) Array manipulation using binary search -> here we get only the length of array, the array may not have the subsequence in order
*/

//Function to find length of longest increasing subsequence.
    int solve(int n, int a[], int curr, int prev, vector<vector<int>> dp){
        if(curr == n){
            return 0;
        }//base case;
        
        if(dp[curr][prev+1] != -1){ //+1 is made as we begin with prev=-1
            return dp[curr][prev];
        }
        
        //including element
        int take = 0;
        if(prev == -1 || a[curr] > a[prev]){
            take = 1 + solve(n, a, curr+1, curr, dp);
        }
        
        int notTaken = solve(n, a, curr+1, prev, dp);
        
        dp[curr][prev+1] = max(take, notTaken);
        
        return dp[curr][prev+1];
    }
    
    int solveTab(int n, int a[]){
        //vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        
        vector<int> currA(n+1, 0); //as we can see on og tab code that for curr ans is dependent on curr+1 thus we will use two arrays instead of a matrix
        vector<int> next(n+1, 0);
        
        for(int curr = n-1; curr>=0; curr--){
            for(int prev = curr-1; prev >= -1; prev--){
                int take = 0;
                if(prev == -1 || a[curr] > a[prev]){
                    take = 1 + next[curr+1];
                }
                
                int notTaken = next[prev+1];
                
                currA[prev+1] = max(take, notTaken);
            } 
            
            next = currA;
        }
        
        return next[0]; //-1 + 1 = 0
    }
    
    int solveOptimal(int n, int a[]){
        if(n==0){
            return 0;
        }    
        
        vector<int> ans;
        ans.push_back(a[0]);
        
        for(int i=1; i<n; i++){
            if(a[i] > ans.back()){//back() fetches the last element pf vector
                ans.push_back(a[i]);
            }
            else{
                int lowerIndex = lower_bound(ans.begin(), ans.end(), a[i]) - ans.begin(); //the index with which we can replace current element
                ans[lowerIndex] = a[i];
            }
        }
        
        
        return ans.size(); //this method doesn;t take extra space the previous two functions take because of creating a new subsequence at every recursive call
    }
    
    int longestSubsequence(int n, int a[])
    {
       // your code here
       //vector<vector<int>> dp(n, vector<int>(n+1, -1)); 
       return solveOptimal(n, a);
    }
