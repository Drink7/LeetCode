class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        // TC: O(m * n), m is the strs array length, n is the average size of string
        // SC: O(1)
        if (strs.size() == 0) {
            return "";
        }

        string base = strs[0];
        for (int i = 1; i < strs.size(); i++) {
            while (strs[i].find(base) != 0) {
                base = base.substr(0, base.size() - 1);
            }
        }
        return base;
    }
};