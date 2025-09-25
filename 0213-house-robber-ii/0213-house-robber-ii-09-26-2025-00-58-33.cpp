class Solution {
public:
    int rob(vector<int>& nums) {
        // 1 & n are adjencent
        // rob 1 to n -1 or rob 2 to n
        // TC: O(n)
        // SC: O(n)
        if (nums.size() == 1) {
            return nums[0];
        }

        if (nums.size() == 2) {
            return max(nums[0], nums[1]);
        }

        int n = nums.size();
        vector<int> dp1(n - 1, 0); // 1 to n - 1
        vector<int> dp2(n - 1, 0); // 2 to n
        // dp1, 1 to n - 1
        dp1[0] = nums[0];
        dp1[1] = max(dp1[0], nums[1]);
        for (int i = 2; i < n - 1; i++) {
            dp1[i] = max(dp1[i - 2] + nums[i], dp1[i - 1]);
        }

        // dp2, 2 to n
        dp2[0] = nums[1];
        dp2[1] = max(dp2[0], nums[2]);
        for (int i = 3; i < n; i++) {
            dp2[(i - 1)] = max(dp2[(i - 1) - 2] + nums[i], dp2[(i - 1) - 1]);
        }

        return max(dp1.back(), dp2.back());
    }
};