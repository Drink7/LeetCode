class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // Two pointer
        // TC: O(n)
        // SC: O(1)
        int left = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[i - 1]) {
                nums[left] = nums[i];
                left++;
            }
        }
        return left;
    }
};