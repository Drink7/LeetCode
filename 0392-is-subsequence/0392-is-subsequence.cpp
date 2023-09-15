class Solution {
public:
    bool isSubsequence(string s, string t) {
        // TC: O(n), n is t length
        // SC: O(1)
        int sId = 0;
        int tId = 0;
        while (tId < t.size()) {
            if (s[sId] == t[tId]) {
                sId++;
            }
            tId++;
        }
        return sId == s.size();
    }
};