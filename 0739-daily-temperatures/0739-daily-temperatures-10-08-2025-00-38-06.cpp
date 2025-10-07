class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        // increasing monotonic stack
        // traverse from end
        // TC: O(n)
        // SC: O(n)
        vector<int> result;
        stack<int> stk;
        for (int i = temperatures.size() - 1; i >= 0; i--) {
            while (!stk.empty() && temperatures[stk.top()] <= temperatures[i]) {
                stk.pop();
            }

            if (stk.empty()) {
                result.push_back(0);
            } else {
                result.push_back(stk.top() - i);
            }
            stk.push(i);
        }

        reverse(result.begin(), result.end());
        return result;
    }
};