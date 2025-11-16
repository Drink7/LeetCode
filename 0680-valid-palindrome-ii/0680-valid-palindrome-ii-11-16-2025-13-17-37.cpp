class Solution {
public:
    bool validPalindrome(string s) {
        // palindrom -> two pointers
        // check isalnum, then tolower
        // if not the same, delete left or right (left++ or right--) at most once
        // TC: O(n)
        // SC: O(1)
        int left = 0;
        int right = s.size() - 1;
        while (left < right) {
            if (s[left] != s[right]) {
                return isValidPalindrome(s, left, right - 1) ||
                    isValidPalindrome(s, left + 1, right);
            } else {
                left++;
                right--;
            }
        }
        return true;
    }

    bool isValidPalindrome(string s, int left, int right) {
        int l = left;
        int r = right;
        while (l < r) {
            if (s[l] != s[r]) return false;
            l++;
            r--;
        }
        return true;
    }
};