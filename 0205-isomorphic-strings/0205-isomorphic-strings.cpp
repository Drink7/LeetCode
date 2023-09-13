class Solution {
public:
    bool isIsomorphic(string s, string t) {
        // two hash tables
        // TC: O(n)
        // SC: O(n)
        if (s.size() != t.size()) {
            return false;
        }

        unordered_map<char, char> sDict;
        unordered_map<char, char> tDict;
        for (int i = 0; i < s.size(); i++) {
            sDict[s[i]] = t[i];
            tDict[t[i]] = s[i];
        }

        for (int i = 0; i < t.size(); i++) {
            if (tDict[t[i]] != s[i] || sDict[s[i]] != t[i]) {
                return false;
            }
        }
        return true;
    }
};