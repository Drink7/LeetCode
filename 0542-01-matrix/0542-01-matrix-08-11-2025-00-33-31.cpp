class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        // multiple source bfs
        // find minimum dist to 0
        // TC: O(m * n)
        // SC: O(m * n)
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> result(m, vector<int>(n, 10001));
        queue<pair<int, int>> bfsQ;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 1) {
                    if (isSource(mat, i, j)) {
                        bfsQ.push({i, j});
                        result[i][j] = 1;
                    }
                } else {
                    result[i][j] = 0;
                }
            }
        }

        // bfs from multiple source
        while (bfsQ.size() > 0) {
            int qSize = bfsQ.size();
            for (int i = 0; i < qSize; i++) {
                auto cell = bfsQ.front();
                bfsQ.pop();

                int row = cell.first;
                int col = cell.second;
                for (int j = 0; j < 4; j++) {
                    int newRow = row + dRow[j];
                    int newCol = col + dCol[j];
                    if (newRow < 0 || newRow >= mat.size() || newCol < 0 || newCol >= mat[0].size() || mat[newRow][newCol] == 0) {
                        continue;
                    }
                    if (result[newRow][newCol] > result[row][col]) {
                        result[newRow][newCol] = 1 + result[row][col];
                        bfsQ.push({newRow, newCol});
                    }
                }
            }
        }
        return result;
    }

    bool isSource(vector<vector<int>>& mat, int row, int col) {
        bool isZeroValid = false;
        for (int i = 0; i < 4; i++) {
            int newRow = row + dRow[i];
            int newCol = col + dCol[i];
            if (newRow < 0 || newRow >= mat.size() || newCol < 0 || newCol >= mat[0].size()) {
                continue;
            }
            if (mat[newRow][newCol] == 0) {
                isZeroValid = true;
                break;
            }
        }
        return isZeroValid;
    }
private:
    int dRow[4] = {-1, 0, 1, 0};
    int dCol[4] = {0, -1, 0, 1};
};