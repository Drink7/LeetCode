class Solution {
public:
    bool isAnagram(string s, string t) {
        // check size s == t
        // #1 sort, check equal?
        // #2 unordered_set, store s, check t, if char in t exist in set, char cnt - 1
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
    }
};