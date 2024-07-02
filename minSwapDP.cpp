/*
VVIMP 

Approach
1) insert -1 at beginning of each array -> done to handle prev for first element of the arrays
2) condition of not swap: arr1[i-1] <= arr1[i]  && arr2[i-1] <= arr2[i]
3) base case: if index == n: return 0
4) using swapped bool to handle the case when previous index were swapped
*/

class Solution {
public:
    int solve(vector<int>& nums1, vector<int>& nums2, int index, bool swapped, vector<vector<int>> &dp){
        if(index >= nums1.size()){
            return 0;
        }

        if(dp[index][swapped] != -1){
            return dp[index][swapped];
        }

        int ans = INT_MAX;
        int prev1 = nums1[index-1];
        int prev2 = nums2[index-1];

        //use of swapped
        if(swapped){
            swap(prev1, prev2);
        }

        if(nums1[index] > prev1 && nums2[index] > prev2){
            ans = min(ans, solve(nums1, nums2, index+1, 0, dp));
        } //no swap
        if(nums1[index] > prev2 && nums2[index] > prev1){
            ans = min(ans, 1 + solve(nums1, nums2, index+1, 1, dp));
        } //swap

        return dp[index][swapped] = ans;
    }
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        //this problem requires us to show the minimum swaps and not the actual increasing arrays
        //thus we don't change the arrays ie literally swapping the elements
        //we handle it using swapped boolean

        nums1.insert(nums1.begin(), -1);
        nums2.insert(nums2.begin(), -1);
        
        bool swapped = 0; //to handle the case when the previous indexes were swapped
        
        vector<vector<int>> dp(nums1.size()+1, vector<int>(2, -1));

        return solve(nums1, nums2, 1, swapped, dp);
    }
};
