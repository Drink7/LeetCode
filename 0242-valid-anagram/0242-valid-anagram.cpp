class Solution {
public:
    bool isAnagram(string s, string t) {
        // vector with 26 size
        // TC: O(m + n)
        // SC: O(1)
        vector<int> lettersCnt(26, 0);
        for (auto const& c : s) {
            lettersCnt[c - 'a']++;
        }

        for (auto const& c : t) {
            lettersCnt[c - 'a']--;
        }

        for (int i = 0; i < 26; i++) {
            if (lettersCnt[i] != 0) {
                return false;
            }
        }
        return true;
    }
};