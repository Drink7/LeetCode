class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        /*
        // strs[0] be the common prefix
        // check each strs
        // TC: O(m * n)
        // SC: O(1)
        string common = strs[0];
        for (int i = 1; i < strs.size(); i++) {
            int index = 0;
            string next = strs[i];
            for (int j = 0; j < next.size(), index < common.size(); j++, index++) {
                if (common[index] != next[j]) {
                    break;
                }
            }
            common = common.substr(0, index);
        }
        return common;
        */

        if (strs.size() == 0) {
            return "";
        }
        string base = strs[0];
        for (int i = 1; i < strs.size(); i++) {
            while (strs[i].find(base) != 0) {
                base.pop_back();
            }
        }
        return base;
    }
};