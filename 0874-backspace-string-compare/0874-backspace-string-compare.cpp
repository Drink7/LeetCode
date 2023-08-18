class Solution {
public:
    bool backspaceCompare(string s, string t) {
        /*
        // Brute Force
        // TC: O(n)
        // SC: O(n)
        return transformStr(s) == transformStr(t);
        */

        // Two Pointer
        // TC: O(n)
        // SC: O(1)
        int sPtr = s.size() - 1;
        int tPtr = t.size() - 1;
        while (sPtr >= 0 || tPtr >= 0) {
            char sChar = findChar(s, sPtr);
            char tChar = findChar(t, tPtr);
            if (sChar != tChar) {
                return false;
            }
            sPtr--;
            tPtr--;
        }
        return true;
    }

    char findChar(string& s, int& ptr) {
        int count = 0;
        while (ptr >= 0 && (count > 0 || s[ptr] == '#')) {
            if (s[ptr] == '#') {
                count++;
            } else {
                count--;
            }
            ptr--;
        }
        // if ptr < 0 and the count still > 0 or the s[ptr] is #
        // return '#'
        return (ptr >= 0) ? s[ptr] : '#';
    }

    // Brute Force
    /*
    string transformStr(string s) {
        string result = "";
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '#') {
                if (result != "") {
                    result.pop_back();
                }
            } else {
                result += s[i];
            }
        }
        return result;
    }
    */
};