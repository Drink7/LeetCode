class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        // pick strs[0] as base
        // compare with the 1....
        // use find to check if base is prefix of strs[1]
        // if not, substr hte base of length base - 1
        // TC: O(n * m), n is strs list length, m is average strs element size
        // SC: O(1)
        string base = strs[0];
        for (int i = 1; i < strs.size(); i++) {
            while (strs[i].find(base) != 0) {
                base = base.substr(0, base.size() - 1);
            }
        }
        return base;
    }
};