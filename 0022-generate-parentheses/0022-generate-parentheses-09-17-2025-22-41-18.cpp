class Solution {
public:
    vector<string> generateParenthesis(int n) {
        // backtracking
        vector<string> result;
        dfs(n, n, result, "");
        return result;
    }

    void dfs(int left, int right, vector<string>& result, string path) {
        if (left == 0 && right == 0) {
            result.push_back(path);
            return;
        }

        if (left > 0) {
            dfs(left - 1, right, result, path + "(");
        }

        if (right > left) {
            dfs(left, right - 1, result, path + ")");
        }
    }
};