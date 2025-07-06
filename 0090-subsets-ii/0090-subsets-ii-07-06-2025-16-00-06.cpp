class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        // sort
        // ignore duplicate
        // TC: O(2^n)
        // SC: O(2^n)
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        vector<int> path;
        subsetsHelper(result, nums, path, 0);
        return result;
    }

    void subsetsHelper(vector<vector<int>>& result, vector<int>& nums, vector<int>& path, int start) {
        result.push_back(path);

        for (int i = start; i < nums.size(); i++) {
            if (i > start && nums[i] == nums[i - 1]) {
                continue;
            }

            path.push_back(nums[i]);
            subsetsHelper(result, nums, path, i + 1);

            path.pop_back();
        }
    }
};