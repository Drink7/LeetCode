class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        // find [left, right] min height
        // min height * (right - left + 1)
        // max
        // TC: O(n)
        // SC: O(n)
        heights.push_back(0);
        int n = heights.size();
        stack<int> indexStack;
        int result = 0;
        for (int i = 0; i < n; i++) {
            while (indexStack.size() > 0 && heights[indexStack.top()] > heights[i]) {
                int topValue = heights[indexStack.top()];
                indexStack.pop();

                int widthId = indexStack.empty() ? -1 : indexStack.top();
                result = max(result, topValue * (i - widthId - 1));
            }
            indexStack.push(i);
        }
        return result;
    }
};