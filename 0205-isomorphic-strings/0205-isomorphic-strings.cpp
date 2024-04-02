class Solution {
public:
    bool isIsomorphic(string s, string t) {
        // two hash table
        // TC: O(s + t)
        // SC: O(s + t)
        if (s.size() != t.size()) {
            return false;
        }
        unordered_map<char, char> sDict;
        unordered_map<char, char> tDict;
        for (int i = 0; i < s.size(); i++) {
            sDict[s[i]] = t[i];
            tDict[t[i]] = s[i];
        }

        for (int i = 0; i < s.size(); i++) {
            if (sDict[s[i]] != t[i] || tDict[t[i]] != s[i]) {
                return false;
            }
        }
        return true;
    }
};