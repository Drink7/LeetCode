class Solution {
public:
    int minFlipsMonoIncr(string s) {
        // dynamic programming
        // TC: O(n)
        // SC: O(1)
        int result = 0;
        int countOne = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '1') {
                countOne++;
            } else {
                result = min(countOne, result + 1);
            }
        }
        return result;
    }
};