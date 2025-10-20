class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        // backtracking
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> result;
        vector<int> path;
        dfs(result, path, candidates, target, 0);
        return result;
    }

    void dfs(vector<vector<int>>& result, vector<int>& path, vector<int>& candidates, int target, int start) {
        if (target < 0) {
            return;
        }

        if (target == 0) {
            result.push_back(path);
            return;
        }

        for (int i = start; i < candidates.size(); i++) {
            if (i > start && candidates[i] == candidates[i - 1]) continue;

            path.push_back(candidates[i]);
            target -= candidates[i];
            dfs(result, path, candidates, target, i + 1);
            target += candidates[i];
            path.pop_back();
        }
    }
};