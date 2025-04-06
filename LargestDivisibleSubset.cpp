/*
maxi -> stores the last index of the largest subset with all pairs divisible
dp: stores the size of subsets at each index, all initialized to 1 as initially each subset has only one element
prev: stores the index of the previous element in the subset ending at nums[i], initially initialized to -1

*/


class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> dp(nums.size(), 1), prev(nums.size(), -1);
        int maxi = 0;
        for (int i = 1; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] % nums[j] == 0 && dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                    prev[i] = j;
                }
            }
            if (dp[i] > dp[maxi]) maxi = i;
        }
        vector<int> res;
        for (int i = maxi; i >= 0; i = prev[i]) {
            res.push_back(nums[i]);
            if (prev[i] == -1) break;
        }
        return res;
    }
};
