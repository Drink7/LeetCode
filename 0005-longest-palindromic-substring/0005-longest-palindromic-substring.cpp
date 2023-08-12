class Solution {
public:
    string longestPalindrome(string s) {
        // Two pointer start from same position
        // Move left and right pointer backward
        // TC: O(n^2)
        // SC: O(1)
        int n = s.size();
        int left = 0;
        int right = 0;
        int maxLength = 0;
        string result = "";

        for (int i = 0; i < n; i++) {
            left = i;
            right = i;
            // Odd
            while (left >= 0 && right < n && s[left] == s[right]) {
                left--;
                right++;
            }
            if (right - left - 1 > maxLength) {
                maxLength = right - left - 1;
                result = s.substr(left + 1, right - left - 1);
            }

            // Even
            left = i;
            right = i + 1;
            while (left >= 0 && right < n && s[left] == s[right]) {
                left--;
                right++;
            }
            if (right - left - 1 > maxLength) {
                maxLength = right - left - 1;
                result = s.substr(left + 1, right - left - 1);
            }
        }
        return result;
    }
};