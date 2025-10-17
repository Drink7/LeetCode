class Solution {
public:
    double myPow(double x, int n) {
        // 2^10, 2.1^3, 2^(-3)
        // 4^5, 2.1*2.1^2, (1/2)^3
        // result = result * x;
        // x = x * x
        // n = n / 2;
        // TC: O(logn)
        // SC: O(1)
        double result = 1.0;
        long N = n;
        if (N < 0) {
            x = 1 / x;
            N = -N;
        }
        while (N) {
            if (N % 2 == 1) {
                result = result * x;
            }
            N = N / 2;
            x = x * x;
        }
        return result;
        // x = 256 * 256, n = 0
        // result = 1048
    }
};