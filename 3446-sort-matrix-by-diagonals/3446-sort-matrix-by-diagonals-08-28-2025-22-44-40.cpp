class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        // bottom-left grid[i + j][j], j = 0, j < n - i
        // top-right grid[j][i+j+1]
        // sort and store back
        // TC: O(mlogm * nlogn)
        // SC: O(1)
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> result(m, vector<int>(n, 0));
        // bottom-left
        for (int i = 0; i < m; i++) {
            vector<int> tmp;
            for (int j = 0; j < n - i; j++) {
                tmp.push_back(grid[i + j][j]);
            }
            sort(tmp.begin(), tmp.end(), [](auto const& a, auto const& b){
                return a >= b;
            });

            int id = 0;
            for (int j = 0; j < n - i; j++) {
                result[i + j][j] = tmp[id++];
            }
        }

        // top-right
        for (int i = 1; i < n; i++) {
            vector<int> tmp;
            for (int j = 0; j < m - i; j++) {
                tmp.push_back(grid[j][i + j]);
            }
            sort(tmp.begin(), tmp.end());

            int id = 0;
            for (int j = 0; j < m - i; j++) {
                result[j][i + j] = tmp[id++];
            }
        }
        return result;
    }
};