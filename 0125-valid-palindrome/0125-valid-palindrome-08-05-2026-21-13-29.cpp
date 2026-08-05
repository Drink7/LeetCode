class Solution {
public:
    bool isPalindrome(string s) {
        // use two pointer to traverse (head. tail)
        // 1. check s[left] and s[right] are valid
        // 2. if valid, start checking
        // 3. tolower(s[left]) == tolower(s[right])?
        // 4. if false, early return false
        // 5. else, continue walking and verify the s[left] and s[right] are valid
        // 6. Back to 1.
        // TC: O(n)
        // SC: O(1)
        int left = 0, right = s.size() - 1;
        while (left < right) {
            while (left < right && !isalnum(s[left])) {
                left++;
            }

            while (left < right && !isalnum(s[right])) {
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