class Solution {
public:
    int divisorSubstrings(int num, int k) {
        // substring -> sliding window
        // k is the fixed size of this sliding window
        // TC: O(n)
        // SC: O(1)
        string numStr = to_string(num);
        int n = numStr.size();
        int result = 0;
        for (int i = 0; i < n - k + 1; i++) {
            int subNum = stoi(numStr.substr(i, k));
            if (subNum != 0 && num % subNum == 0) {
                result++;
            }
        }
        return result;
    }
};