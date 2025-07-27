class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // calculate from left to right
        // then caculate from right to left
        // TC: O(n)
        // SC: O(1)
        int n = nums.size();
        vector<int> result(n, 1);

        // from left to right
        int base = 1;
        for (int i = 0; i < n; i++) {
            if (i > 0) {
                base = base * nums[i - 1];
            }
            result[i] = base;
        }

        // from right to left
        base = 1;
        for (int i = n - 1; i >= 0; i--) {
            if (i < n - 1) {
                base = base * nums[i + 1];
            }
            result[i] = result[i] * base;
        }
        return result;
    }
};