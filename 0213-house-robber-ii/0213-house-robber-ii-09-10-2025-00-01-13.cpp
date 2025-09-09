class Solution {
public:
    int rob(vector<int>& nums) {
        // compare nums[0... n - 2] and [1 ... n - 1]
        // find both maxiumu
        // TC: O(n)
        // SC: O(n)
        int n = nums.size();
        vector<int> dp1(n - 1, 0);
        vector<int> dp2(n - 1, 0);
        if (n == 1) {
            return nums[0];
        }

        if (n == 2) {
            return max(nums[0], nums[1]);
        }

        dp1[0] = nums[0];
        dp2[0] = nums[1];
        dp1[1] = max(dp1[0], nums[1]);
        dp2[1] = max(dp2[0], nums[2]);
        // traverse 0 ~ n - 2
        for (int i = 2; i < n - 1; i++) {
            dp1[i] = max(dp1[i - 2] + nums[i], dp1[i - 1]);
        }

        // traverse 1 ~ n - 1
        for (int i = 2; i < n - 1; i++) {
            dp2[i] = max(dp2[i - 2] + nums[i + 1], dp2[i - 1]);
        }
        return max(dp1.back(), dp2.back());
    }
};