class Solution {
public:
    int reverse(int x) {
        // string reverse is OK
        // use % and /
        // check edged cases
        // handle big number
        // in C++, -123 % 10 = -3
        // TC: O(n)
        // SC: O(n)
        int result = 0;
        while (x) {
            if (result > INT_MAX / 10 || result < INT_MIN / 10) {
                return 0;
            }

            if ((result == INT_MAX / 10 && x % 10 > 7) ||
                (result == INT_MIN / 10 && x % 10 < -8)) {
                return 0;
            }
            result = result * 10;
            result += x % 10;
            x = x / 10;
        }
        return result;
    }
};