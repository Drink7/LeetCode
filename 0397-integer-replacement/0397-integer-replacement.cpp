class Solution {
public:
    int integerReplacement(int n) {
        // Recursion
        // TC: O(logn)
        // SC: O(1)
        return replaceHelper(n);
    }

    int replaceHelper(long n) {
        if (n == 1) {
            return 0;
        }

        if (n % 2 == 0) {
            return replaceHelper(n / 2) + 1;
        } else {
            return min(replaceHelper(n + 1) + 1, replaceHelper(n - 1) + 1);
        }
    }
};