class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        // mono stack, for easy pop method, we insert 0 on the front and the tail
        // TC: O(n)
        // SC: O(n)
        heights.insert(heights.begin(), 0);
        heights.push_back(0);
        int n = heights.size();
        stack<int> stk;
        int area = 0;
        for (int i = 0; i < n; i++) {
            while (!stk.empty() && heights[stk.top()] > heights[i]) {
                int height = heights[stk.top()];
                stk.pop();

                area = max(area, height * (i - 1 - stk.top()));
            }
            stk.push(i);
        }
        return area;
    }
};