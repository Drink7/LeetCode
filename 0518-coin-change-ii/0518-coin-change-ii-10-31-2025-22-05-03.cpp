class Solution {
public:
    int change(int amount, vector<int>& coins) {
        // top-down
        return dfs(amount, coins, 0);
    }

    int dfs(int amount, vector<int>& coins, int start) {
        if (amount < 0 || start >= coins.size()) {
            return 0;
        }

        if (amount == 0) {
            return 1;
        }

        auto key = make_pair(amount, start);
        if (dp.count(key) > 0) {
            return dp[key];
        }

        int cnt = 0;
        cnt += dfs(amount - coins[start], coins, start);
        cnt += dfs(amount, coins, start + 1);
        dp[{amount, start}] = cnt;
        return dp[{amount, start}];
    }
private:
    map<pair<int, int>, int> dp; // use amount, start with cnt
};