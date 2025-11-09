class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        // sum < target or -sum > target -> impossible
        // recursion
        // amount is target
        // dp[i][j] represent the way form to j from prev i number
        // dp[i][j] += dp[i][j - num[i]]
        // dp[i][j] += dp[i][j + num[i]]
        // j - nums[i], j + num[i] might oversize
        // use unordered_map to store <sum, ways> here 
        unordered_map<int, int> dict;
        dict[0] = 1;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            unordered_map<int, int> sumDict;
            for (auto& p : dict) {
                sumDict[p.first + nums[i]] += p.second;
                sumDict[p.first - nums[i]] += p.second;
            }

            // assign sumDict to dict
            dict = sumDict;
        }
        return dict[target];

        /*
        int result = 0;
        int sum = 0;
        dfs(nums, target, 0, sum, result);
        return result;
        */
    }

    /*
    void dfs(vector<int>& nums, int target, int startId, int sum, int& result) {
        if (startId == nums.size()) {
            if (target == sum) result++;
            return;
        }

        if (startId == nums.size()) {
            return;
        }

        for (int i = startId; i < nums.size(); i++) {
            // +
            dfs(nums, target, i + 1, sum + nums[i], result);

            // -
            dfs(nums, target, i + 1, sum - nums[i], result);
        }
    }
    */
};