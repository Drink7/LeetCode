class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // can not use sort and extra array
        // Detect cycle / Find Cycle Start
        // TC: O(n)
        // SC: O(1)
        int fast = nums[0];
        int slow = nums[0];
        while (true) {
            fast = nums[nums[fast]];
            slow = nums[slow];
            if (fast == slow) {
                break;
            }
        }

        // found cycle, check cycle start
        slow = nums[0];
        while (fast != slow) {
            fast = nums[fast];
            slow = nums[slow];
            if (fast == slow) {
                break;
            }
        }
        return slow;
    }
};