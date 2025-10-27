class Solution {
public:
    int reverse(int x) {
        // can not use long
        int result = 0;
        while (x) {
            if (result >= (INT_MAX / 10)) {
                if (result > (INT_MAX / 10)) {
                    return 0;
                }
                
                if (x % 10 > 7) {
                    return 0;
                }
            } else if (result <= (INT_MIN / 10)) {
                if (result < (INT_MIN / 10)) {
                    return 0;
                }

                if (x % 10 < -8) {
                    return 0;
                }
            }

            // valid
            result = result * 10;
            result += x % 10;
            x = x / 10;
        }

        return result;
    }
};