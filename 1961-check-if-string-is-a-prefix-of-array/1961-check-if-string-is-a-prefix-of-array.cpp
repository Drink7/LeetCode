class Solution {
public:
    bool isPrefixString(string s, vector<string>& words) {
        /*
        // TC: O(max(m, n * k), m is s length, n is words length and k is average size of words
        // SC: O(1)
        int m = s.size();
        int index = 0;
        int prefixCnt = 0;
        for (int i = 0; i < words.size(); i++) {
            for (int j = 0; j < words[i].size(); j++) {
                prefixCnt++;
                if (index < m && s[index++] != words[i][j]) {
                    return false;
                }
            }
            if (index == m && index == prefixCnt) {
                return true;
            }
        }
        return false;
        */

        // more elegant
        // TC: O(max(m, n * k), m is s length, n is words length and k is average size of words
        // SC: O(1)
        int i = 0;
        for (int j = 0; j < words.size() && i < s.size(); j++) {
            for (auto const& ch : words[j]) {
                if (i == s.size() || s[i++] != ch) {
                    return false;
                }
            }
        }
        return i == s.size();
    }
};