class Solution {
/*
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
*/
public:
    vector<int> getRow(int rowIndex) {
        // DP bottom up
        // TC: O(n^2)
        // SC: O(n)
        // Iteratively update from the end to the beginning
        vector<int> result(rowIndex + 1, 0);
        result[0] = 1;
        for (int i = 1; i < rowIndex + 1; i++) {
            for (int j = i; j >= 1; j--) {
                result[j] += result[j - 1];
            }
        }
        return result;
    }
};