class Solution {
public:
    bool isAnagram(string s, string t) {
        // TC: O(nlogn)
        // SC: O(1)
        /*
        int sLen = s.size();
        int tLen = t.size();
        if (sLen != tLen) {
            return false;
        }
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        for (int i = 0; i < sLen; i++) {
            if (s[i] != t[i]) {
                return false;
            }
        }
        return true;
        */
        // TC: O(n)
        // SC: O(1)
        int dict[26] = {0};
        int sLen = s.size();
        int tLen = t.size();
        if (sLen != tLen) {
            return false;
        }

        for (int i = 0; i < sLen; i++) {
            dict[s[i] - 'a']++;
        }

        for (int i = 0; i < sLen; i++) {
            if (dict[t[i] - 'a'] == 0) {
                return false;
            }
            dict[t[i] - 'a']--;
        }
        return true;
    }
};