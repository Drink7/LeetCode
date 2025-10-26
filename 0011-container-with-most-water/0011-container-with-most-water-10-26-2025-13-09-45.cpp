class Solution {
public:
    int maxArea(vector<int>& height) {
        // two pointer with greedy
        // left, right, calculate area
        // move the smaller size and hope we can get max area
        // TC: O(n)
        // SC: O(1)
        int left = 0;
        int right = height.size() - 1;
        int result = 0;
        while (left < right) {
            result = max(result, min(height[left], height[right]) * (right - left));
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }
        return result;
    }
};