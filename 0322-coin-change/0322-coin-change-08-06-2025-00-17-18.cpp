class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        //backtracking
        // sort coins with decreasing  -> nlogn
        // % biggest, then recursive
        vector<int> dp(amount + 1, INT_MIN);
        dp[0] = 0;
        
        return changeHelper(coins, dp, amount);
    }

    int changeHelper(vector<int>& coins, vector<int>& dp, int remain) {
        if (remain < 0) {
            return - 1;
        }

        if (dp[remain] != INT_MIN) {
            return dp[remain];
        }

        int changeCnt = INT_MAX;
        for (int i = 0; i < coins.size(); i++) {
            int tmp = changeHelper(coins, dp, remain - coins[i]);

            if (tmp >= 0) {
                changeCnt = min(changeCnt, tmp + 1);
            }
        }

        if (changeCnt == INT_MAX) {
            dp[remain] = -1;
        } else {
            dp[remain] = changeCnt;
        }
        return dp[remain];
    }
};