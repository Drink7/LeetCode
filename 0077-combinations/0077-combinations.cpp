class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        // TC: O(2^n)
        // SC: O(2^n)
        vector<vector<int>> result;
        vector<int> combination;
        combineHelper(result, combination, 1, n, k);
        return result;
    }

    void combineHelper(vector<vector<int>>& result, vector<int>& combination, int index, int n, int k) {
        if (combination.size() == k) {
            result.push_back(combination);
            return;
        }

        for (int i = index; i <= n; i++) {
            combination.push_back(i);
            combineHelper(result, combination, i + 1, n, k);
            combination.pop_back();
        }
    }
};