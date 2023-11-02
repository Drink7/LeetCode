class Solution {
public:
    bool isAnagram(string s, string t) {
        // sort nd compare
        // TC: O(nlogn)
        // SC: O(1)
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
    }
};