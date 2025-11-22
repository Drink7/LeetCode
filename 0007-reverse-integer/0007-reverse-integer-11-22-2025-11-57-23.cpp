class Solution {
public:
    int reverse(int x) {
        // newX
        // while (x), check newX INT_MAX, INT_MIN
        // newX >= INT_MAX / 10, newX * 10 >= INT_MAX
        // newX > INT_MAX / 10, return 0
        // newX  == INT_MAX / 10, check x % 10
        // if x % 10 > INT_MAX % 10, return 0
        // TC: O(logn)
        // SC: O(1)
        int newX = 0;
        while (x) {
            if (newX >= INT_MAX / 10 || newX <= INT_MIN / 10) {
                if (newX > INT_MAX / 10 || newX < INT_MIN / 10) return 0;
                if (newX == INT_MAX / 10 && x % 10 > INT_MAX % 10) return 0;
                if (newX == INT_MIN / 10 && x % 10 < INT_MIN % 10) return 0;
            }
            newX = newX * 10;
            newX += x % 10;
            x = x / 10;
        }
        return newX;
    }
};