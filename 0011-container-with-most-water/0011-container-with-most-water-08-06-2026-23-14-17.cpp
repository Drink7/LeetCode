class Solution {
public:
    int maxArea(vector<int>& height) {
        // two pointer, move the lower one to find higher height
        // TC: O(n)
        // SC: O(1)
        int left = 0, right = height.size() - 1;
        int result = 0;
        while (left < right) {
            int width = right - left;
            int area = width * min(height[left], height[right]);
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