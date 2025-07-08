class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        // TC: O(n^4)
        // SC: O(n^2)
        vector<vector<string>> result;
        vector<int> queen(n);
        solver(result, queen, 0, n);
        return result;
    }

    void solver(vector<vector<string>>& result, vector<int>& queen, int row, int n) {
        if (row == n) {
            result.push_back(transform(queen, n));
            return;
        }

        for (int i = 0; i < n; i++) {
            queen[row] = i;
            if (isValid(queen, row, i, n)) {
                solver(result, queen, row + 1, n);
            }
        }
    }

    bool isValid(vector<int> queen, int row, int col, int n) {
        int left = col - 1;
        int right = col + 1;
        for (int i = row - 1; i >= 0; i--) {

            // check col
            if (queen[i] == col) {
                return false;
            }

            // check diagnol
            if (left >= 0 && queen[i] == left) {
                return false;
            }

            if (right < n && queen[i] == right) {
                return false;
            }
            left--;
            right++;
        }
        return true;
    }

    vector<string> transform(vector<int>& queen, int n) {
        vector<string> result;
        for (int i = 0; i < n; i++) {
            string tmp = "";
            for (int j = 0; j < n; j++) {
                if (j == queen[i]) {
                    tmp += "Q";
                } else {
                    tmp += ".";
                }
            }
            result.push_back(tmp);
        }
        return result;
    }
};