class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        // Choose the first string as token
        // start from the second string and get the common prefix
        // until the last string
        // TC: O(m * n), m is average string length, n is string list number
        // SC: O(1)
        string base = strs[0];
        int n = strs.size();
        for (int i = 1; i < n; i++) {
            while (strs[i].find(base) != 0) {
                base = base.substr(0, base.size() - 1);
            }
        }
        return base;
    }
};