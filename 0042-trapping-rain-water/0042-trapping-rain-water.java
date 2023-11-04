class Solution {
    public int trap(int[] height) {
        int left = 0;
        int right = height.length - 1;
        int total = 0;
        int leftMax = height[left];
        int rightMax = height[right];
        while (left < right) {
            if (leftMax > rightMax) {
                right--;
                rightMax = Math.max(rightMax, height[right]);
                total += rightMax - height[right];
            } else {
                left++;
                leftMax = Math.max(leftMax, height[left]);
                total += leftMax - height[left];
            }
        }
        return total;
    }
}