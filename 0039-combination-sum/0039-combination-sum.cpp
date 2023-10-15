class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        // TC: O(2^n)
        // SC: O(2^n)
        vector<vector<int>> result;
        conbinationHelper(result, {}, 0, 0, candidates, target);
        return result;

    }

    void conbinationHelper(vector<vector<int>>& result, vector<int> combination, int start, int sum, vector<int>& candidates, int target) {
        if (sum > target) {
            return;
        }

        if (sum == target) {
            result.push_back(combination);
            return;
        }

        for (int i = start; i < candidates.size(); i++) {
            combination.push_back(candidates[i]); 
            conbinationHelper(result, combination, i, sum + candidates[i], candidates, target);
            combination.pop_back();
        }
    }
};