class Solution {
public:
    int maxArea(vector<int>& height) {
        // move the shortest height every time to find the most water
        // Two pointer
        // TC: O(n)
        // SC: O(1)
        int left = 0;
        int right = height.size() - 1;
        int result = 0;
        while (left < right) {
            int capacity = min(height[left], height[right]) * (right - left);
            result = max(result, capacity);

            if (height[left] >= height[right]) {
                right--;
            } else {
                left++;
            }
        }
        return result;
    }
};