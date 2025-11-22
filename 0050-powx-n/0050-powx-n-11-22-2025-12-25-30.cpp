class Solution {
public:
    double myPow(double x, int n) {
        // if n < 0
        // we should pu t the final number to the bottom
        // check is neg
        // long N = abs(n)
        // keep mutiplying
        // x ^ 2b = (x^2)b bit exponential
        // decrease the time complexity
        // if b is odd, ans = ans * x, then keep /2
        if (n < 0) {
            x = 1 / x;
        }

        long newN = n;
        if (n < 0) newN = -newN;
        double result = 1.0;
        while (newN) {
            if (newN % 2 != 0) {
                result = result * x;
            }
            x = x * x;
            newN = newN / 2;
        }
        return result;
    }
};