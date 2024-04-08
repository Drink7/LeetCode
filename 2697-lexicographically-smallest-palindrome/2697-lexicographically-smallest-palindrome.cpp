class Solution {
public:
    string makeSmallestPalindrome(string s) {
        // Palindrome -> two pointer
        // Make smallest lexicographically
        // TC: O(n)
        // SC: O(1)
        int left = 0;
        int right = s.size() - 1;
        while (left <= right) {
            if (s[left] < s[right]) {
                s[right] = s[left];
            } else {
                s[left] = s[right];
            }
            left++;
            right--;
        }
        return s;
    }
};