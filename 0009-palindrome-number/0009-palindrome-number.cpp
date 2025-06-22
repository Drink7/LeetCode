class Solution {
public:
    bool isPalindrome(int x) {
        // x is negative -> false
        // x is < 10 -> true
        // TC: O(n)
        // SC: O(1)
        if (x < 0 || x != 0 && x % 10 == 0) {
            return false;
        }

        int reversed = 0;
        while (x > reversed) {
            reversed = reversed * 10;
            reversed += x % 10;
            x /= 10;
        }
        return reversed == x || (x == reversed / 10);
    }
};