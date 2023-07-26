class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // Use XOR
        // TC: O(n)
        // SC: O(1)
        int n = nums.size();
        int result = nums[0];
        for (int i = 1; i < n; i++) {
            result ^= nums[i];
        }
        return result;
    }
};