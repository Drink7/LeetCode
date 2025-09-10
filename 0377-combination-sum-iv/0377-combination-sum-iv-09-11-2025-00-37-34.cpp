class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        // backtrack -> TLE
        // backpack problem?
        // dp[target]
        // dp[target]
        return dfs(nums, target);
    }

    int dfs(vector<int>& nums, int target) {
        if (target < 0) {
            return 0;
        }

        if (target == 0) {
            return 1;
        }

        if (dp.count(target) > 0) {
            return dp[target];
        }

        for (int i = 0; i < nums.size(); i++) {
            dp[target] += dfs(nums, target - nums[i]);
        }

        return dp[target];
    }
private:
    unordered_map<int, int> dp;
};