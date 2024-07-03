/*
Why did we use the map a dp array:
This is done as we have different values of diff variable for a given index
*/

class Solution{   
public:
    int bruteForce(int arr[], int N){
        int ans = 0;
        
        for(int i=0; i<N-1; i++){
            for(int j = i+1; j<N; j++){
                int diff = arr[j] - arr[i];
                int len = 2;
                int k = i-1;
                int last = arr[i];
                while(k >= 0){
                    if(last - arr[k] == diff){
                        last = arr[k];
                        len++;
                    }
                    k--;
                }
                
                ans = max(ans, len);
            }
        }
        
        return ans;
    }
    
    int solve(int i, int A[], int diff){ //backward recursive answer
        if(i < 0){
            return 0;
        }
        
        int ans = 0;
        
        for(int j=i-1; j >= 0; j--){
            if(A[i]-A[j] == diff){
                ans = max(ans, 1 + solve(j, A, diff)); 
            }
        }
        
        return ans;
    }
    
    int solveMem(int i, int A[], int diff, unordered_map<int, int> dp[]){ //backward recursive answer
        if(i < 0){
            return 0;
        }
        
        if(dp[i].count(diff)){
            return dp[i][diff];
        }
        
        int ans = 0;
        
        for(int j=i-1; j >= 0; j--){
            if(A[i]-A[j] == diff){
                ans = max(ans, 1 + solveMem(j, A, diff, dp)); 
            }
        }
        
        return dp[i][diff] = ans;
    }
    
    int lengthOfLongestAP(int A[], int n) {
        //return bruteForce(A, n);
        if(n <= 2){
            return n;
        }
        int ans = 0;
        //dp[i][diff] will represent the length of longest AP till i index of array(startign from 0)
        unordered_map<int, int> dp[n+1];
        
        for(int i=0; i<n-1; i++){
            for(int j = i+1; j<n; j++){
                ans = max(ans, 2 + solveMem(i, A, A[j]-A[i], dp));//will follow 2D DP as diff and index changes
            }
        }
        
        return ans;
    }
};
