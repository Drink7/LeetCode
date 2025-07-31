class Solution {
public:
    int reverse(int x) {
        // reverse and also check INT_MIN INT_MAX
        // positive or negative
        // TC: O(32)
        // SC: O(1)
        int result = 0;
        while (x) {
            // check range
            if (result > INT_MAX / 10 || result < INT_MIN / 10) {
                return 0;
            }

            if (result == INT_MAX / 10) {
                if (x % 10 > INT_MAX % 10) {
                    return 0;
                }
            }

            if (result == INT_MIN / 10) {
                if (x % 10 < INT_MIN % 10) {
                    return 0;
                }
            }

            result = result * 10 + x % 10;
            x = x / 10;
        }
        return result;
    }
};