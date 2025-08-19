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
        int left = -1;
        int right = -1;
        long long result = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                if (left == -1) {
                    left = i;
                }
            } else {
                // check subarray
                if (left != -1) {
                    right = i - 1;

                    // start calculate subarray
                    int cnt = right - left + 1;
                    result += (long long)(cnt + 1) * cnt / 2;

                    left = -1;
                    right = -1;
                }
            }
        }

        if (left != -1) {
            right = n - 1;
            int cnt = right - left + 1;
            result += (long long)(cnt + 1) * cnt / 2;
        }
        return result;
    }
};