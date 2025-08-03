class Solution {
public:
    bool isPalindrome(string s) {
        // tolower, isalnum
        // two pointer
        // TC: O(n)
        // SC: O(1)
        int left = 0;
        int right = s.size() - 1;
        while (left < right) {
            // make sure is alnum
            while (left < right && isalnum(s[left]) == 0) {
                left++;
            }

            while (left < right && isalnum(s[right]) == 0) {
                right--;
            }
            char leftChar = tolower(s[left]);
            char rightChar = tolower(s[right]);
            if (leftChar != rightChar) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};