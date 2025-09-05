class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        // prefix sum of prices & profit
        // calculate with sliding window
        // inside sliding window : use prices prefix sum to calulcate
        // outside sliding window (left/right parts) : use profit prefix sum to calculate
        // TC: O(n)
        // SC: O(n)
        vector<long long> profitSum;
        vector<long long> priceSum;
        int n = prices.size();
        for (int i = 0; i < n; i++) {
            priceSum.push_back(prices[i]);
            profitSum.push_back(prices[i] * strategy[i]);
        }

        // prefix sum
        for (int i = 1; i < n; i++) {
            priceSum[i] += priceSum[i - 1];
            profitSum[i] += profitSum[i - 1];
        }

        // sliding window
        int half = k / 2;
        int left = 0, right = k - 1;
        long long result = profitSum[n - 1];
        while (right < n) {
            long long leftPart = (left > 0) ? profitSum[left - 1] : 0;
            long long rightPart = profitSum[n - 1] - profitSum[right];
            long long strategyPart = priceSum[right] - priceSum[right - half];
            result = max(result, leftPart + rightPart + strategyPart);
            left++;
            right++;
        }
        return result;
    }
};