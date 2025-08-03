class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        // backtracking
        // TC: O(2 ^ n)
        // SC: O(2 ^ n)
        sort(candidates.begin(), candidates.end());

        vector<vector<int>> result;
        vector<int> path;
        combineHelper(candidates, target, result, path, 0, 0);
        return result;
    }

    void combineHelper(vector<int>& candidates, int target, vector<vector<int>>& result, vector<int>& path, int pathSum, int index) {
        if (pathSum == target) {
            result.push_back(path);
            return;
        }

        if (pathSum > target) {
            return;
        }

        for (int i = index; i < candidates.size(); i++) {
            path.push_back(candidates[i]);
            pathSum += candidates[i];
            combineHelper(candidates, target, result, path, pathSum, i);
            pathSum -= candidates[i];
            path.pop_back();
        }
    }
};