class Solution {
public:
    int trap(vector<int>& height) {
        // two pointer
        // TC: O(n)
        // SC: O(1)
        int left = 0 ;
        int right = height.size() - 1;
        int leftMax = height[left];
        int rightMax = height[right];
        int result = 0;
        while (left < right) {
            if (leftMax < rightMax) {
                left++;
                if (left < right) {
                    leftMax = max(leftMax, height[left]);
                    result += leftMax - height[left];
                }
            } else {
                right--;
                if (left < right) {
                    rightMax = max(rightMax, height[right]);
                    result += rightMax - height[right];
                }
            }
        }
        return result;
    }
};