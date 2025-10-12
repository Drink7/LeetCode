class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        // brute force
        // dfs 
        // TC: O(2^n)
        // SC: O(2^n)
        dfs(nums, target, 0, 0);
        return result;
    }

    void dfs(vector<int>& nums, int target, int id, int sum) {
        if (id > nums.size()) {
            return;
        }

        if (id == nums.size()) {
            if (sum == target) {
                result++;
            }
            return;
        }

        // +1
        dfs(nums, target, id + 1, sum + nums[id]);

        // -1
        dfs(nums, target, id + 1, sum - nums[id]);
    }
private:
    int result = 0;
};