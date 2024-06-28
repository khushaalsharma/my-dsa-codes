/*
VERY VERY IMPORTANT QUESTION

Given n posts in fence and k color, we are required to tell the no. of possible ways of painting the fences such that not more than two adjacent posts have same color

for n=1
same = 0, diff = k
total = k

This will make a following table: for all k >= 2;
            n=2            n=3
same color   k ways        k*k - k ways
diff color   k*k - k ways  (k-1) - k*k ways
Total        k*k ways      k**3 - k ways        and so on

thus 
total[i] = same[i] + diff[i]
same[i]  = diff[i-1]
diff[i]  = total[i-1] * (k-1)
*/

#include <bits/stdc++.h> 

using namespace std;

#define mod 1000000007

long long int ways(int n, int k){ //using tabulation method
    long dp[n+1];
    memset(dp, 0, sizeof(dp));

    dp[1] = k;
    dp[2] = k*k;

    for(int i=3; i<=n ;i++){
        dp[i] = ((k-1)*(dp[i-1] + dp[i-2])) % mod;
    }

    return dp[n];
}

int numberOfWays(int n, int k) {
    long long int ans  = ways(n, k);

    return ans%mod;
}
