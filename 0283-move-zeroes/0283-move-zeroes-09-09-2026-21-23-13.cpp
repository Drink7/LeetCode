class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        // zeroIdx and idx
        // idx keep forwarding
        // if nums[idx] == 0 continue
        // else swap (nums[idx], nums[zeroIdx++])
        // TC: O(n)
        // SC: O(1)
        int zeroIdx = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] != 0) {
                swap(nums[i], nums[zeroIdx++]);
            }
        }
    }
};