class Solution {
public:
    int trap(vector<int>& height) {
        /*
        // TC: O(n)
        // SC: O(1)
        int left = 0;
        int right = height.size() - 1;
        int leftMost = height[left];
        int rightMost = height[right];
        int result = 0;
        while (left < right) {
            if (height[left] < height[right]) {
                left++;
                if (left < right) {
                    // trap left
                    leftMost = max(leftMost, height[left]);
                    result += leftMost - height[left];
                }
            } else {
                right--;
                if (left < right) {
                    // trap right
                    rightMost = max(rightMost, height[right]);
                    result += rightMost - height[right];
                }
            }
        }
        return result;
        */
        // Monotonic Stack
        int n = height.size();
        stack<int> stk;
        int result = 0;
        for (int i = 0; i < n; i++) {
            while (!stk.empty() && height[stk.top()] <= height[i]) {
                int buttom = height[stk.top()];
                stk.pop();

                if (stk.empty()) {
                    break;
                }
                int dh = min(height[stk.top()], height[i]) - buttom;
                int width = i - stk.top() - 1;
                result += dh * width;
            }
            stk.push(i);
        }
        return result;
    }
};