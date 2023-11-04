class Solution {
public:
    bool isPalindrome(string s) {
        // two pointer
        // TC: O(n)
        // SC: O(1)
        int left = 0;
        int right = s.size() - 1;
        while (left < right) {
            // isalpha or isdigit
            while (left < right && !isalpha(s[left]) && !isdigit(s[left])) {
                left++;
            }

            while (left < right && !isalpha(s[right]) && !isdigit(s[right])) {
                right--;
            }

            if (tolower(s[left]) != tolower(s[right])) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};