class Solution {
public:
    int lengthOfLastWord(string s) {
        // traverse from back
        // ignore prefix space until first not space
        // traverse the not space until the space
        // return the length
        // TC: O(n)
        // SC: O(1)
        int cnt = 0;
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] == ' ') {
                if (cnt != 0) {
                    break;
                }
                continue;
            } else {
                cnt++;
            }
        }
        return cnt;
    }
};