//Leetcode 321
//use of monotonic stack 
//monotonic stack: contents are either in increasing or decreasing order
//here since max number is required we will use a monotonic stack for decreasing order


class Solution {
    public int[] maxNumber(int[] nums1, int[] nums2, int k) {
        int n1 = nums1.length, n2 = nums2.length;
        int[] res = new int[k];
        
        for (int i = Math.max(0, k - n2); i <= Math.min(k, n1); i++) {
            int[] part1 = maxSubsequence(nums1, i);
            int[] part2 = maxSubsequence(nums2, k - i);
            int[] candidate = merge(part1, part2);
            if (greater(candidate, 0, res, 0))
                res = candidate;
        }
        return res;
    }

    private int[] maxSubsequence(int[] nums, int k) {
        int[] stack = new int[k];
        int top = -1, remain = nums.length;
        for (int num : nums) {
            while (top >= 0 && stack[top] < num && remain > k - top - 1) { // if the current number is larger than top of stack remove it
                top--;
            }
            if (top + 1 < k) stack[++top] = num; //add to stack if dec order is maintained
            remain--;
        }
        return stack;
    }

    private int[] merge(int[] nums1, int[] nums2) {
        int x = nums1.length, y = nums2.length;
        int[] merged = new int[x + y];
        int i = 0, j = 0, idx = 0;
        while (i < x || j < y)
            merged[idx++] = greater(nums1, i, nums2, j) ? nums1[i++] : nums2[j++];
        return merged;
    }

    private boolean greater(int[] nums1, int i, int[] nums2, int j) {
        while (i < nums1.length && j < nums2.length && nums1[i] == nums2[j]) {
            i++;
            j++;
        }
        return j == nums2.length || (i < nums1.length && nums1[i] > nums2[j]);
    }
}
