class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        // backtracking
        vector<vector<int>> result;
        vector<int> path;
        combineHelper(result, candidates, 0, target, 0, path);
        return result;
    }

    void combineHelper(vector<vector<int>>& result, vector<int>& candidates, int start, int target, int sum, vector<int> path) {
        if (sum == target) {
            result.push_back(path);
            return;
        }

        if (sum > target) {
            return;
        }

        for (int i = start; i < candidates.size(); i++) {
            path.push_back(candidates[i]);
            combineHelper(result, candidates, i, target, sum + candidates[i], path);
            path.pop_back();
        }
    }
};