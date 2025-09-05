class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        // calculate base prefix sum
        // sort
        // sum from index left - 1 to right - 1
        int modulo = 1000000007;
        vector<int> prefixSum(nums.begin(), nums.end());
        for (int i = 1; i < n; i++) {
            prefixSum[i] += prefixSum[i - 1] % modulo;
        }

        // calculate all subarray
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                prefixSum.push_back(prefixSum[j] - prefixSum[i]);
            }
        }

        sort(prefixSum.begin(), prefixSum.end());

        int result = 0;
        for (int i = left - 1; i <= right - 1; i++) {
            result = (result + prefixSum[i]) % modulo;
        }
        return result;
    }
};