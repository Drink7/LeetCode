class Solution {
public:
    int minStartValue(vector<int>& nums) {
        /*
        // Prefix sum to get the minimum value
        // TC: O(n)
        // SC: O(n)
        int n = nums.size();
        vector<int> prefixSum(nums.begin(), nums.end());
        int minVal = nums[0];
        for (int i = 1; i < n; i++) {
            prefixSum[i] += prefixSum[i - 1];
            minVal = min(minVal, prefixSum[i]);
        }
        return (minVal <= 0) ? 1 - minVal : 1;
        */

        // Prefix sum to get the minimum value
        // Space optimization
        // TC: O(n)
        // SC: O(1)
        int n = nums.size();
        int prefixSum = 0;
        int minVal = 0;
        for (int i = 0; i < n; i++) {
            prefixSum += nums[i];
            minVal = min(minVal, prefixSum);
        }
        return 1 - minVal;
    }
};