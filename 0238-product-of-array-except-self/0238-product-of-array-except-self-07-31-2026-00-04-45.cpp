class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // find left part TC:(n)
        // find right part TC:(n)
        // multiply TC:(n)
        // TC: O(n)
        // SC: O(n)
        int n = nums.size();
        vector<int> result(n);
        vector<int> left(n, 1);
        vector<int> right(n, 1);

        // left
        for (int i = 1; i < n; i++) {
            left[i] = nums[i - 1] * left[i - 1];
        }

        // right
        for (int i = n - 2; i >= 0; i--) {
            right[i] = nums[i + 1] * right[i + 1];
        }

        for (int i = 0; i < n; i++) {
            result[i] = left[i] * right[i];
        }
        return result;
    }
};