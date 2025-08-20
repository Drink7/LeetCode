class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // switch to the problem: detect cycle (duplicate index)
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
    
        fast = nums[0];
        while (fast != slow) {
            fast = nums[fast];
            slow = nums[slow];
        }
        return fast;
    }
};