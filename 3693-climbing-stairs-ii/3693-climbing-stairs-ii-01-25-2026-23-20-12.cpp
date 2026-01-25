class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        // TC: O(n)
        // SC: O(n)
        // #1 insert 0 to the front of costs
        // #2 recursive function: 
        // #3 Note, dfs(n) = cost[n] + min({dfs(n - 1) + (n - 1)^2, dfs(n - 2) + (n - 2)^2, dfs(n - 3) + (n - 3)^2});
        dp.resize(n + 1, -1);
        dp[0] = 0;
        return dfs(n, costs);
    }

    int dfs(int i, vector<int>& costs) {
        if (i <= 0) {
            return 0;
        }

        if (dp[i] != -1) {
            return dp[i];
        }

        // (i + 1 - i)^2 ==> 1
        // (i + 2 - i)^2 ==> 4
        // (i + 3 - i)^2 ==> 9
        
        int result = 2e9;
        for (int j = max(i - 3, 0); j < i; j++) {
            result = min(result, dfs(j, costs) + (i - j) * (i - j));
        }

        /*
        result = min(result, dfs(i - 1, costs) + 1);
        if (i >= 2) {
            result = min(result, dfs(i - 2, costs) + 4);
        }
        
        if (i >= 3) {
            result = min(result, dfs(i - 3, costs) + 9);
        }
        */

        //result = min({res1, res2, res3});
        result += costs[i - 1];
        dp[i] = result;
        return dp[i];
    }

private:
    vector<int> dp;
};