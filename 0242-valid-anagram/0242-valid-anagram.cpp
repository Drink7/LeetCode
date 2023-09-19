class Solution {
public:
    bool isAnagram(string s, string t) {
        /*
        // sort and compare
        // TC: O(nlogn)
        // SC: O(1)
        if (s.size() != t.size()) {
            return false;
        }

        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != t[i]) {
                return false;
            }
        }
        return true;
        */
        // Use hash map to check valid
        // store s to check t
        // TC: O(n)
        // SC: O(n)
        if (s.size() != t.size()) {
            return false;
        }

        unordered_map<char, int> letterCnt;
        for (auto const& c : s) {
            letterCnt[c]++;
        }

        for (auto const& c : t) {
            if (letterCnt[c] == 0) {
                return false;
            }
            letterCnt[c]--;
        }
        return true;
    }
};