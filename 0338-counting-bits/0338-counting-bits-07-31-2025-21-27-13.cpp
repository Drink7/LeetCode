class Solution {
public:
    vector<int> countBits(int n) {
        /*
        // TC: O(nlogn)
        // SC: O(1)
        vector<int> result(n + 1, 0);
        for (int i = 0; i < n + 1; i++) {
            result[i] = cntNum(i);
        }
        return result;
        */
        // Single pass
        // TC: O(n)
        // SC: O(n)
        vector<int> dp(n + 1, 0);
        for (int i = 0; i <= n; i++) {
            dp[i] = (i & 1) + dp[i >> 1];
        }
        return dp;
    }

    int cntNum(int n) {
        int result = 0;
        while (n) {
            n = n & (n - 1);
            result++;
        }
        return result;
    }
};