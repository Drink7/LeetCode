class Solution {
public:
    int rob(vector<int>& nums) {
        // rob the first house vs. rob the last house
        // TC: O(n)
        // SC: O(n)
        int n = nums.size();

        if (n == 1) {
            return nums[0];
        }

        vector<int> dp1(n - 1);
        vector<int> dp2(n - 1);

        // rob the first house
        dp1[0] = nums[0];
        for (int i = 1; i < n - 1; i++) {
            if (i == 1) {
                dp1[i] = max(dp1[i - 1], nums[i]);
            } else {
                dp1[i] = max(dp1[i - 1], dp1[i - 2] + nums[i]);
            }
        }

        // rob the last house
        dp2[0] = nums[1];
        for (int i = 1; i < n - 1; i++) {
            if (i == 1) {
                dp2[i] = max(dp2[i - 1], nums[i + 1]);
            } else {
                dp2[i] = max(dp2[i - 1], dp2[i - 2] + nums[i + 1]);
            }
        }
        return max(dp1.back(), dp2.back());
    }
};