class Solution {
public:
    string longestPalindrome(string s) {
        // expand from middle
        // odd even
        // TC: O(n^2)
        // SC: O(1)
        int n = s.size();
        int cur = 0;
        int start = 0;
        int length = 0;
        while (cur < n) {
            // odd
            int left = cur;
            int right = cur;
            while (left >= 0 && right < n && s[left] == s[right]) {
                if (right - left + 1 > length) {
                    start = left;
                    length = right - left + 1;
                }

                left--;
                right++;
            }

            // even
            left = cur;
            right = cur + 1;
            while (left >= 0 && right < n && s[left] == s[right]) {
                if (right - left + 1 > length) {
                    start = left;
                    length = right - left + 1;
                }

                left--;
                right++;
            }
            cur++;
        }
        return s.substr(start, length);
    }
};