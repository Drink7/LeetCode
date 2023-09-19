class Solution {
public:
    int firstUniqChar(string s) {
        // hash
        // TC: O(n)
        // SC: O(1)
        vector<int> letterIndex(26, 0);
        for (int i = 0; i < s.size(); i++) {
            letterIndex[s[i] - 'a']++;
        }

        for (int i = 0; i < s.size(); i++) {
            if (letterIndex[s[i] - 'a'] == 1) {
                return i;
            }
        }
        return -1;
    }
};