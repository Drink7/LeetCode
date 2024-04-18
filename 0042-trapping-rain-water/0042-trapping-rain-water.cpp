class Solution {
public:
    int trap(vector<int>& height) {
        // TC: O(n)
        // SC: O(1)
        int result = 0;
        int n = height.size();
        int left = 0;
        int right = n - 1;
        int leftMax = height[left];
        int rightMax = height[right];
        while (left < right) {
            if (leftMax > rightMax) {
                right--;
                rightMax = max(rightMax, height[right]);
                result += rightMax - height[right];
            } else {
                left++;
                leftMax = max(leftMax, height[left]);
                result += leftMax - height[left];
            }
        }
        return result;
    }
};