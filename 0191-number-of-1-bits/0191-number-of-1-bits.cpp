class Solution {
public:
    int hammingWeight(uint32_t n) {
        /*
        // Bit operation 32 times
        // TC: O(1)
        // SC: O(1)
        int count = 0;
        for (int i = 0; i < 32; i++) {
            if (n & (1 << i)) {
                count++;
            }
        }
        return count;
        */

        // Follow up
        int count = 0;
        while (n) {
            n = n & (n - 1);
            count++;
        }
        return count;
    }
};