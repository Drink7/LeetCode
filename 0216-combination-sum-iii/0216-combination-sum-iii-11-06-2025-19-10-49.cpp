class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        vector<int> path;
        dfs(result, path, 1, k, n);
        return result;
    }

    void dfs(vector<vector<int>>& result, vector<int> path, int start, int k, int n) {
        if (path.size() == k && n == 0) {
            result.push_back(path);
            return;
        }

        if (path.size() > k) {
            return;
        }

        if (n < 0) {
            return;
        }

        for (int i = start; i <= 9; i++) {
            path.push_back(i);
            n -= i;
            dfs(result, path, i + 1, k, n);
            n += i;
            path.pop_back();
        }
    }
};