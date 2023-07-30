class Solution {
public:
    bool isIsomorphic(string s, string t) {
        // Two hash table mapping
        // TC: O(n)
        // SC: O(n)
        if (s.size() != t.size()) {
            return false;
        }

        unordered_map<char, char> sDict, tDict;

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