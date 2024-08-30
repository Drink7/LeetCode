class Solution {
public:
    int maxArea(vector<int>& height) {
        // two pointer
        // every time move the smaller one
        // TC: O(n)
        // SC: O(1)
        int left = 0;
        int right = height.size() - 1;
        int result = 0;
        while (left < right) {
            int h = min(height[left], height[right]);
            int w = right - left;
            int area = w * h;
            if (result < area) {
                result = area;
            }

            if (height[right] > height[left]) {
                left++;
            } else {
                right--;
            }
        }
        return result;
    }
};