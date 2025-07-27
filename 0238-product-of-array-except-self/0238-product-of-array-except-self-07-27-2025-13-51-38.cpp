class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // n^2 must TLE
        // 1, 2, 3, 4
        // right => 24, 12, 4, 1
        // left => 1, 1, 2, 6
        // TC: O(n)
        // SC: O(n)
        int n = nums.size();
        vector<int> right(n, 1);
        vector<int> left(n, 1);
        vector<int> result(n);
        // calculate right
        for (int i = n - 2; i >= 0; i--) {
            right[i] = right[i + 1] * nums[i + 1];
        }

        // calculate left
        for (int i = 1; i < n; i++) {
            left[i] = left[i - 1] * nums[i - 1];
        }

        // calculate result
        for (int i = 0; i < n; i++) {
            result[i] = right[i] * left[i];
        }
        return result;

    }
};