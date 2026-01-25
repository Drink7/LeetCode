class Solution {
public:
    int rob(vector<int>& nums) {
        // TC: O(n)
        // SC: O(n)
        // #1 rob first can not rob last, rob last can not rob first
        // #2 divide to two part-> rob 1st ... nth, rob 0th ... n - 1th
        // fetch their max value
        /*
        int n = nums.size();
        if (n == 1) {
            return nums[0];
        }

        // rob 0th ... n - 1th
        dp.assign(n, -1);
        dp[0] = nums[0];
        int leftHalf = dfs(0, n - 2, nums);

        dp.assign(n, -1);
        dp[0] = nums[1];
        int rightHalf = dfs(1, n - 1, nums);
        return max(leftHalf, rightHalf);
        */
        int n = nums.size();
        if (n == 1) return nums[0];
        return max(dfs(0, n - 2, nums), dfs(1, n - 1, nums));
    }

    int dfs(int start, int end, vector<int>& nums) {
        int n = end - start + 1;
        vector<int> dp(n + 1, -1);
        dp[0] = 0;
        dp[1] = nums[start];
        int index = start + 1;
        for (int i = 2; i <= n; i++, index++) {
            dp[i] = max(dp[i - 2] + nums[index], dp[i - 1]);
        }
        return dp[n];

        // if (i < start) {
        //     return 0;
        // }

        // if (dp[i] != -1) {
        //     return dp[i];
        // }

        // int result = max(dfs(start, i - 2, nums) + nums[i], dfs(start, i - 1, nums));
        // dp[i] = result;
        // return dp[i];
    }

// private:
//     vector<int> dp;
};