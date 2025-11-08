class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        //backtracking
        // 1 - n choose k
        // TC: O(2^n)
        // SC: O)2^n
        vector<vector<int>> result;
        vector<int> path;
        dfs(result, 1, n, k, path);
        return result;
    }

    void dfs(vector<vector<int>>& result, int start, int n, int k, vector<int>& path) {
        if (k == 0) {
            result.push_back(path);
            return;
        }
        for (int i = start; i <= n; i++) {
            path.push_back(i);
            dfs(result, i + 1, n, k - 1, path);
            path.pop_back();
        }
    }
};