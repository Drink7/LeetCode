class Solution {
public:
    bool isAnagram(string s, string t) {
        // if s size != t size, must be false
        // #1 sort s and t, compare
        // #2 use hash map to store s, check t
        //sort(s.begin(), s.end());
        //sort(t.begin(), t.end());
        //return s == t;
        if (s.size() != t.size()) return false;
        unordered_map<char, int> dict;
        for (auto const& c : s) {
            dict[c]++;
        }

        for (auto const& c : t) {
            if (dict[c] == 0) {
                return false;
            }
            dict[c]--;
        }
        return true;
    }
};