class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        // back tracking
        // TC: O()
        vector<vector<int>> result;
        vector<int> sumList;
        sumHelper(candidates, target, result, sumList, 0, 0);
        return result;
        
    }

    void sumHelper(vector<int>& candidates, int target, vector<vector<int>>& result, vector<int>& sumList, int index, int sum) {
        if (sum == target) {
            result.push_back(sumList);
            return;
        }

        if (sum > target) {
            return;
        }

        for (int i = index; i < candidates.size(); i++) {
            sumList.push_back(candidates[i]);
            sumHelper(candidates, target, result, sumList, i, sum + candidates[i]);
            sumList.pop_back();
        }
    }
};