class Solution {
public:
    int bitwiseComplement(int n) {
        /*
        // use XOR to original num
        // TC: O(1)
        // SC: O(1)
        // exception handle first
        if (n == 0) {
            return 1;
        }

        // find leading one
        int totalBit = 0;
        int tmp = n;
        while (tmp) {
            tmp = tmp >> 1;
            totalBit++;
        }

        for (int i = 0; i < totalBit; i++) {
            n = n ^ (1 << i);
        }

        return n;
        */
        // Elegant
        // Elegant
        int mask = 1;
        while (mask < n) {
            mask = (mask << 1) | 1;
        }
        return mask ^ n;
    }
};