class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // 2 arrays to store minProduct and maxProduct
        // TC: O(n)
        // SC: O(n)
        vector<int> maxDp(nums.size());
        vector<int> minDp(nums.size());
        maxDp[0] = nums[0];
        minDp[0] = nums[0];
        int result = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] >= 0) {
                maxDp[i] = max(maxDp[i - 1] * nums[i], nums[i]);
                minDp[i] = min(minDp[i - 1] * nums[i], nums[i]);
            } else {
                maxDp[i] = max(minDp[i - 1] * nums[i], nums[i]);
                minDp[i] = min(maxDp[i - 1] * nums[i], nums[i]);
            }
            result = max(result, maxDp[i]);
        }
        return result;
    }
};