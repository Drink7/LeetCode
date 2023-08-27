class Solution {
public:
    int maxArea(vector<int>& height) {
        // two pointer and move the smaller height side to find max volumn
        // TC: O(n)
        // SC: O(1)
        int result = 0;
        int left = 0;
        int right = height.size() - 1;
        while (left < right) {
            int tmp = min(height[left], height[right]) * (right - left);
            result = max(result, tmp);
            if (height[left] > height[right]) {
                right--;
            } else {
                left++;
            }
        }
        return result;
    }
};