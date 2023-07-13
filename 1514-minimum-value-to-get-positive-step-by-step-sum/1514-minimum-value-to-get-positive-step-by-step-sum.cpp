class Solution {
public:
    int minStartValue(vector<int>& nums) {
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
    }
};