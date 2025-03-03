/*
You are given a 0-indexed integer array nums and an integer pivot. Rearrange nums such that the following conditions are satisfied:

Every element less than pivot appears before every element greater than pivot.
Every element equal to pivot appears in between the elements less than and greater than pivot.
The relative order of the elements less than pivot and the elements greater than pivot is maintained.
More formally, consider every pi, pj where pi is the new position of the ith element and pj is the new position of the jth element. If i < j and both elements are smaller (or larger) than pivot, then pi < pj.
Return nums after the rearrangement.

This solution uses two pointer approach.
Can't use the quick sort method as it can change the relative ordering of elements
*/


class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> ans(nums.size());
        int lessI = 0;
        int greaterI = nums.size() - 1;
        for (int i = 0, j = nums.size() - 1; i < nums.size(); i++, j--) {
            if (nums[i] < pivot) {
                ans[lessI] = nums[i];
                lessI++;
            }
            if (nums[j] > pivot) {
                ans[greaterI] = nums[j];
                greaterI--;
            }
        }
        while (lessI <= greaterI) {
            ans[lessI] = pivot;
            lessI++;
        }
        return ans;
    }
};
