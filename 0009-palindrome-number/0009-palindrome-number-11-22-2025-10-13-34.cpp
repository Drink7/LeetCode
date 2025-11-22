class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0 || (x != 0 && x % 10 == 0)) {
            return false;
        }

        int newX = 0;
        while (newX < x / 10) {
            newX = newX * 10;
            newX += x % 10;
            x = x / 10;
        }

        // odd or even
        return (x == newX) || (x / 10 == newX);
    }
};