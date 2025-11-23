class Solution {
public:
    bool canJump(vector<int>& nums) {
        // record the maximum jump
        // if maximum jump >= last index, return true
        // else false
        // TC: O(n)
        // SC: O(1)
        int maxJump = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            if (i <= maxJump) {
                maxJump = max(maxJump, i + nums[i]);
            }
        }
        return maxJump >= nums.size() - 1;
    }
};