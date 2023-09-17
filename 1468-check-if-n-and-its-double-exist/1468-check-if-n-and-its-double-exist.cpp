class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        // Brute Force
        // TC: O(n^2)
        // SC: O(1)
        for (int i = 0; i < arr.size(); i++) {
            for (int j = 0; j < arr.size(); j++) {
                if (i != j && arr[i] == arr[j] * 2) {
                    return true;
                }
            }
        }
        return false;
    }
};