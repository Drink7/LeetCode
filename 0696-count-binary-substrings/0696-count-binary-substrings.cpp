class Solution {
public:
    int countBinarySubstrings(string s) {
        // palindrome, if found, goes left and right
        // 0 and 1 needed to be grouped together
        // start from 0, 1
        // TC: O(n^2)
        // SC: O(1)
        int start = 0;
        int n = s.size();
        int result = 0;
        while (start < n) {
            int left = start;
            int right = start + 1;
            int cnt[2] = {0, 0};
            while (left >= 0 && right < n) {
                cnt[s[left] - '0']++;
                cnt[s[right] - '0']++;
                if (cnt[0] == cnt[1]) {
                    result++;
                    if (left - 1 >= 0 && s[left - 1] != s[left]) {
                        break;
                    }
                    if (right + 1 < n && s[right + 1] != s[right]) {
                        break;
                    }
                    left--;
                    right++;
                } else {
                    break;
                }
            }
            start++;
        }
        return result;
    }
};