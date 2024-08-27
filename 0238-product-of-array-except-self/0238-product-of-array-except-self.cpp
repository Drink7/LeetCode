class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // TC: O(n)
        // SC: O(n)
        int n = nums.size();
        vector<int> right(n, 1);
        vector<int> left(n, 1);
        vector<int> result(n, 1);

        // right
        for (int i = 1; i < n; i++) {
            right[i] = right[i - 1] * nums[i - 1];
        }

        // left
        for (int i = n - 2; i >=0; i--) {
            left[i] = left[i + 1] * nums[i + 1];
        }

        // result
        for (int i = 0; i < n; i++) {
            result[i] = left[i] * right[i];
        }
        return result; 
    }
};