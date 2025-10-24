class Solution {
public:
    bool isPowerOfTwo(int n) {
        /*
        // check % 2 == 0, each run will / 2
        // TC: O(logn)
        // SC: O(1)
        if (n <= 0) {
            return false;
        }

        while (n > 1) {
            if (n % 2 != 0) return false;
            n = n / 2;
        }
        return true;
        */
        // only singe one in bit 
        // TC: O(32)
        // SC: O(1)
        /*
        if (n <= 0) {
            return false;
        }

        int cnt = 0;
        while (n) {
            cnt++;
            n = n & (n - 1);
        }
        return cnt == 1;
        */

        return n > 0 && (n & (n - 1)) == 0;
    }
};