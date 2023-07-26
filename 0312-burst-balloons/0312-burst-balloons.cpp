class Solution {
    /*
public:
    int maxCoins(vector<int>& nums) {
        // Backtracking (TLE)
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        dfs(nums, 0, 0);
        return result;
    }

    void dfs(vector<int>& nums, int used, int cur) {
        if (used == nums.size() - 2) {
            result = max(result, cur);
            return;
        }

        for (int i = 1; i < nums.size() - 1; i++) {
            if (nums[i] == -1) {
                continue;
            }
            // calculate sum
            // looking backward
            int prev = i - 1;
            while (nums[prev] == -1) {
                prev--;
            }
            // looking forward
            int next = i + 1;
            while (nums[next] == -1) {
                next++;
            }
            int sum = nums[prev] * nums[i] * nums[next];
            
            // burst balloons
            int tmp = nums[i];
            nums[i] = -1;
            dfs(nums, used + 1, cur + sum);
            nums[i] = tmp;
        }
    }
private:
    int result = 0;
    */

public:
    int maxCoins(vector<int>& nums) {
        // Elegant top down dp with Memo
        // Instead of which one to burst first, need to think which one to burst last
        // Time: O(n^3) -> O(n^2) states, for each states, determining max coins is O(n)
        // Space: O(n^2) -> O(n^2) to store all states
        
        // insert first one and last one
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        int n = nums.size();

        vector<vector<int>> dp(n, vector<int>(n, -1));
        // index 0 and n - 1 is fake ballon
        return dfs(nums, dp, 1, n - 2);
    }

    int dfs(vector<int>& nums, vector<vector<int>>& dp, int left, int right) {
        if (left > right) {
            return 0;
        }

        if (dp[left][right] > -1) {
            return dp[left][right];
        }

        int result = 0;
        for (int i = left; i <= right; i++) {
            int current = nums[left - 1] * nums[i] * nums[right + 1];
            int remain = dfs(nums, dp, left, i - 1) + dfs(nums, dp, i + 1, right);
            result = max(result, current + remain);
        }
        dp[left][right] = result;
        return dp[left][right];
    }
};