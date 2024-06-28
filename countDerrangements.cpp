/*
Approach:
  Consider an array of size n given as : 0,1,2,3,....,i,..n-1
  This is the og way of order for numbers

  say I want to shift 0's position thus recusively I can write it as:
    (n-1)*[solution of sub-problems]

    Here the subproblems can be of 2 types:
    1) Swaping 0 and i -> 
        We have now i,1,2,3,....0,..n-1 Thus unshifted elements : n-2
      
    2) Swaping 0 at ith position but not i with 0's position
        Thus unfixed/unshifted numbers = n-1

Hence formula = (n-1)*[f(n-1) + f(n-2)]
*/

//Solution using Recursion and memoization

#include <iostream>
#include <vector>

using namespace std;

#define mod 1000000007

long long int countDerangements(int n, vector<long long int> &mem) {
    // Write your code here.

    //base case
    if(n==0){
        return 0;
    }

    if(n==2){
        return 1;
    }

    if(mem[n] != -1){
        return mem[n];
    }

    int ans = (((n-1)%mod) * ((countDerangements(n-1, mem)%mod) + (countDerangements(n-2, mem)%mod))%mod);
    mem[n] = ans;
    return ans;
}

long long int countDerangements(int n) {
    // Write your code here.

    vector<long long int> memoization(n+1, -1);
    int ans = countDerangements(n, memoization);

    return ans;
}
