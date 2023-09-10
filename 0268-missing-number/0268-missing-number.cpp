class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // XOR from 0 to n
        // TC: O(n)
        // SC: O(1)
        int n = nums.size();
        int result = n;
        for (int i = 0; i < n; i++) {
            result = result ^ nums[i] ^ i;
        }
        return result;
    }
};