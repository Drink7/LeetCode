class Solution {
public:
    int integerReplacement(int n) {
        // TC: O(logn)
        // SC: O(logn)
        // Recursion
        if (n == 1) {
            return 0;
        }
        if (n % 2 == 0) {
            return 1 + integerReplacement(n / 2);
        } else {
            long t = n;
            return 1 + 1 + min(integerReplacement((t + 1) / 2), integerReplacement((t - 1) / 2));
        }
    }
};