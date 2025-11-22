class Solution {
public:
    vector<int> countBits(int n) {
        /*
        vector<int> result;
        for (int i = 0; i <= n; i++) {
            result.push_back(countBit(i));
        }
        return result;
        */
        vector<int> dp(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            dp[i] = dp[i >> 1] + (i & 1);
        }
        return dp;
    }

    int countBit(int n) {
        int result = 0;
        while (n) {
            result++;
            n = n & (n - 1);
        }
        return result;
    }
};