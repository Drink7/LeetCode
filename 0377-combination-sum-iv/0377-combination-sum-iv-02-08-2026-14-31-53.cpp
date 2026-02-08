class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        // TC:O(n * target)
        // SC: O(target)
        /*
        if (target == 0) {
            return 1;
        }

        if (dict.count(target)) {
            return dict[target];
        }

        // climbing to the stairs - target needs ? steps
        int result = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (target - nums[i] >= 0) {
                result += combinationSum4(nums, target - nums[i]);
            }
        }

        dict[target] = result;

        return dict[target];
        */
        vector<unsigned long> dp(target + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= target; i++) {
            for (auto const& num : nums) {
                if (i - num >= 0) {
                    dp[i] += dp[i - num];
                }
            }
        }
        return dp[target];
    }
private:
    unordered_map<int, int> dict;
};