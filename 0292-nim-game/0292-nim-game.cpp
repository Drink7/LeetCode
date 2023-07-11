class Solution {
public:
    bool canWinNim(int n) {
        /*
        // we can remove 1, 2, 3 stones to win
        // Dynamic programming
        // TC: O(n)
        // SC: O(n)
        // TLE
        if (n < 4) {
            return true;
        }

        vector<bool> dp(n + 1, false);
        dp[0] = true;
        dp[1] = true;
        dp[2] = true;
        dp[3] = true;
        bool isWin = false;
        for (int i = 4; i <= n; i++) {
            if (!dp[i - 1] || !dp[i - 2] || !dp[i - 3]) {
                dp[i] = true;
            }
        }
        return dp[i];
        */

        // Pure Math
        // TC: O(1)
        // SC: O(1)
        return n % 4;        
    }
private:
};