class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        // remove duplicate -> sort
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        vector<int> path;
        dfs(result, path, nums, 0);
        return result;
    }

    void dfs(vector<vector<int>>& result, vector<int> path, vector<int>& nums, int start) {
        result.push_back(path);

        for (int i = start; i < nums.size(); i++) {
            if (i > start && nums[i] == nums[i - 1]) continue;
            path.push_back(nums[i]);
            dfs(result, path, nums, i + 1);
            path.pop_back();
        }
    }
};