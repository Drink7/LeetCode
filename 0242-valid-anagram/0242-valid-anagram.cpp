class Solution {
public:
    bool isAnagram(string s, string t) {
        // sort s & t
        // compare two string
        // TC: O(nlogn + mlogm)
        // SC: O(1)
        //sort(s.begin(), s.end());
        //sort(t.begin(), t.end());
        //return s == t;

        // store s to map
        // count t
        // TC: O(n + m)
        // SC: O(n)
        // traverse s
        if (s.size() != t.size()) {
            return false;
        }

        unordered_map<char, int> dict;
        for (auto const& c : s) {
            dict[c]++;
        }

        // traverse t
        for (auto const& c : t) {
            if (dict[c] == 0) {
                return false;
            }
            dict[c]--;
        }
        return true;
    }
};