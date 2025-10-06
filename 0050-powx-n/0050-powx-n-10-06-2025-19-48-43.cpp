class Solution {
public:
    double myPow(double x, int n) {
        /*
        // Brute Force --> TLE
        // TC: O(x^n)
        // SC: O(1)
        double result = 1.0;
        if (n > 0) {
            if (abs(x) == 1.0) {
                if (n % 2 == 0) {
                    return abs(x);
                } else {
                    return x;
                }
            } else {
                while (n > 0) {
                    result = result * x;
                    n--;
                }
            }
        } else if (n < 0) {
            if (abs(x) == 1.0) {
                if (n % 2 == 0) {
                    return abs(x);
                } else {
                    return x;
                }
            } else {
                // n > 0
                while (n > 0) {
                    result = result * x;
                    n--;
                }

                // or n < 0
                while (n < 0) {
                    result = result * x;
                    n++;
                }
                result = 1.0 / result;
            }
        }
        return result;
        */

        // more efficient way
        long long N = n;
        double ans = 1.0;
        if (N < 0) {
            x = 1 / x;
            N = -N;
        }
        while (N > 0) {
            if (N % 2 == 1) {
                ans *= x;
            }

            x *= x;

            N /= 2;
        }
        
        return ans;
    }
};