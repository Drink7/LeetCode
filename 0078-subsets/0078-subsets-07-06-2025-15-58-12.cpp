class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        // TC: O(2^n)
        // SC: O(2^n)
        vector<vector<int>> result;
        vector<int> path;
        subsetsHelper(result, nums, path, 0);
        return result;
    }

    void subsetsHelper(vector<vector<int>>& result, vector<int>& nums, vector<int>& path, int index) {
        result.push_back(path);

        for (int i = index; i < nums.size(); i++) {
            if (index >= nums.size()) {
                break;
            }

            path.push_back(nums[i]);
            subsetsHelper(result, nums, path, i + 1);
            path.pop_back();
        }
    }
};