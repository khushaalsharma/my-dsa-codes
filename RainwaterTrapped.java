/*
KEY IDEA:
waterUnit += min(max of left side, max of right side) - height[i]

*/


class Solution {
    public int trap(int[] height) {
        int size = height.length;
        int start = 0, end = size - 1, leftMax = 0, rightMax = 0;

        int trappedWater = 0;

        while(start < end){
            leftMax = Math.max(leftMax, height[start]);
            rightMax = Math.max(rightMax, height[end]);

            if(leftMax < rightMax){
                trappedWater += (leftMax - height[start]);
                start++;
            }
            else{
                trappedWater += (rightMax - height[end]);
                end--;
            }
        }

        return trappedWater;
    }
}
