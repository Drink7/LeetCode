class Solution {
public:
    int integerReplacement(int n) {
        // Recursion
        // TC: O(logn)
        // SC: O(1)
        //return replaceHelper(n);

        // Bit operation
        // if n end up with 01, use n - 1
        // if n end up with 11, use n + 1
        long bigN = n;
        int count = 0;
        while (bigN != 1) {
            if ((bigN & 1) == 0) {
                bigN = bigN >> 1;
            } else {
                if ((bigN & 2) == 0 || bigN == 3) {
                    bigN = bigN - 1;
                } else {
                    bigN = bigN + 1;
                }
            }
            count++;
        }
        return count;
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