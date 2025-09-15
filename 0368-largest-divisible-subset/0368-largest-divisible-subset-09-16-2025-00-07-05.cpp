class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return {};

        sort(nums.begin(), nums.end());

        vector<int> dp(n, 1);     // dp[i] = 最大可整除子集長度 ending with nums[i]
        vector<int> prev(n, -1);  // prev[i] = 前一個元素的 index
        int maxLen = 1;
        int maxIdx = 0;

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] % nums[j] == 0 && dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    prev[i] = j;
                }
            }
            if (dp[i] > maxLen) {
                maxLen = dp[i];
                maxIdx = i;
            }
        }

        // 回溯構造答案
        vector<int> res;
        int idx = maxIdx;
        while (idx != -1) {
            res.push_back(nums[idx]);
            idx = prev[idx];
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
