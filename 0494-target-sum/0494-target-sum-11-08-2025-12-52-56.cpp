class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        // sum < target or -sum > target -> impossible
        // recursion
        int result = 0;
        int sum = 0;
        dfs(nums, target, 0, sum, result);
        return result;
    }

    void dfs(vector<int>& nums, int target, int startId, int sum, int& result) {
        if (startId == nums.size()) {
            if (target == sum) result++;
            return;
        }

        // +
        dfs(nums, target, startId + 1, sum + nums[startId], result);

        // -
        dfs(nums, target, startId + 1, sum - nums[startId], result);
    
    }
};