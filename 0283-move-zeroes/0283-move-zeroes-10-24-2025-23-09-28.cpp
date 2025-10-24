class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        // use an index to represent current not zero insert index
        // if zero, keep traverse
        // if not zero, swap idx and i nums, then idx++
        // TC: O(n)
        // SC: O(1)
        int idx = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                swap(nums[idx++], nums[i]);
            }
        }
    }
};