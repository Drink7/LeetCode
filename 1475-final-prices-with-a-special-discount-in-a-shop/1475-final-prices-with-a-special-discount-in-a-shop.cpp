class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        /*
        // Brute force
        // TC: O(n^2)
        // SC: O(1)
        vector<int> result;
        for (int i = 0; i < prices.size(); i++) {
            int discount = 0;
            for (int j = i; j < prices.size(); j++) {
                if (j > i && prices[j] <= prices[i]) {
                    discount = prices[j];
                    break;
                }
            }
            result.push_back(prices[i] - discount);
        }
        return result;
        */
        // monotonic stack
        // TC: O(n)
        // SC: O(n)
        // traverse from back
        vector<int> result;
        stack<int> monoStack;
        int n = prices.size();

        for (int i = n - 1; i >= 0; i--) {
            if (monoStack.size() > 0) {
                // check if we need to update discount value
                while (monoStack.size() > 0 && prices[monoStack.top()] > prices[i]) {
                    monoStack.pop();
                }

                int stackTopVal = monoStack.size() > 0 ? prices[monoStack.top()] : 0;
                if (prices[i] < stackTopVal) {
                    result.push_back(prices[i]);
                } else {
                    result.push_back(prices[i] - stackTopVal);
                }                
            } else {
                result.push_back(prices[i]);
            }
            monoStack.push(i);
        }
        reverse(result.begin(), result.end());
        return result;
    }
};