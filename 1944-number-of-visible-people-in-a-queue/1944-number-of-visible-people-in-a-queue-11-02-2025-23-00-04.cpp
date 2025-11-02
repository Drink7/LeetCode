class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        // daily temperature
        // monotonic stack, find the next greater element
        // stack, store the value index which the value is decreasing
        // when the incoming value is increase, check the stack until the stk top is bigger than the incoming value
        // TC: O(n), n is for heights size
        // SC: O(n)
        stack<int> stk;
        int n = heights.size();
        vector<int> result(n, 0);
        for (int i = 0; i < n; i++) {
            while (!stk.empty() && heights[stk.top()] < heights[i]) {
                result[stk.top()]++;
                stk.pop();
            }
            if (!stk.empty()) {
                result[stk.top()]++;
            }
            stk.push(i);
        }
        return result;
    }
};