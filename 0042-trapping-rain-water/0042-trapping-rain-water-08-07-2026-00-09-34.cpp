class Solution {
public:
    int trap(vector<int>& height) {
        // left, right, leftMax, rightMax
        // move the smaller one (E.g., left)
        // if (height[left] >= height[leftMax], can calculate area)
        // waterHeight will be min(height[leftMax], height[left])
        // water area will be waterHeight - height[i], i is in (leftMax, left)
        // update leftMax = left, then continue
        // TC: O(n)
        // SC: O(1)
        int n = height.size();
        int left = 0, leftMax = height[left], right = n - 1, rightMax = height[right];
        int result = 0;
        while (left < right) {
            if (leftMax < rightMax) {
                // move left
                left++;
                if (left < right) {
                    leftMax = max(height[left], leftMax);
                    result += leftMax - height[left];
                }
            } else {
                // move right
                right--;
                if (left < right) {
                    rightMax = max(height[right], rightMax);
                    result += rightMax - height[right];
                }
            }
        }
        return result;
    }
};