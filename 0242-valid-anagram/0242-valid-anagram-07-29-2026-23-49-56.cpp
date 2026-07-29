class Solution {
public:
    bool isAnagram(string s, string t) {
        /*
        // check size s == t
        // #1 sort, check equal?
        // #2 unordered_map, store s, check t, if char in t exist in set, char cnt - 1
        // if char cnt < 0, false
        // #1
        // TC: O(nlogn)
        // SC: O(1)
        if (s.size() != t.size()) {
            return false;
        }

        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
        */

        // unordered_map
        // TC: O(n)
        // SC: O(n)
        if (s.size() != t.size()) {
            return false;
        }

        unordered_map<char, int> dict_s;
        for (auto const& c : s) {
            dict_s[c]++;
        }

        for (auto const& c : t) {
            if (dict_s[c] > 0) {
                dict_s[c]--;
            } else {
                return false;
            }
        }
        return true;
    }
};