class Solution {
public:
    bool isSubsequence(string s, string t) {
        // TC: O(n)
        // SC: O(1)
        int sIndex = 0;
        int tIndex = 0;
        while (tIndex < t.size()) {
            if (s[sIndex] == t[tIndex]) {
                sIndex++;
            }
            tIndex++;
        }
        return sIndex == s.size();
    }
};