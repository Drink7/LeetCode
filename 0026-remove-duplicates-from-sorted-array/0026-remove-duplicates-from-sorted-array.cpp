class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // Two pointer and traverse
        // TC: O(n)
        // SC: O(1)
        int n = nums.size();
        int curVal = nums[0];
        int count = 1;
        for (int i = 1; i < n; i++) {
            if (curVal != nums[i]) {
                nums[count++] = nums[i];
                curVal = nums[i];
            }
        }
        return count;
    }
};