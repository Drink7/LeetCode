class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        // distinct number, output unique combiniations
        // backtracking
        // TC: O(2^n)
        // SC: O(2^n)
        vector<vector<int>> result;
        vector<int> path;
        dfs(result, candidates, target, 0, path);
        return result;
    }

    void dfs(vector<vector<int>>& result, vector<int>& candidates, int target, int start, vector<int> path) {
        if (start >= candidates.size()) {
            return;
        }

        if (target == 0) {
            result.push_back(path);
            return;
        }

        if (target < 0) {
            return;
        }

        // target > 0
        for (int i = start; i < candidates.size(); i++) {
            path.push_back(candidates[i]);
            dfs(result, candidates, target - candidates[i], i, path);
            path.pop_back();
        }
    }
};