class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        // 1. sort
        // 2. candidates i +1 
        // TC: O(2^n)
        // SC: O(2^n)
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> result;
        combinationHelper(result, {}, 0, 0, candidates, target);
        return result;
    }

    void combinationHelper(vector<vector<int>>& result, vector<int> combination, int start, int sum, vector<int>& candidates, int target) {
        if (sum > target) {
            return;
        }

        if (sum == target) {
            result.push_back(combination);
            return;
        }

        for (int i = start; i < candidates.size(); i++) {
            // target = 8
            // candidates = 1, 2, 2, 5
            if (i > start && candidates[i - 1] == candidates[i]) {
                continue;
            }
            combination.push_back(candidates[i]);
            combinationHelper(result, combination, i + 1, sum + candidates[i], candidates, target);
            combination.pop_back();
        }
    }
};