class Solution {
public:
    vector<int> grayCode(int n) {
        //gray code 
        // TC: O(2^n)
        // SC: O(1)
        vector<int> result;
        result.push_back(0);
        for (int i = 0; i < n; i++) {
            int size = result.size();
            for (int j = size - 1; j >= 0; j--) {
                result.push_back(result[j] | 1 << i);
            }
        }
        return result;
    }
};