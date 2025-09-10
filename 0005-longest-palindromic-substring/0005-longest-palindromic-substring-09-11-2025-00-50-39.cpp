class Solution {
public:
    string longestPalindrome(string s) {
        // start from each char
        // expand to each side
        // TC: O(n^2)
        // SC: O(1)
        int start = 0;
        int longest = 1;
        for (int i = 0; i < s.size(); i++) {
            // odd
            int left = i;
            int right = i;
            while (left >= 0 && right < s.size() && s[left] == s[right]) {
                if (right - left + 1 > longest) {
                    start = left;
                    longest = right - left + 1;
                }
                left--;
                right++;
            }

            // even
            left = i;
            right = i + 1;
            while (left >= 0 && right < s.size() && s[left] == s[right]) {
                if (right - left + 1 > longest) {
                    start = left;
                    longest = right - left + 1;
                }
                left--;
                right++;
            }
        }
        return s.substr(start, longest);
    }
};