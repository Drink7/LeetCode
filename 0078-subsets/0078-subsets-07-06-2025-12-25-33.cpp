class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        // TC: O(2^n)
        // SC: O(2^n)
        vector<vector<int>> result;
        vector<int> sets;
        subsetsHelper(result, nums, sets, 0);
        return result;
    }

    void subsetsHelper(vector<vector<int>>& result, vector<int>& nums, vector<int> sets, int index) {
        if (index >= nums.size()) {
            result.push_back(sets);
            return;
        }

        // not choose nums[index]
        subsetsHelper(result, nums, sets, index + 1);

        // choose nums[index]
        sets.push_back(nums[index]);
        subsetsHelper(result, nums, sets, index + 1);
    }
};