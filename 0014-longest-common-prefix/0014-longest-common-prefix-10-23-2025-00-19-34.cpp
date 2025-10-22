class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        // use the first string as prefix
        // traverse 2nd string, and keep pop back the prefix until str.find is 0
        // then keep traversing
        // TC: O(m * n), m is the size of strs, and n is the average size of string
        // SC: O(1)
        string prefix = strs[0];
        for (int i = 1; i < strs.size(); i++) {
            while (strs[i].find(prefix) != 0) {
                prefix.pop_back();
            }
        } 
        return prefix;
    }
};