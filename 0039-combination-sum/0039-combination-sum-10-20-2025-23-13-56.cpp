class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        // backtracking
        vector<vector<int>> result;
        vector<int> path;
        dfs(result, path, candidates, target, 0);
        return result;
    }

    void dfs(vector<vector<int>>& result, vector<int> path, vector<int>& candidates, int target, int start) {
        if (target < 0) {
            return;
        }

        if (target == 0) {
            result.push_back(path);
            return;
        }

        for (int i = start; i < candidates.size(); i++) {
            path.push_back(candidates[i]);
            target -= candidates[i];
            dfs(result, path, candidates, target, i);
            target += candidates[i];
            path.pop_back();
        }
    }
};