class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        // use first string to represent common prefix
        // compare with others (use find)
        // if not common, pop string tail and compare
        // until common prefix
        // then compare with the next one
        // TC: O(m * n), m is strs count, n is average string length in strs
        // SC: O(n), n is verage string length in strs
        string commonPrefix = strs[0];
        int n = strs.size();
        for (int i = 1; i < n; i++) {
            while (strs[i].find(commonPrefix) != 0) {
                commonPrefix.pop_back();
            }
        }
        return commonPrefix;
    }
};