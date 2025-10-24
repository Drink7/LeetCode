class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        //   1
        //  1 1
        // 1 2 1
        // 0 and n - 1 will be 1
        // i ~ n - 2 is prev row i - 1 + i
        // TC: O((1+n)*n/2 => n^2)
        // SC: O(1)
        vector<vector<int>> pascal(numRows);
        for (int i = 0; i < numRows; i++) {
            pascal[i].resize(i + 1, 1);
            for (int j = 1; j < i; j++) {
                pascal[i][j] = pascal[i - 1][j - 1] + pascal[i - 1][j];
            }
        }
        return pascal;
    }
};