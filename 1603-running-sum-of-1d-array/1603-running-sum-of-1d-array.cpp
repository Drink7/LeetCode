class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        // Prefix Sum
        // TC: O(n)
        // SC: O(n)
        int n = nums.size();
        vector<int> result(n, 0);
        result[0] = nums[0];
        for (int i = 1; i < n; i++) {
            result[i] += result[i - 1] + nums[i]; 
        }
        return result;
    }
};