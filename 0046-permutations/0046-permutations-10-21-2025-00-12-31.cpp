class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        // use hash set to record used
        // TC: (n! * n)
        // SC: O(n)
        unordered_set<int> visited;
        vector<vector<int>> result;
        vector<int> path;
        dfs(result, nums, path, visited);
        return result;
    }

    void dfs(vector<vector<int>>& result, vector<int>& nums, vector<int> path, unordered_set<int>& visited) {
        if (path.size() == nums.size()) {
            result.push_back(path);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (visited.count(nums[i]) > 0) continue;
            visited.insert(nums[i]);
            path.push_back(nums[i]);
            dfs(result, nums, path, visited);
            path.pop_back();
            visited.erase(nums[i]);
        }
    }
};