class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        vector<int> queens;
        dfs(result, queens, n);
        return result;
    }

    void dfs(vector<vector<string>>& result, vector<int> queens, int n) {
        if (!check(queens, n)) {
            return;
        }

        if (queens.size() == n) {
            save(result, queens);
            return;
        }

        for (int i = 0; i < n; i++) {
            // choose
            queens.push_back(i);
            dfs(result, queens, n);

            // not choose
            queens.pop_back();
        }
    }

    bool check(vector<int> queens, int n) {
        if (queens.size() == 0) {
            return true;
        }

        int row = queens.size() - 1; // last row
        int col = queens.back(); // last col

        // check col
        for (int i = row - 1; i >= 0; i--) {
            if (queens[i] == col) {
                return false;
            }
        }

        // check left-top
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if (queens[i] == j) {
                return false;
            }
        }

        // check right-top
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
            if (queens[i] == j) {
                return false;
            }
        }

        return true;
    }

    void save(vector<vector<string>>& result, vector<int> queens) {
        int qSize = queens.size();
        vector<string> ans;
        for (int i = 0; i < qSize; i++) {
            string tmp = "";
            for (int j = 0; j < qSize; j++) {
                if (queens[i] != j) {
                    tmp += '.';
                } else {
                    tmp += 'Q';
                }
            }
            ans.push_back(tmp);
        }
        result.push_back(ans);
    }
};