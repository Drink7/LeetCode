class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // slow / fast
        // start from the first num
        // fast go two and slow go one
        int slow = nums[0];
        int fast = nums[0];
        while (true) {
            slow = nums[slow];
            fast = nums[nums[fast]];
            if (slow == fast) {
                break;
            }
        }
        
        // find cycle, find the cycle start
        slow = nums[0];
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};