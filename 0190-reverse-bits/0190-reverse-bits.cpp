class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        /*
        // shift left
        // TC: O(1)
        // SC: O(1)
        uint32_t reversed = 0;
        for (int i = 0; i < 32; i++) {
            reversed <<= 1;
            reversed = (reversed | (n & 1));
            n >>= 1;
        }
        return reversed;
        */

        // shift left
        // TC: O(1)
        // SC: O(1)
        uint32_t reversed = 0;
        for (int i = 1; i < 32; i++) {
            reversed = (reversed | (n & 1));
            reversed = reversed << 1;
            n = n >> 1;
        }
        reversed = (reversed | (n & 1));
        return reversed;
    }
};