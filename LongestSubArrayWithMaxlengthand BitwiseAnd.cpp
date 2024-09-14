class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int maxElem = *max_element(nums.begin(), nums.end()); // Find the maximum element
        int maxLen = 0, currentLen = 0;
        
        for (int i = 0; i < n; i++) {
            if (nums[i] == maxElem) {
                currentLen++; // Keep counting length of subarray with max element
                maxLen = max(maxLen, currentLen); // Update the maximum length
            } else {
                currentLen = 0; // Reset length if current element is not max
            }
        }
        
        return maxLen;
    }
};
