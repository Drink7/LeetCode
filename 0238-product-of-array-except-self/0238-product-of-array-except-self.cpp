class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // TC: O(n)
        // SC: O(1)
        int n = nums.size();
        vector<int> result(n, 1);

        for (int i = 1; i < n; i++) {
            result[i] = result[i - 1] * nums[i - 1];
        }

        int tmp = 1;
        for (int i = n - 2; i >=0; i--) {
            tmp = tmp * nums[i + 1];
            result[i] = result[i] * tmp;
        }

        return result; 
    }
};