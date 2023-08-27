class Solution {
public:
    bool validPalindrome(string s) {
        // use two pointer
        // if there is one not match, check right - 1 and left + 1 cases
        // TC: O(n)
        // SC: O(1)
        int left = 0;
        int right = s.size() - 1;
        while (left <= right) {
            if (s[left] != s[right]) {
                return isPalindromeHelper(s, left + 1, right) ||
                        isPalindromeHelper(s, left, right - 1);
            } else {
                left++;
                right--;
            }
        }
        return true;
    }

    bool isPalindromeHelper(string s, int left, int right) {
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