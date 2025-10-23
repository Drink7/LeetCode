class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // idx keep insert unique index
        // i keep going and check i & i - 1
        // if nums[i] != nums[i - 1], assign nums[idx] to nums[i]
        // TC: O(n)
        // SC: O(1)
        int n = nums.size();
        int idx = 0;
        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            nums[idx++] = nums[i];
        }
        return idx;
    }
};