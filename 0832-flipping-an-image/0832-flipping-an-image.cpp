class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        /*
        // Reverse horizontally
        // Invert each element
        // TC: O(n^2)
        // SC: O(1)
        vector<vector<int>> result;
        int n = image.size();
        for (auto const& row : image) {
            vector<int> newRow;
            int right = n - 1;
            while (right >= 0) {
                newRow.push_back(row[right] == 1 ? 0 : 1);
                right--;
            }
            result.push_back(newRow);
        }
        return result;
        */
        // More elegant
        // TC: O(n^2)
        // SC: O(1)
        for (auto& row : image) {
            reverse(row.begin(), row.end());
            for (auto& v : row) {
                v ^= 1;
            }
        }
        return image;
    }
};