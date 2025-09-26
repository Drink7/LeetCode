class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // startn from index 0
        // loop
        // find meet index-> ans: number
        // TC: O(n)
        // SC: O(1)
        int slow = 0;
        int fast = 0;
        while (true) {
            slow = nums[slow];
            fast = nums[nums[fast]];
            if (slow == fast) {
                break;
            }
        }

        // find meet index
        slow = 0;
        while (nums[slow] != nums[fast]) {
            slow = nums[slow];
            fast = nums[fast];
        }
        return nums[slow];
    }
};