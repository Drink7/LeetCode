class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        // mono stack
        // store index
        // TC: O(n)
        // SC: O(n)
        int n = temperatures.size();
        stack<int> stk;
        vector<int> result(n, 0);
        for (int i = 0; i < n; i++) {
            while(!stk.empty() && temperatures[i] > temperatures[stk.top()]) {
                result[stk.top()] = i - stk.top();
                stk.pop();
            }
            stk.push(i);
        }
        return result;
    }
};