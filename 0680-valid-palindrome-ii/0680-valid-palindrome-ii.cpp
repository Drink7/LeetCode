class Solution {
public:
    bool validPalindrome(string s) {
        // two pointer
        // TC: O(n)
        // SC: O(1)
        int left = 0;
        int right = s.size() - 1;
        while (left < right) {
            if (s[left] != s[right]) {
                return validHelper(s, left + 1, right) || validHelper(s, left, right - 1);
            }
            left++;
            right--;
        }
        return true;
    }

    bool validHelper(string& s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right]) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};