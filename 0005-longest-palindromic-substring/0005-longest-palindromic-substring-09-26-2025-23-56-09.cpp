class Solution {
public:
    string longestPalindrome(string s) {
        // check with certral
        // check odd & even case
        // TC: O(n^2)
        // SC: O(1)
        int ansId = 0;
        int ansLen = 0;
        for (int i = 0; i < s.size(); i++) {
            // odd
            int left = i;
            int right = i;
            while (left >= 0 && right < s.size() && s[left] == s[right]) {
                if (right - left + 1 > ansLen) {
                    ansLen = right - left + 1 ;
                    ansId = left;
                }
                left--;
                right++;
            }

            // even
            left = i;
            right = i + 1;
            while (left >= 0 && right < s.size() && s[left] == s[right]) {
                if (right - left + 1 > ansLen) {
                    ansLen = right - left + 1 ;
                    ansId = left;
                }
                left--;
                right++;
            }
        }
        return s.substr(ansId, ansLen);
    }
};