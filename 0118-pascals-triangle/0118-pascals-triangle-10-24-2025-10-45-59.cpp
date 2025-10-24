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
        if (numRows == 1) {
            return {{1}};
        }

        vector<vector<int>> pascal = {{1}, {1, 1}};
        for (int i = 2; i < numRows; i++) {
            vector<int> tmp;
            tmp.push_back(1);
            for (int j = 1; j < pascal[i - 1].size(); j++) {
                tmp.push_back(pascal[i - 1][j - 1] + pascal[i - 1][j]);
            }
            tmp.push_back(1);
            pascal.push_back(tmp);
        }
        return pascal;
    }
};