class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        // traverse back and maintain a monotonic decreasing stack
        // we store index for the ans
        // TC: O(n)
        // SC: O(n)
        int n = temperatures.size();
        vector<int> result(n, 0);
        stack<int> monoStack;
        for (int i = n - 1; i >= 0; i--) {
            while (monoStack.size() > 0 && temperatures[i] > temperatures[monoStack.top()]) {
                monoStack.pop();
            }

            if (monoStack.size() > 0) {
                result[i] = monoStack.top() - i;
            } else {
                result[i] = 0;
            }
            monoStack.push(i);
        }
        return result;
    }
};