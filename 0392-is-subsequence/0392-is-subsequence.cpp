class Solution {
public:
    bool isSubsequence(string s, string t) {
        /*
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
        */

        // recursion
        // TC: O(n)
        // SC: O(n)
        int sLen = s.size();
        int tLen = s.size();
        return isSubseq(s, t, 0, 0);
    }

    bool isSubseq(string& s, string& t, int x, int y) {
        if (x == s.size()) {
            return true;
        }

        if (y == t.size()) {
            return false;
        }

        if (s[x] == t[y]) {
            return isSubseq(s, t, x + 1, y + 1);
        } else {
            return isSubseq(s, t, x, y + 1);
        }
    }
};