class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        // prefix sum
        // TC: O(n)
        // SC: O(n)
        int n = nums.size();
        vector<int> prefixSum(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            prefixSum[i] += prefixSum[i - 1] + nums[i - 1];
        }

        int index = 0;
        for (int i = 1; i <= n; i++) {
            if (prefixSum[i - 1] == (prefixSum[n] - prefixSum[i])) {
                return i - 1;
            }
        }
        return -1;
    }
};