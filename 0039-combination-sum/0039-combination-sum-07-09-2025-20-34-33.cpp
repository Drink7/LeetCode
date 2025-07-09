class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        // sort
        // backtracking
        // TC: O(2^n)
        // SC: (n)
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> result;
        vector<int> path;
        sumHelper(result, candidates, target, path, 0, 0);
        return result;
    }

    void sumHelper(vector<vector<int>>& result, vector<int>& candidates, int target, vector<int>& path, int pathSum, int start) {
        if (pathSum > target) {
            return;
        }
        if (pathSum == target) {
            result.push_back(path);
            return;
        }
        for (int i = start; i < candidates.size(); i++) {
            path.push_back(candidates[i]);
            pathSum += candidates[i];
            sumHelper(result, candidates, target, path, pathSum, i);
            pathSum -= candidates[i];
            path.pop_back();
        }
    }
};