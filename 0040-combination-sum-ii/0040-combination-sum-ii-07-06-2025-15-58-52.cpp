class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        // sort
        // combination sum but ignore duplicate
        // TC: O(2^n)
        // SC: O(2^n)
        vector<vector<int>> result;
        vector<int> path;
        int pathSum = 0;
        sort(candidates.begin(), candidates.end());
        combinationSumHelper(result, candidates, path, pathSum, target, 0);
        return result;
    }

    void combinationSumHelper(vector<vector<int>>& result, vector<int>& candidates, vector<int>& path, int pathSum, int target, int index) {
        if (pathSum > target) {
            return;
        }

        if (pathSum == target) {
            result.push_back(path);
            return;
        }

        for (int i = index; i < candidates.size(); i++) {
            // prune
            if (i > index && candidates[i] == candidates[i - 1]) {
                continue;
            }

            pathSum += candidates[i];
            path.push_back(candidates[i]);

            combinationSumHelper(result, candidates, path, pathSum, target, i + 1);

            path.pop_back();
            pathSum -= candidates[i];
        }
    }
};