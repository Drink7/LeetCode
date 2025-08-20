class Solution {
    /*
    // Backtracking
    public:
        int findTargetSumWays(vector<int>& nums, int target) {
            // backtracking
            // TC: O(2^n)
            // SC: O(n)
            dfs(nums, target, 0, 0);
            return counter;
        }

        void dfs(vector<int>& nums, int target, int index, int total) {
            if (index == nums.size()) {
                if (total == target) {
                    counter++;
                }
                return;
            }

            dfs(nums, target, index + 1, total + nums[index]);
            dfs(nums, target, index + 1, total - nums[index]);
        }
    private:
        int counter = 0;
    */

    /*
    // DFS + MEMO
    public:
        int findTargetSumWays(vector<int>& nums, int target) {
            // top down (index, total) -> dfs with memorization
            // TC: O(n * t), t is total count
            // SC: O(n * t)
            return dfs(nums, target, 0, 0);
        }

        int dfs(vector<int>& nums, int target, int index, int total) {
            if (index == nums.size()) {
                return (target == total) ? 1 : 0;
            }

            if (dict.count({index, total})) {
                return dict[{index, total}];
            }

            dict[{index, total}] = dfs(nums, target, index + 1, total + nums[index]) +
                                    dfs(nums, target, index + 1, total - nums[index]);

            return dict[{index, total}];
        }
    private:
        map<pair<int, int>, int> dict;
    */


public:
    int findTargetSumWays(vector<int>& nums, int target) {
        // dynamic programming
        // TC: O(n * t), t is total count
        // SC: O(n * t)
        int n = nums.size();
        vector<unordered_map<int, int>> dp(n + 1); // {index, sum}, count
        dp[0][0] = 1;
        for (int i = 0; i < n; i++) {
            for (auto const& p : dp[i]) {
                int sum = p.first;
                int cnt = p.second;
                dp[i + 1][sum + nums[i]] += cnt;
                dp[i + 1][sum - nums[i]] += cnt;
            }
        }
        return dp[n][target];
    }
};