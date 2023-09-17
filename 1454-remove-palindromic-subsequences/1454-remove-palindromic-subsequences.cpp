class Solution {
public:
    int removePalindromeSub(string s) {
        // subsequence don't need to be contiguos
        // we can directly remove all a or all b at a time
        // TC: O(n)
        // SC: O(1)
        if (isFullyPalindrome(s)) {
            return 1;
        } else {
            return 2;
        }
    }

    bool isFullyPalindrome(string s) {
        int left = 0;
        int right = s.size() - 1;
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