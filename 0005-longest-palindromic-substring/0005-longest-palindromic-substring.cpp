class Solution {
public:
    string longestPalindrome(string s) {
        // longest palindrome
        // start from each letter, and expand left, right side to find longest length
        // odd case and even case
        // TC: O(n^2)
        // SC: O(1)
        int longestLen = 0;
        int longestLenStart = 0;
        string result = "";
        for (int i = 0; i < s.size(); i++) {
            // odd case 0 1 2
            int left = i;
            int right = i;
            while (left >= 0 && right < s.size() && s[left] == s[right]) {
                left--;
                right++;
            }
            
            if (right - left + 1 - 2 > longestLen) {
                longestLen = right - left + 1 - 2;
                longestLenStart = left + 1;
            }

            // even case 0 1 2 3
            left = i;
            right = i + 1;
            while (left >= 0 && right < s.size() && s[left] == s[right]) {
                left--;
                right++;
            }

            if (right - left + 1 - 2 > longestLen) {
                longestLen = right - left + 1 - 2;
                longestLenStart = left + 1;
            }
        }

        result = s.substr(longestLenStart, longestLen);
        return result;
    }
};