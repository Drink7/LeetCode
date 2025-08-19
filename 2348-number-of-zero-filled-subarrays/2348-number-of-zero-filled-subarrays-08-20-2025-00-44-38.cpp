class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        // subarray -> sliding window, prefix sum
        // sliding window
        // index keep going until first zero
        // label left
        // index keep going until non-zero
        // label right
        // calculate the subarray
        int n = nums.size();
        int cnt = 0;
        long long result = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                cnt++;
            } else {
                result += (long long)(cnt + 1) * cnt / 2;
                cnt = 0;
            }
        }

        // handle last zeros
        result += (long long)(cnt + 1) * cnt / 2;
        return result;
    }
};