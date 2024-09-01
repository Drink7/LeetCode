class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        // TC: O(n)
        // SC: O(n)
        vector<vector<int>> result;
        if (original.size() % m == 0 && original.size() == m * n) {
            for (int i = 0; i < m; i++) {
                vector<int> sub_result;
                for (int j = 0; j < n; j++) {
                    sub_result.push_back(original[i * n + j]);
                }
                result.push_back(sub_result);
            }
        }
        return result;
    }
};