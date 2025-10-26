class Solution {
public:
    int trap(vector<int>& height) {
        // leftMost arr
        // rightMost arr
        // TC: O(n)
        // SC: O(n)
        int n = height.size();
        vector<int> leftMost(n, 0), rightMost(n, 0);
        int result = 0;
        leftMost[0] = height[0];
        rightMost[n - 1] = height[n - 1];
        for (int i = 1; i < n; i++) {
            leftMost[i] = max(height[i], leftMost[i - 1]);
            rightMost[n - 1 - i] = max(height[n - 1 - i], rightMost[n - i]);
        }

        for (int i = 0; i < n; i++) {
            result += min(leftMost[i], rightMost[i]) - height[i];
        }
 
        return result;
    }
};