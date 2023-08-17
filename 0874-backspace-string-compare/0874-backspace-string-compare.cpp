class Solution {
public:
    bool backspaceCompare(string s, string t) {
        // Brute Force
        // TC: O(n^2)
        // SC: O(1)
        return transformStr(s) == transformStr(t);
    }

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
};