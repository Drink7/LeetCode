class Solution {
public:
    bool isPalindrome(string s) {
        // if not alpha or digit, go with next letter
        // if yes, tolower and check left, right pointer
        // TC: O(n)
        // SC: O(1)
        int left = 0;
        int right = s.size() - 1;
        while (left < right) {
            while (left < right && !isalpha(s[left]) && !isdigit(s[left])) {
                left++;
            }

            while (left < right && !isalpha(s[right]) && !isdigit(s[right])) {
                right--;
            }

            // all to lowercase and check
            if (left > right || tolower(s[left]) != tolower(s[right])) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};