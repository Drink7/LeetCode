class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        // single pass way
        // TC: O(n)
        // SC: O(1)
        int n = nums.size();
        int maxK = 0;
        int prev = 0;
        int cur = 1;
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] < nums[i + 1]) {
                cur++;
            } else {
                maxK = max({maxK, cur / 2, min(prev, cur)});
                prev = cur;
                cur = 1;
            }
        }
        maxK = max({maxK, cur / 2, min(prev, cur)});
        return maxK;
    }
};