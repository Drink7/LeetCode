class Solution {
public:
    bool isPowerOfThree(int n) {
        // Brute Force
        // TC: O(log3)
        // SC: O(log3)
        long ans = 1;
        while (ans != n) {
            if (ans > n) {
                return false;
            }
            ans *= 3;
        }
        return true;
    }
};