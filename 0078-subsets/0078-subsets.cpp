class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        // backtracking
        // TC: O(2^n)
        // SC: O(2^n)
        vector<vector<int>> result;
        vector<int> subset;
        subsetHelper(nums, result, subset, 0);
        return result;
    }

    void subsetHelper(vector<int>& nums, vector<vector<int>>& result, vector<int> subset, int index) {
        if (index == nums.size()) {
            result.push_back(subset);
            return;
        }

        
        // choose
        subset.push_back(nums[index]);
        subsetHelper(nums, result, subset, index + 1);

        // not choose
        subset.pop_back();
        subsetHelper(nums, result, subset, index + 1);
    }
};