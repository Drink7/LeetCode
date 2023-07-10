class Solution {
public:
    vector<int> getRow(int rowIndex) {
        // DP top down + memorization
        if (dict.count(rowIndex) < 1) {
            // calculate pascal's triangle
            vector<int> prev;
            vector<int> result(rowIndex + 1, 1);
            prev = getRow(rowIndex - 1);
            for (int i = 1; i < result.size() - 1; i++) {
                result[i] = prev[i - 1] + prev[i];
            }
            dict[rowIndex] = result;
        }
        return dict[rowIndex];
    }
private:
    unordered_map<int, vector<int>> dict = {{0, {1}}, {1, {1, 1}}};
};