class Solution {
public:
    bool validPalindrome(string s) {
        // two pointer, and we can skip one character
        // TC: O(n)
        // SC: O(1)
        int left = 0;
        int right = s.size() - 1;
        while (left <= right) {
            if (s[left] != s[right]) {
                return checkValidPalindrome(s, left + 1, right) || checkValidPalindrome(s, left, right - 1);
            } else {
                left++;
                right--;
            }
        }
        return true;
    }

    bool checkValidPalindrome(string s, int left, int right) {
        int l = left;
        int r = right;
        while (left <= right) {
            if (s[left] != s[right]) {
                return false;
            } else {
                left++;
                right--;
            }
        }
        return true;
    }
};