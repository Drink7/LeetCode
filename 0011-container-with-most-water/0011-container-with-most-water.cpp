class Solution {
public:
    int maxArea(vector<int>& height) {
        // two pointer
        // move smaller height size
        // TC: O(n)
        // SC: O(1)
        int left = 0;
        int right = height.size() - 1;
        int result = 0;
        while (left < right) {
            int area = min(height[left], height[right]) * (right - left);
            result = max(result, area);

            if (height[left] > height[right]) {
                right--;
            } else {
                left++;
            }
        }
        return result;
    }
};