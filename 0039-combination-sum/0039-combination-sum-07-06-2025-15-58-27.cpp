class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        // sort
        // choose and prune
        // TC: O(nlogn + 2^n)
        // SC: O(2^n)
        vector<vector<int>> result;
        vector<int> path;
        int pathSum = 0;
        sort(candidates.begin(), candidates.end());
        combinationHelper(result, candidates, path, pathSum, target, 0);
        return result;
    }

    void combinationHelper(
        vector<vector<int>>& result,
        vector<int>& candidates,
        vector<int>& path,
        int& pathSum,
        int& target,
        int index
    ) {
        if (pathSum > target) {
            return;
        }
        if (pathSum == target) {
            result.push_back(path);
            return;
        }

        for (int i = index; i < candidates.size(); i++) {
            path.push_back(candidates[i]);
            pathSum += candidates[i];
            combinationHelper(result, candidates, path, pathSum, target, i);

            // pop_back
            pathSum -= candidates[i];
            path.pop_back();
        }
    }
};