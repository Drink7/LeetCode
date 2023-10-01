class Solution {
public:
    int countSubstrings(string s) {
        // similar to 5
        // but we count the palindrome here
        // TC: O(n^2)
        // SC: O(1)
        int count = 0;
        for (int i = 0; i < s.size(); i++) {
            // odd
            int left = i;
            int right = i;
            while (left >= 0 && right < s.size() && s[left] == s[right]) {
                count++;
                left--;
                right++;
            }

            //even
            left = i;
            right = i + 1;
            while (left >= 0 && right < s.size() && s[left] == s[right]) {
                count++;
                left--;
                right++;
            }
        }
        return count;
    }
};